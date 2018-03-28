#include<bits/stdc++.h>
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
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 500001

bool vis[N];
vi adj[N];
int L[N] , F[N] , n , D;

int bfs(int source){
    vi d( n , -1 );
    queue<int> Q;
    Q.push( source );
    d[source] = 0;
    int s;
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        s = u;
        for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
            int v = adj[u][i];
            if( d[v] == -1 ){
                Q.push( v );
                d[v] = d[u] + 1;
                D = max( D , d[v] );
            }
        }
    }
    return s;
}

void dfs( int u , int lvl , int f ){
    L[ u ] = lvl;
    F[ u ] = f;
    for(int i = 0 ; i < adj[ u ].size() ; i++)if( adj[u][i] != f )
        dfs( adj[ u ][i] , lvl + 1 , u );
    
}

int M[N][25];

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

int lca(int p,int q){
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

int dist(int x,int y){
    int r = lca( x , y );
    return L[x] + L[y] - 2 * L[r];
}

int A[N] , B[N];
ll C[N];

int main(){
    int nn , q , x , y;
    while( scanf("%d%d",&nn,&q) == 2 ){
        D = 0;
        for(int i = 0 ; i < nn ; i++)
            adj[i].clear();
        for(int i = 0 ; i < nn - 1 ; i++){
            scanf("%d%d",&x,&y); x--,y--;
            adj[x].pb( y );
            adj[y].pb( x );
        }
        n = nn;
        int a = bfs( 0 );
        int b = bfs( a );
        me(vis,0);
        dfs( 0 , 0 , -1 );
        init();
        double S1 = 0 , S2 = 0;
        for(int i = 0 ; i < n ; i++){
            A[i] = max( dist( i , a ) ,  dist( i , b ) );
            S1 += A[i];
        }
        
        for(int i = 0 ; i < q ; i++)
            adj[i].clear();
        
        for(int i = 0 ; i < q - 1 ; i++){
            scanf("%d%d",&x,&y); x--,y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        
        n = q;
        a = bfs( 0 );
        b = bfs( a );
        me(vis,0);
        dfs( 0 , 0 , -1 );
        init();
        for(int i = 0 ; i < q ; i++){
            B[i] = max( dist( i , a ) ,  dist( i , b ) );
            S2 += B[i];
        }
        n = nn;
        sort( A , A + n );
        sort( B , B + q );
        C[0] = B[0];
        for(int i = 1 ; i < q ; i++)
            C[i] = C[i-1] + B[i];
        
        ll aumenta = 0;
        for(int i = 0 ; i < n ; i++)
            if( A[i] + 1 < D ){
                if( A[i] + 1 + B[0] >= D ) break;
                if( A[i] + 1 + B[q-1] < D )
                    aumenta += D * q - C[q - 1] - q - q * A[i]; 
                else{

                    int lo = 0 , hi = q - 1;
                    while( lo + 1 < hi ){
                        int mid = (lo + hi)>>1;
                        if( A[i] + 1 + B[mid] < D ) lo = mid;
                        else hi = mid;
                    }
                    aumenta += D * (lo + 1) - C[ lo ] - (lo + 1) - (lo + 1) * A[i];
                }
            }
        double ans = ( S1 * q + S2 * n + aumenta )/( 1.0 * n * q ) + 1;
        printf("%.3lf\n",ans);
    }
    return 0;
    
}
