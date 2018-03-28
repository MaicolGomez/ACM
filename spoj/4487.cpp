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
#define inf 2000000007
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
	int x, y, cnt , S , SL , SR , best;
	bool rev;
	pnode L, R;
	node() {}
	node(int X, int Y){ x = X, y = Y, cnt = 1 , S = X , SL = X , SR = X , best = X , L = NULL , R = NULL; }
};

inline int cnt(pnode &it){
	return it ? it->cnt : 0;
}

inline int SL(pnode &it){
	return it ? it->SL : -inf;
}

inline int SR(pnode &it){
	return it ? it->SR : -inf;
}

inline int best(pnode &it){
	return it ? it->best : -inf;
}

inline int S(pnode &it){
	return it ? it->S : 0;
}


inline void upd_cnt(pnode &it){
	if(it){
		it->cnt = cnt(it->L) + cnt(it->R) + 1;
		it->S = S(it->L) + S(it->R) + it->x;
		int p = max( 0 , SL(it->R) ) , q = max( 0 , SR(it->L) );
		it->SL = max( SL(it->L) , S(it->L) + it->x + p );
		it->SR = max( SR(it->R) , q + it->x + S(it->R) );
        it->best = max( it->x + p + q , max( best(it->L) , best(it->R) ) );
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

void update(pnode &t,int value,int pos){
    if( t ){
        int cL = cnt(t->L);
        if( pos < cL ) update( t->L , value , pos );
        else if( cL == pos ) t->x = value ;//, t->S = value , t->best = value , t->SL = value , t->SR = value;
        else  update( t->R , value , pos - cL - 1 );
        
        upd_cnt(t);
    }
}

void erase(pnode &t,int pos){
    if( t ){
        int cL = cnt(t->L);
        if( pos < cL ) erase( t->L , pos );
        else if( cL == pos ) merge( t , t->L , t->R );
        else erase( t->R , pos - cL - 1 );
        upd_cnt(t);
    }
}

pnode query(pnode &t,int a,int b){
    int cL = cnt(t->L);
    if( b < cL ) return query( t->L , a , b );
    else if( cL + 1 <= a ) return query( t->R , a - cL - 1 , b - cL - 1 );
    else{
        if( b - a  + 1 == cnt(t) ) return t;
        pnode L = (a < cL ? query( t->L , a , cL - 1 ) : NULL );
        pnode R = (cL + 1 <= b ? query( t->R , 0 , b - cL - 1 ) : NULL );
        pnode ans = new node( t->x , 0 );
        ans->L = L;
        ans->R = R;
        upd_cnt(ans);
        return ans;
    }
}

pnode T;

void print(pnode t){
    if( t ){
        print(t->L);
        printf("%d ",t->x);
        print(t->R);
    }
}

#define MAXN 100000
int x[MAXN], y[MAXN], find_L[MAXN], find_R[MAXN], SS[MAXN], sz;
pnode v[MAXN];
 
bool visited[MAXN];
 
void fix(pnode t){
    if(t){
        fix(t->L);
        fix(t->R);
        upd_cnt(t);
    }
}
 
void build_treap(int n)
{
    sz = 0;
    for(int i=0; i<n; i++)
    {
        while(sz && y[SS[sz-1]] < y[i]) sz--;
        find_L[i] = (sz == 0 ? -1 : SS[sz-1]);
        SS[sz++] = i;
    }
   
    sz = 0;
    for(int i=n-1; i>=0; i--)
    {
        while(sz && y[SS[sz-1]] < y[i]) sz--;
        find_R[i] = (sz == 0 ? -1 : SS[sz-1]);
        SS[sz++] = i;
    }
 
    for(int i=0; i<n; i++)
        v[i] = new node(x[i], y[i]);
   
    int root = -1;
    for(int i=0; i<n; i++)
    {
        int j = i;
        while(!visited[j])
        {
            visited[j] = 1;
           
            int pL = find_L[j], pR = find_R[j], p;
           
            if(pL == -1 && pR == -1) root = j;
            else
            {
                if(pL == -1) p = pR;
                else if(pR == -1) p = pL;
                else p = (y[pL] < y[pR] ? pL : pR);
           
                if(p < j) v[p]->R = v[j];
                else v[p]->L = v[j];
                j = p;
            }
        }
    }
    T = v[root];
    fix(T);
}

int main(){
    T = NULL;
    int n ;
    sc(n);
    for(int i = 0 ; i < n ; i++){
        sc(x[i]);
        y[i] = rand();
        //merge( T , T , new node( x , rand() ) );
    }
    build_treap( n );
    int q;
    sc(q);
    char type[5];
    int a , b;
    pnode L , R;
    while( q-- ){
        scanf("%s",type);
        if( type[0] == 'I' ){
            scanf("%d%d",&a,&b); a --;
            split( T , L , R , a );
            merge( L , L , new node( b , rand() ) );
            merge( T , L , R );
        }
        else if( type[0] == 'D' ){
            scanf("%d",&a); a--;
            //erase( T , a );
            pnode L , R;
            split( T , T , L , a );
            split( L , L , R , 1 );
            merge( T , T , R );
        }
        else if(type[0] == 'R'){
            scanf("%d%d",&a,&b); a--;
            update( T , b , a );
            /*pnode L , R;
            split( T , T , L , a );
            split( L , L , R , 1 );
            merge( T , T , new node( b , rand() ) );
            merge( T , T , R );*/
        }
        else{
            scanf("%d%d",&a,&b);
            printf("%d\n", query( T , a - 1 , b - 1 )->best );
            /*pnode L , R;
            split( T , T , L , a );
            split( L , L , R , b - a + 1 );
            printf("%d\n",best(L));
            merge( L , L , R );
            merge( T , T , L );*/
        }
    }
    
    return 0;
}
