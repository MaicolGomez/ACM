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
#define N 100005

struct nodo{
    int u , c , d;
    nodo(){}
    nodo(int U,int C,int D){
        u = U, c = C , d = D;
    }
};

bool operator<(nodo A,nodo B){
    return A.d > B.d;
}

vi adj[N] , cost[N];
vi A[N] , C[N];
bool vis[N][2];
int d[N][2];

int dijkstra(int n,int s,int t){
    for(int i = 0 ; i <= n ; i++)
        d[i][0] = d[i][1] = inf;
    
    priority_queue<nodo> Q;
    Q.push( nodo( s , 0 , 0 ) );
    d[s][0] = 0;
    while( !Q.empty() ){
        nodo q = Q.top(); Q.pop();
        int u = q.u , dd = q.d , c = q.c;
        if( u == t ) return d[u][c];
        if( vis[u][c] ) continue;
        vis[u][c] = 1;
        for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
            int v = adj[u][i] , nd = dd + cost[u][i];
            if( nd < d[v][c] ){
                d[v][c] = nd;
                Q.push( nodo( v , c , nd ) );
            }
        }
        if( !c ){
            for(int i = A[u].size() - 1 ; i >= 0 ; i--){
                int v = A[u][i] , nd = dd + C[u][i];
                if( nd < d[v][1] ){
                    d[v][1] = nd;
                    Q.push( nodo( v , 1 , nd ) );
                }
            }
        }
    }
    return -1;
}

int main(){
    int tc , n , m , k , s , t;
    sc(tc);
    while(tc--){
        scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
        for(int i = 0 ; i <= n ; i++)
            adj[i].clear() , cost[i].clear() , A[i].clear() , C[i].clear() , vis[i][0] = vis[i][1] = 0;
            
        int a , b , c;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].pb(b) , cost[a].pb(c);
            //adj[b].pb(a) , cost[b].pb(c);
        }
        for(int i = 0 ; i < k ; i++){
            scanf("%d%d%d",&a,&b,&c);
            A[a].pb(b) , C[a].pb(c);
            A[b].pb(a) , C[b].pb(c);
        }
        int ans = dijkstra( n , s , t );
        printf("%d\n",ans);
    }
    return 0;
}
