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
#define fi first
#define se second
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 10005

int n , F[N] , L[N] , M[N][20];
vi adj[N] , cost[N];
bool vis[N];
ll C[N];

void dfs( int u , int lvl , int f , ll costo ){
    L[ u ] = lvl;
    F[ u ] = f;
    C[ u ] = costo;
    vis[u] = 1;
    for(int i = 0 ; i < adj[ u ].size() ; i++)if( adj[u][i] != f and !vis[ adj[u][i] ] )
        dfs( adj[ u ][i] , lvl + 1 , u  , costo + cost[u][i] );
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

int f(int u,int d){
    for(int i = 20 ; i >= 0 ; i--){
        if( M[u][i] != -1 and (1<<i) <= d ){
            u = M[u][i];
            d -= (1<<i);
        }
    }
    return u;
}

int main(){
    int tc , a , b , c;
    sc(tc);
    while(tc--){
        sc(n);
        for(int i = 0 ; i < n + 5 ; i++)
            adj[i].clear() , cost[i].clear();
        me(vis,0);
        for(int i = 0 ; i < n - 1 ; i++){
            scanf("%d%d%d",&a,&b,&c); a--,b--;
            adj[a].pb(b); cost[a].pb(c);
            adj[b].pb(a); cost[b].pb(c);
        }
        me(F,-1);
        dfs( 0 , 0 , -1 , 0 );
        
        init();
        char s[10];
        while( scanf("%s",s) ){
            if( s[1] == 'O' ) break;
            scanf("%d%d",&a,&b); a--,b--;
            if( s[0] == 'D' ){
                int lca = query( a , b );
                printf("%lld\n", C[a] + C[b] - 2 * C[lca] );
            }
            else{
                scanf("%d",&c); c--;
                //cout << a << " " << b << " " << c << endl;
                int lca = query( a , b );
                int ans;
                if( L[a] - L[lca] >= c )
                    ans = f( a , c );
                else{
                    ans = f( b , (L[b] - L[lca]) - (c - (L[a] - L[lca])) );
                    //cout << ": " << (L[c] - L[lca]) - (c - (L[a] - L[lca])) << endl;
                }
                printf("%d\n",ans+1);
            }
        }
        printf("\n");
    }
    return 0;
}
