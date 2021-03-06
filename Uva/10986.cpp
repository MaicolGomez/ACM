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
#define N 20005

struct nodo{
    int u , d;
    nodo(){}
    nodo(int U,int D){
        u = U, d = D;
    }
};

bool operator<(nodo A,nodo B){
    return A.d > B.d;
}

vector< pii > adj[N];
int d[N];

int dijkstra(int s,int t){
    if( s == t ) return 0;
    d[s] = 0;
    priority_queue< nodo > Q;
    Q.push( nodo(s,0) );
    while( !Q.empty() ){
        nodo q = Q.top(); Q.pop();
        int u = q.u;
        if( u == t ) return d[u]; 
        for(int i = 0 ; i < adj[u].size() ; i++){
            int v = adj[u][i].fi , nd = d[u] + adj[u][i].se;
            if( d[v] > nd ){
                d[v] = nd;
                Q.push( nodo(v,nd) );
            }
        }
    }
    return inf;
}

int main(){
    int tc , test = 0 , n , m , s , t , x , y , c;
    sc(tc);
    while(tc--){
        printf("Case #%d: ",++test);
        scanf("%d%d%d%d",&n,&m,&s,&t);
        for(int i = 0 ; i < n ; i++)
            adj[i].clear() , d[i] = inf;
        
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&x,&y,&c);
            adj[x].pb( mp(y,c) );
            adj[y].pb( mp(x,c) );
        }
        int ans = dijkstra( s , t );
        if( ans == inf ) printf("unreachable\n");
        else printf("%d\n",ans);
    }
    
    return 0;
}
