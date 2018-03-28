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
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf (1<<30)
#define eps 1e-8
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mk(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define N 10005

vector<int> adj[N];
int n;
int L[ N ] , F[ N ];
int M[  N ][ 20 ];

void dfs( int u , int lvl , int f ){
    L[ u ] = lvl;
    F[ u ] = f;
    for(int i = 0 ; i < adj[ u ].size() ; i++)if( adj[u][i] != f ){
        dfs( adj[ u ][i] , lvl + 1 , u );
    }
}

void init(){
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; (1<<j) < n ; j++)
            M[i][j] = -1;
    
    for(int i = 0 ; i < n ; i++)
        M[i][0] = F[i];
    
    for(int j = 1 ; (1<<j) < n ; j++)
        for(int i = 0 ; i < n ; i++)
            if( M[i][j-1] != -1 )
                M[i][j] = M[ M[i][j-1] ][j-1];
}

int query(int p,int q){
    if( L[p] < L[q] )
        swap( p , q );
    
    int log = 1;
    for(log = 1 ; 1<<log <= L[p] ; log++);
    log--; 
    
    for(int i = log ; i >= 0 ; i--)
        if( L[p] - (1<<i) >= L[q] )
            p = M[p][i];
    
    if( p == q ) return p;
    
    for(int i = log ; i >= 0 ; i--)
        if( M[p][i] != -1 && M[p][i] != M[q][i] )
            p = M[p][i] , q = M[q][i];
    
    return F[p];
}

int main(){
    int tc , s , t;
    scanf("%d",&tc);
    while( tc-- ){
        sc(n);
        for(int i = 0 ; i < n ; i++) adj[i].clear();
        for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < 20 ; j++) M[i][j] = inf;
        for(int i = 0 ; i < n - 1 ; i++){
            scanf("%d%d",&s,&t);
            adj[t].pb(s);
        }
        dfs( 0 , 0 , -1 );
        init();
        int q;
        scanf("%d",&q);
        for(int i = 0 ; i < q ; i++){
            scanf("%d%d",&s,&t);
            if(s == t) printf("No\n");
            else{
                int r = query( s , t );
                if( s == r ) printf("Yes\n");
                else printf("No\n");
            }
        }
        printf("\n");
    }
}
