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
#define N 20005

int n , m , comp[N+10] , ncomp , in[N+10] , cost[N+5], mini[N+5] , out[N];
vi adj[N+10] , adjT[N+10];
bool vis[N+10];
stack<int> nodes;

void clean(){
    for(int i = 0 ; i < n ; i++){
        mini[i] = inf;
        adj[i].clear();
        adjT[i].clear();
    }
    me(vis,0);
    me(in,0);
    me(out,0);
}

void dfs1(int u){
    vis[u] = 1;
    for(int i = 0 ; i < adj[u].size() ; i++) if( !vis[ adj[u][i] ] ) dfs1( adj[u][i] );
    nodes.push(u);
}

void dfs2(int u){
    vis[u] = 0;
    for(int i = 0 ; i < adjT[u].size() ; i++) if( vis[ adjT[u][i] ] ) dfs2( adjT[u][i] );
    comp[u] = ncomp;
}

void solve(){
    for(int i = 0 ; i < n ; i++) if( !vis[i] ) dfs1( i );
    ncomp = 0;
    while( !nodes.empty() ){
        int q = nodes.top();
        nodes.pop();
        if( vis[ q ] ){
            dfs2(q);
            ++ncomp;
        }
    }
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < adj[i].size() ; j++)
            if( comp[i] != comp[ adj[i][j] ] )
                in[ comp[ adj[i][j] ] ]++ , out[ comp[ i ] ]++;
        
    
    int res = 0 , a = 0 , b = 0;
    for(int i = 0 ; i < ncomp ; i++){
        if( in[i] == 0 ) a++;
        if( out[i] == 0 ) b++;
    }
    res = max( a , b );
    if( ncomp == 1 ) res = 0;
    printf("%d\n",res);
}


int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        scanf("%d%d",&n,&m);
        clean();
        int x , y;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&x,&y); x--,y--;
            adj[x].pb( y );
            adjT[y].pb( x );
        }
        solve();
    }
    return 0;
}
