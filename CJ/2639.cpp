#include<bits/stdc++.h>
using namespace std;
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
#define N 100000


vector<int> adj[N];
vector<int> articulation;
bool visited[N];
int d[N] , lowpt[N] , pi[N];
int timer , n;

void dfs(int u) {
    int sons=0, v;
    bool art = false;
    visited[u] = true; lowpt[u] = d[u] = timer++;
    for( int i = 0 ; i < adj[u].size() ; i++){
        v = adj[u][i];
        if(!visited[ adj[u][i] ]){
            sons++;
            pi[v] = u;
            dfs(v);
            lowpt[u] = min( lowpt[u] ,  lowpt[v] );
            if ( (pi[u] != -1) && (lowpt[v] >= d[u])) art = true;
        }
        else if ( v!= pi[u] ) lowpt[u] = min( lowpt[u] , d[v]);
    }
    if( art ) articulation.push_back(u);
    else if (pi[u] == -1 && sons > 1 ) articulation.push_back(u);
}

void articulations(){
    articulation.clear();
    timer = 0;
    for(int i = 0 ; i <= n ; i++){
        visited[i] = false;
        pi[i] = -1;
    }
    for(int i = 1 ; i <= n ; i++)
        if( !visited[i] )
            dfs(i);

    printf("%d\n", int( articulation.size() ));
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int m , x , y;
        scanf("%d%d",&n,&m);
        for(int i = 0 ; i < n + 1 ; i++)
            adj[i].clear();
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        articulations();
    }
    return 0;
}
