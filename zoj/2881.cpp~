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
#define N 1005

int p[N] , n , m;
vi adj[N] , cost[N];

int dijkstra(int c,int s,int e){
    vector< vi > d = vector< vector<int> > ( n , vector<int> ( c + 1 , inf ) );
    vector< vector<bool> > vis = vector< vector<bool> > ( n , vector<bool> ( c + 1 , 0 ) );
    d[s][0] = 0;
    priority_queue< pair< int , pii > > Q;
    Q.push( mp( 0 , mp( s , 0 ) ) );
    while( !Q.empty() ){
        pair< int , pii > q = Q.top(); Q.pop();
        int u = q.se.fi , have = q.se.se , di = -q.fi;
        if( u == e ) return di;
        if( vis[u][have] ) continue;
        vis[u][have] = 1;
        for(int i = 0 ; i + have <= c ; i++){
            int nd = di + p[u] * i;
            if( d[u][have + i] > nd ){
                d[u][have + i] = nd;
                Q.push( mp( -nd , mp( u , have + i ) ) );
            }
        }
        
        for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
            int v = adj[u][i] , nd = di;
            if( have >= cost[u][i] and nd < d[v][have - cost[u][i]] ){
                d[v][have - cost[u][i]] = nd;
                Q.push( mp( -nd , mp( v , have - cost[u][i] ) ) );
            }
        }
        
    }
    return -1;
}

int main(){
    while( scanf("%d%d",&n,&m) == 2 ){
        for(int i = 0 ; i < n ; i++)
            sc(p[i]);
        int a , b , c;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].pb(b); cost[a].pb(c);
            adj[b].pb(a); cost[b].pb(c);
        }
        int q;
        sc(q);
        while( q-- ){
            int s , e , c;
            scanf("%d%d%d",&c,&s,&e);
            int ans = dijkstra( c , s , e );
            if( ans == -1 ) printf("impossible\n");
            else printf("%d\n",ans);
        }
    }
    return 0;
}
