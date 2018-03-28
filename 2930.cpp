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
#define N 100001

int T[N] , n;
ll ans , x;
vi adj[N] , cost[N];

int g(int u,int p){
    T[u] = 1;
    for(int i = 0 ; i < adj[u].size() ; i++)
        if( adj[u][i] != p ) g( adj[u][i] , u );
    for(int i = 0 ; i < adj[u].size() ; i++)
        if( adj[u][i] != p ) T[u] += T[ adj[u][i] ];

}

void f(int u,ll d,int p){
    x += d;
    for(int i = 0 ; i < adj[u].size() ; i++)
        if( adj[u][i] != p ) f( adj[u][i] , d + cost[u][i] , u );
}

void dfs(int u,ll r, int p){
    ans += r;
    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];
        if( v != p ) dfs( v , r + (n - 2 * T[v] ) * cost[u][i] , u );
    }
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int a , b , c;
        sc(n);
        for(int i = 0 ; i < n ; i++)
            adj[i].clear() , cost[i].clear();
        for(int i = 0 ; i < n - 1 ; i++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].pb(b); cost[a].pb(c);
            adj[b].pb(a); cost[b].pb(c);
        }
        g( 0 , -1 );
        x = ans = 0;
        f( 0 , 0 , -1 );
        dfs( 0 , x , -1 );
        double ret = 1.0 * ans / ( n * (n-1) ) ;
        printf("%.8lf\n",ret);
    }
    return 0;
}
