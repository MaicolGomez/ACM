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
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 1100

int c[22] , S , T , C[N][N] , can[N][N];
bool vis[N];
vi adj[N];

int dfs(int u,int g){
    if( u == T ) return g;
    if( vis[u] ) return 0;
    vis[u] = 1;
    for(int i = 0 ; i < T + 1 ; i++){
        if( C[u][i] ){
            int r = dfs( i , min( g , C[u][i] ) );
            if( r ){
                C[u][i] -= r;
                C[i][u] += r;
                return r;
            }
        }
    }
    return 0;
}

int maxFlow(){
    int flow = 0;
    while( 1 ){
        me(vis,0);
        int r = dfs( S , inf );
        if( !r ) break;
        flow += r;
    }
    return flow;
}

int main(){
    int n , m;
    while( scanf("%d%d",&n,&m) == 2 and (n||m) ){
    
        S = 0 , T = n + m + 1;
        me(C,0);
        me(can,0);
        int k = 0;
        for(int i = 0 ; i < n ; i++){
            sc(c[i]);
            C[S][ i + 1 ] = c[i];
            k += c[i];
        }
        for(int i = 1 ; i <= m ; i++){
            C[n+i][T] = 1;
            int x , y;
            sc(x);
            for(int j = 0 ; j < x ; j++){
                sc(y);
                C[y][n + i] = 1;
                can[y][n+i] = 1;
            }
        }
        int flow = maxFlow();
        if( k == flow ){
            printf("1\n");
            for(int i = 1 ; i <= n ; i++){
                bool ok = 0;
                for(int j = 1 ; j <= m ; j++)
                    if( can[i][n + j] and !C[i][n+j] ){
                        if( ok ) printf(" ");
                        printf("%d",j);
                        ok = 1;
                    }
                printf("\n");
            }
        }
        else printf("0\n");
    }
    return 0;
}
