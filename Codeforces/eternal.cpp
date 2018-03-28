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
#define N 100501

vi adj[N] , cost[N];
ll d[N];

void dfs(int u,ll x,int pa){
    d[u] = x;
    
    for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
        int v = adj[u][i] , y = cost[u][i];
        if( v != pa )
            dfs( v , x + y , u );
    }
}

int main(){
    int n;
    while( sc(n) == 1 ){
        for(int i = 1 ; i <= n ; i++)
            adj[i].clear();
        
        int a , b , c;
        ll S = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].pb(b); cost[a].pb(c);
            adj[b].pb(a); cost[b].pb(c);
            S += c;
        }
        S *= 2;
        
        dfs( 1 , 0 , -1 );
        ll ans = (1LL<<60);
        
        for(int i = 1 ; i <= n ; i++)
            ans = min( ans , S - d[i] );
        
        cout << ans << '\n';
    }
    return 0;
}
