#include<bits/stdc++.h>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf (1<<30)
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
#define ios ios::sync_with_stdio(0)
#define N 5005

vi adj[N] , cost[N];
int n;

vi dijkstra(int s){
    priority_queue< pii > Q;
    Q.push( mp( 0 , s ) );
    vector<bool> vis( n + 1 , 0 );
    vi d( n + 1 , inf );
    d[ s ] = 0;
    while( !Q.empty() ){
        pii q = Q.top(); Q.pop();
        int u = q.se , di = -q.fi;
        if( vis[u] ) continue;
        vis[u] = 1;
        for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
            int v = adj[u][i];
            if( d[v] > d[u] + cost[u][i] ){
                d[v] = d[u] + cost[u][i];
                Q.push( mp( -d[v] , v ) );
            }
        }
    }
    return d;
}

int main(){
    int m , a , b , c;
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < m ; i++){
        scanf("%d%d%d",&a,&b,&c);
        adj[a].pb( b ); cost[a].pb( c );
        adj[b].pb( a ); cost[b].pb( c );
    }
    vi x = dijkstra( 1 );
    vi y = dijkstra( n );
    int ans = inf;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 0 ; j < adj[i].size() ; j++){
            int r = x[ i ] + cost[i][j] + y[ adj[i][j] ];
            if( r != x[n] ) ans = min( ans , r );
        }
            
    printf("%d\n",ans);
    return 0;
}
