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
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 505

vi adj[N];
int to[N] , n;
bool vis[N];

bool dfs(int u){
    if( u == -1 ) return 1;
    for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
        int v = adj[u][i];
        if( vis[v] ) continue;
        vis[v] = 1;
        if( dfs( to[v]) ) {
            to[v] = u;
            return 1;
        }
    }
    return 0;
}

int bipartite(){
    int ans = 0;
    me(to,-1);
    for(int i = 0 ; i < n ; i++){
        me(vis,0);
        if( dfs( i ) ) ans++;
    }
    return ans;
}
  
int main(){
    while( sc(n) == 1 ){
        for(int i = 0 ; i < n ; i++)
            adj[i].clear();
        int id , x , v;
        for(int i = 0 ; i < n ; i++){
            scanf("%d: (%d)",&id,&x);
            for(int j = 0 ; j < x ; j++){
                sc(v);
                adj[id].pb(v);
                adj[v].pb(id);
            }
        }
        int match = bipartite();
        printf("%d\n", n - match/2);
    }
    return 0;
}
