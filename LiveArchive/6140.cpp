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
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 100005

int n , L[N] , F[N] , cycle[N] , c , tc[N] , lugar[N] , C[N];
bool vis[N];
vi adj[N];

int A[N] , R[N];

void dfs(int u,int lvl,int fa,int comp,int arbol){
    vis[u] = 1;
    L[u] = lvl;
    F[u] = fa;
    C[u] = comp;
    A[u] = arbol;
    for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
        int v = adj[u][i];
        if( cycle[v] == -1 and !vis[v] )
            dfs( v , lvl + 1 , u , comp , arbol );
    }
}

int M[N][20];

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

int pa[N];

int FIND(int x){
    return (pa[x] == x)?x:(pa[x] = FIND(pa[x]));
}

void UNION(int x,int y){
    pa[FIND(x)] = FIND(y);
}

int main(){
    while( sc(n) == 1 ){
        for(int i = 0 ; i < n + 2 ; i++)
            adj[i].clear() , pa[i] = i;
            
        int x;
        me(vis,0);
        me(cycle,-1);
        me(lugar,-1);
        c = 0;
        for(int i = 0 ; i < n ; i++){
            sc(x); x--;
            if( FIND(i) == FIND(x) ){
                int k = x , r = 0;
                F[ i ] = x;
                while( 1 ){
                    if( vis[k] ) break;
                    cycle[k] = c; lugar[k] = r++;
                    vis[k] = 1;
                    k = F[k];
                }
                tc[c] = r;
                c++;
            }
            UNION( i , x );
            F[ i ] = x;
            adj[ x ].pb( i ); adj[ x ].pb( i );
        } 
        me( vis , 0 );
        me( F , -1 );
        me( A , -1 );
        int arbol = 0;
        for(int i = 0 ; i < n ; i++)if( cycle[i] >= 0 ){
            R[arbol] = i , dfs( i , 0 , -1 , cycle[i] , arbol++ );
        }
        init();
            
        int q , a , b;
        sc(q);
        while( q-- ){
            scanf("%d%d",&a,&b); a--,b--;
            if( C[a] != C[b] ) printf("-1\n");
            else{
                if( A[a] == A[b] )
                    printf("%d\n", L[a] + L[b] - 2 * L[ query( a , b ) ] );
                else{
                    int r = R[ A[a] ] , s = R[ A[b] ];
                    int ans = min( abs( lugar[s] - lugar[r] ) , tc[ cycle[r] ] - abs( lugar[s] - lugar[r] ) ) + L[a] + L[b];
                    printf("%d\n",ans);
                }
            }
        }  
    }
    return 0;
}
