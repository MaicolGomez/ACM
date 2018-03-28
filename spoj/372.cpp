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
#define MOD 10009
#define N 50005

vi adj[N] , cost[N];
int D[N] , ans;

void dfs(int u,int pa){
    int mx1 = 0 , mx2 = 0;
    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i] , r = cost[u][i];
        if( v == pa ) continue;
        dfs( v , u );
        if( D[v] + r > mx1 ) mx2 = mx1 , mx1 = D[v] + r;
        else if( D[v] + r > mx2 ) mx2 = D[v] + r;
    }
    ans = max( ans , mx1 + mx2 );
    D[u] = mx1;
}

int main(){
    int tc , n , a , b , c;
    sc(tc);
    while(tc--){
        sc(n);
        ans = 0;
        for(int i = 0 ; i <= n ; i++)
            adj[i].clear() , cost[i].clear() , D[i] = 0;
        
        for(int i = 0 ; i < n - 1 ; i++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].pb(b); cost[a].pb(c);
            adj[b].pb(a); cost[b].pb(c);
        }
        dfs( 1 , -1 );
        printf("%d\n",ans);
    }
    return 0;
}
