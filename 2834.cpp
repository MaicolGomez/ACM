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
#define N 1005

vi adj[N];
int C[N];
bool vis[N] , is[N];

void dfs(int u){
    if( vis[u] ) return;
    vis[u] = 1;
    C[u]++;
    for(int i = 0 ; i < adj[u].size() ; i++)
        dfs( adj[u][i] );
}

int main(){
    int n , m , k;
    while( scanf("%d%d%d",&k,&n,&m) == 3 ){
        int x , y;
        int a[k];
        for(int i = 0 ; i < k ; i++){
            sc(a[i]), a[i]--;
            is[ a[i] ] = 1;
        }
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&x,&y); x--,y--;
            adj[x].pb( y );
        }
        for(int i = 0 ; i < k ; i++){
            me(vis,0);
            dfs( a[i] );
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            if( C[i] == k ) ans++;
        
        printf("%d\n",ans);
    }
    return 0;
}
