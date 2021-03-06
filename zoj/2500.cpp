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
#define N 101

int n , m;
bool vis[N];

int dfs(int u,vi adj[N] ){
    vis[u] = 1;
    int ret = 0;
    for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
        int v = adj[u][i];
        if( vis[v] ) continue;
        ret += 1 + dfs( v , adj );
    }
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        sc(n),sc(m);
        
        vi adj[2][N];
        int a , b;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&a,&b); a--,b--;
            adj[0][a].pb(b) , adj[1][b].pb(a);
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            me(vis,0);
            int x = dfs( i , adj[0] );
            me(vis,0);
            int y = dfs( i , adj[1] );
            if( x > n/2 or y > n/2 ) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
