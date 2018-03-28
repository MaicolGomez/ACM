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
#define N 100010

bool vis[N];
vi adj[N] , radj[N];
int I[N] , comp[N];
vi v;

void dfs1(int u){
    vis[u] = 1;
    for (int i = 0 ; i < adj[u].size() ; i++ )
        if ( !vis[ adj[u][i]] ) dfs1 ( adj[u][i] );
 
    v.push_back(u);
}

void dfs2(int u,int c){
    vis[u] = 0;
    comp[u] = c;
    for (int i = 0 ; i < radj[u].size() ; i++ )
        if ( vis[ radj[u][i]] ) dfs2 ( radj[u][i] , c);
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n , m , x , y;
        scanf("%d%d",&n,&m);
        
        for(int i = 0 ; i < N  ; i++)
            adj[i].clear() , radj[i].clear();
            
        v.clear();
        me(vis,0);
        me(I,0);
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&x,&y); x--,y--;
            adj[x].pb(y);
            radj[y].pb(x);
        }
        
        for(int i = 0 ; i < n ; i++)if( !vis[i] )
            dfs1( i );
            
        int c = 0;
        
        for(int i = v.size() - 1; i >= 0; i-- ) {
            if ( vis [ v[i] ] )
                dfs2 ( v[i], c++);
        }
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < adj[i].size() ; j++)
                if( comp[ i ] != comp[ adj[i][j] ] )
                    I[ comp[ adj[i][j] ] ]++;
        
        int ans = 0;
        for(int i = 0 ; i < c ; i++)
            ans += (I[i] == 0);
        printf("%d\n",ans);
    }
    return 0;
}
