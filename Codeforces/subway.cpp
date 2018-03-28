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
#define N 3005

vi adj[N];
int pa[N];
bool vis[N] , cycle[N] , ok;

void f(int u,int p){
    if(ok) return;
    pa[u] = p;
    vis[u] = 1;
    for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
        if(ok) return;
        int v = adj[u][i];
        if( v != p ){
            if( !vis[v] ){
                f( v , u );
            }
            else{
                cycle[u] = 1;
                int x = u;
                //cout << u << " --> " << v << " : " << pa[u] << endl;
                while( x != v ){
                    x = pa[x];
                    cycle[x] = 1;
                }
                ok = 1;
                return;
            }
        }
    }
    
}

int d[N];

void dfs(int u,int pa,int r = 0){
    d[u] = r;
    for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
        int v = adj[u][i];
        if( v != pa && !cycle[v] ) dfs( v , u , r + 1 );
    }
}

int main(){
    int n;
    while( sc(n) == 1 ){
        int x , y;
        for(int i = 0 ; i < n ; i++)
            adj[i].clear();
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d",&x,&y); x--,y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        me(vis,0);
        me(cycle,0);
        ok = 0;
        f( 0 , -1 );
        for(int i = 0 ; i < n ; i++)if( cycle[i] )
            dfs( i , -1 );
        
        for(int i = 0 ; i < n ; i++){
            if( i ) printf(" ");
            printf("%d",d[i]);
        }
        printf("\n");
    }
    return 0;
}
