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
#define N 50005

int d[N][502] , n , k , F[N];
vi adj[N];

void dfs(int v,int f){
    F[v] = f;
    d[v][0] = 1;
    for(int i = adj[v].size() - 1 ; i >= 0 ; i--){
        int u = adj[v][i];
        if( u != f ){
            dfs( u , v );
        }
    }
    for(int i = adj[v].size() - 1 ; i >= 0 ; i--){
        int u = adj[v][i];
        if( u != f ){
            for(int j = 0 ; j < k ; j++)
                d[v][j+1] += d[u][j];
        }
    }
}

int main(){
    while( scanf("%d%d",&n,&k) == 2 ){
        for(int i = 0 ; i < n ; i++)
            adj[i].clear();
        me(d,0);
        int a , b;
        for(int i = 0 ; i < n - 1 ; i++){
            scanf("%d%d",&a,&b); a--,b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs( 0 , -1 );
        ll p = 0 , q = 0;
        for(int v = 0 ; v < n ; v++){
            p += d[v][k];
            for(int i = 0 ; i < adj[v].size() ; i++){
                int u = adj[v][i];
                if( u == F[v] ) continue;
                for(int x = 1 ; x <= k - 1 ; x++){
                    q += 1LL * d[u][x-1] * ( d[v][k-x] - d[u][k - x - 1] );
                    if( 1LL * d[u][x-1] * ( d[v][k-x] - d[u][k - x - 1] ) < 0 ) cout << v << " " << u << " " << x  << endl;
                }
            }
        }
        cout << p + q/2 << "\n";
    }
    return 0;
}
