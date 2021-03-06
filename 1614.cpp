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

map<int,int> m;
int n , in[N];
vi adj[N];
bool vis[N];

int get(int x){
    if( m.find( x ) == m.end() ) m[x] = n++;
    return m[x];
}

void dfs(int u){
    if( vis[u] ) return;
    vis[u] = 1;
    for(int i = adj[u].size() - 1 ; i >= 0 ; i--)
        dfs( adj[u][i] );
}

int main(){
    int x , y , test = 0;
    while( scanf("%d%d",&x,&y) == 2 and x != -1 ){
        for(int i = 0 ; i < N ; i++)
            adj[i].clear();
        me(in,0);
        me(vis,0);
        n = 0;
        m.clear();
        while( (x||y) ){
            x = get( x ) , y = get( y );
            in[y]++;
            adj[x].pb( y );
            scanf("%d%d",&x,&y);
        }
        
        bool ans = 1;
        int root = -1 , ct = 0 , ones = 0;
        for(int i = 0 ; i < n ; i++)
            if( in[i] == 0 ) root = i , ct++;
            else if( in[i] == 1 ) ones++;

        if( ones == n - 1 and ct == 1 ) dfs( root );
        else ans = 0;
        for(int i = 0 ; i < n ; i++)
            if( !vis[i] ) ans = 0;
        if( n == 0 ) ans = 1;
        printf("Case %d ",++test);
        if( ans ) printf("is a tree.\n");
        else printf("is not a tree.\n");
    }
    return 0;
}
