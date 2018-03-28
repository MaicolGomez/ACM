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
#define ios ios::sync_with_stdio(0)
#define N 30

int n , ans , v[N] , r;
bool vis[N];
vi adj[N];

void solve(int x){
    if( v[x] == n ){
        ans++;
        for(int i = 0 ; i < x + 1 ; i++){
            if( i ) printf(" ");
            printf("%d",v[i]);
        }
        printf("\n");
        return;
    }
    int l = adj[ v[x] ].size();
    int u = v[x];
    x++;
    for(int i = 0 ; i < l ; i++){
        int y = adj[ u ][i];
        if( vis[y] == 0 ){
            vis[y] = 1;
            v[x] = y;
            solve( x );
            vis[y] = 0;
        }
    }
    return;
}

bool dfs(int u){
    if( u == n ) return 1;
    if( vis[u] ) return 0;
    vis[u] = 1;
    for(int i = 0 ; i < adj[u].size() ; i++)
        if( dfs( adj[u][i] ) ) return 1;
    return 0;
}

int main(){
    int test = 1;
    while( sc(n) == 1 ){
        printf("CASE %d:\n",test++);
        ans = 0;
        int x , y;
        for(int i = 0 ; i < N ; i++)
            adj[i].clear() , vis[i] = 0;
            
        while( scanf("%d%d",&x,&y) == 2 and (x || y) ){
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for(int i = 0 ; i < N ; i++)
            sort( all(adj[i]) );

        me(vis,0);
        if( dfs( 1 ) ){
            me(vis,0);
            v[0] = 1;
            vis[1] = 1;
            solve( 0 );
            printf("There are %d routes from the firestation to streetcorner %d.\n",ans,n);
        }
        else printf("There are %d routes from the firestation to streetcorner %d.\n",0,n);
    }
    return 0;
}
