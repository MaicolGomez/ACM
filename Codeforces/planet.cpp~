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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 100102

vi adj[N];
vi cost[N];
vector< vi > timer;
int d[N];
bool vis[N];

struct nodo{
    int u , d;
    nodo(){}
    nodo(int U,int D){
        u = U , d = D;
    }
};

bool operator<(nodo A,nodo B){
        return A.d > B.d;
}

int main(){
    int a , b , n , m , c;
    while( scanf("%d%d",&n,&m) == 2 ){
        timer.clear();
        for(int i = 0 ; i < n ; i++){
            adj[i].clear();
            cost[i].clear();
            vis[i] = 0;
            d[i] = inf;
        }
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&a,&b,&c); a--,b--;
            adj[a].pb(b); cost[a].pb(c);
            adj[b].pb(a); cost[b].pb(c);
        }
        
        int k , x;
        for(int i = 0 ; i < n ; i++){
            sc(k);
            vi v;
            if( k > 0 ) v = vi ( k );
            for(int j = 0 ; j < k ; j++)
                sc(v[j]);
            timer.pb( v );
        }
        
        d[0] = 0;
        priority_queue< nodo > Q;
        Q.push( nodo( 0 , 0 ) );
        while( !Q.empty() ){
            nodo q = Q.top(); Q.pop();
            int u = q.u , di = q.d;
            if( u == n - 1 ) break;
            if( vis[u] ) continue;
            vis[u] = 1;
            
            int add = 0;
            while( binary_search( all( timer[u] ) , d[u] + add ) ) add++;
            
            for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
                int v = adj[u][i] , nd = di + add + cost[u][i];
                if( d[v] > nd ){
                    d[v] = nd;
                    Q.push( nodo( v , nd ) );
                }
            }
        }
        
        if( d[n-1] == inf ) cout << -1 << '\n';
        else cout << d[n-1] << '\n';
    }
    return 0;
}
