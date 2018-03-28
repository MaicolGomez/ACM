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
#define fi first
#define se second
#define MOD 10009
#define N 100005

int n , m , k , niv , lvl[N] , pa[N] , solve;
vi adj[N];
int vis[N];

void dfs(int u){
    if( solve ) return;
    lvl[u] = niv;
    vis[niv++] = u;
    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];
        if( lvl[u] - lvl[v] >= k ){
            solve = 1;
            printf("%d\n",lvl[u]-lvl[v] + 1);
            for(int i = lvl[v] ; i <= lvl[u] ; i++){
                if( i > lvl[v] ) printf(" ");
                printf("%d",vis[i]);
            }
            return;
        }
        else if( lvl[v] == inf ) dfs( v );
        if( solve ) return;
    }
    
}

int main(){
    cin >> n >> m >> k;
    int x , y;
    niv = 0;
    for(int i = 0 ; i < m ; i++){
        sc(x),sc(y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    me(pa,-1);
    fill(lvl, lvl+n+1, inf);
    solve = 0;
    dfs( 1 );
    return 0;
}
