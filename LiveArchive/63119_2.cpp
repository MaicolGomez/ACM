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
#define N 1000005


typedef struct node * pnode;

struct node{
	int y, cnt;
	char x;
	//bool rev;
	pnode L, R;
	node() {}
	node(char x, int y): x(x), y(y), cnt(1), L(NULL), R(NULL) {}
};


inline int cnt(pnode &it){
	return it ? it->cnt : 0;
}

inline void upd_cnt(pnode &it){
	if(it){
		it->cnt = cnt(it->L) + cnt(it->R) + 1;
	}
}

// Lazy propagation
void push(pnode it){
	if (it && it->rev){
		it->rev = false;
		swap(it->L, it->R);
		if (it->L) it->L->rev ^= true;
		if (it->R) it->R->rev ^= true;
	}
}

// Split Treap
void split(pnode t, int x, pnode &L, pnode &R){
	if (!t) L = R = NULL;
	else{
		//push(t);
		if (x < t->x)
			split (t->L, x, L, t->L), R = t;
		else
			split (t->R, x, t->R, R), L = t;
		upd_cnt(t);
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
void insert(pnode &t, char value, int pos){
	pnode t1, t2;
	split(t, t1, t2, pos);
	merge(t1, t1, new node(value, rand()));
	merge(t, t1, t2);
}

// Reverse implicit Treap
void reverse(pnode &t, int l, int r){
	pnode t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r-l +1);
	t2->rev ^= true;
	merge(t, t1, t2);
	merge(t, t, t3);
}

char s[N];
pnode T;

pnode get(){
    pnode x;
    int n = strlen(s);
    for(int i = 0 ; i < n ; i++)
        insert( T , s[i] , i );
}

void print(pnode t){
    if( t ){
        print( t->L );
        printf("%c",t->x);
        print( t->R );
    }
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        scanf("%s",s);
        T = get();
        print(T);
        char type[5];
        while( scanf("%s",type) == 1 ){
            if( type[0] == 'E' ) break;
            else if( type[0] == 'I' ){
                int pos;
                scanf("%s%d",s,&pos);
            }
            else{
                scanf("%d%d",&a,&b);
            }
        }
    }
    
    return 0;
}
