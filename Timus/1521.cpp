#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<deque>
#include<queue>
#include<map>
#include<climits>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf (1<<29)
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 100001

typedef struct node * pnode;

struct node{
	int x, y, cnt;
	pnode L, R;
	node() {}
	node(int X, int Y){ x = X , y = Y , cnt = 1, L = NULL, R = NULL; }
};

pnode T;

inline int cnt(pnode &it){
	return it ? it->cnt : 0;
}

inline void upd_cnt(pnode &it){
	if(it){
		it->cnt = cnt(it->L) + cnt(it->R) + 1;
	}
}

// Split Implicit Treap
void split(pnode t, pnode &L, pnode &R, int key){
	if (!t) L = R = NULL;
	else{
		//push(t);
		int cntL = cnt(t->L);
		if (key <= cntL)
			split (t->L, L, t->L, key), R = t;
		else
			split (t->R, t->R, R, key - cntL - 1), L = t;
		upd_cnt(t);
	}
}

// For Treap & Implicit Treap
void merge(pnode &t, pnode L, pnode R){
	//push(L);
	//push(R);
	if (!L) t = R;
	else if(!R) t = L;
	else if (L->y > R->y)
		merge (L->R, L->R, R), t = L;
	else
		merge (R->L, L, R->L), t = R;
	upd_cnt(t);
}

// Insert into implicit Treap
void insert(pnode &t, int value, int pos){
	pnode t1, t2;
	split(t, t1, t2, pos);
	merge(t1, t1, new node(value, rand()));
	merge(t, t1, t2);
}

int find(pnode t,int pos){
    int ct = cnt(t->L);
    if( pos < ct ) return find( t->L , pos );
    else if( pos == ct ) return t->x;
    else return find( t->R , pos - ct - 1 );
}

void print(pnode &t){
    if(t){
        print(t->L);
        printf("%d ",t->x);
        print(t->R);
    }
}

int main(){
    T = NULL;
    int n , k;
    scanf("%d%d",&n,&k);
    for(int i = 1 ; i < n + 1 ; i++)
        merge( T , T , new node( i , rand() ) );

    int pos = 0 , s , t;
    pnode L , R;
    for(int i = 0 ; i < n ; i++){
        s = k;
        //cout << pos << " ** ";
        t = cnt(T);
        if( pos + s - 1 >= t ){
            s -= t + 1 - pos;
            pos = 0;
            if( s >= t ) s %= t;
            pos += s;
        }
        else pos += s - 1;
        //cout << pos << endl;
        printf("%d ", find( T , pos ) );
        split( T , T , L , pos );
        split( L , L , R , 1 );
        merge( T , T , R );
        //print(T);
        //printf("\n");
    }
    printf("\n");
}
