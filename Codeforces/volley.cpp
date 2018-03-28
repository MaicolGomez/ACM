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
#define ios ios::sync_with_stdio(0);
#define N 1051

struct nodo{
    int u;
    ll d;
    nodo(){}
    nodo(int U,ll D){
        u = U , d = D;
    }
};

bool operator<(nodo A,nodo B){
        return A.d > B.d;
}

vi adj[N] , cost[N] , adj2[N] , cost2[N];
ll d[N];
bool vis[N];

void dijkstra( int uu ){
    for(int i = 0 ; i < N ; i++)
        d[i] = (1LL<<60) , vis[i] = 0;
        
    d[uu] = 0;
    priority_queue<nodo> Q;
    Q.push( nodo(uu,0) );
    while( !Q.empty() ){
        nodo q = Q.top(); Q.pop();
        int u = q.u; ll di = q.d;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
            int v = adj[u][i];
            ll nd = di + cost[u][i];
            if( d[v] > nd ){
                d[v] = nd;
                Q.push( nodo( v , nd ) );
            }
        }
    }
}

int main(){
    int n , m , C;
    while( scanf("%d%d",&n,&m) == 2 ){
        
        for(int i = 0 ; i < n ; i++)
            adj[i].clear() , adj2[i].clear() , cost[i].clear();
        
        int star , end , a , b , c;
        scanf("%d%d",&star,&end);
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&a,&b,&c); a--,b--;
            adj[a].pb(b), cost[a].pb(c);
            adj[b].pb(a), cost[b].pb(c);
        }
        int T;
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d",&T,&C);
            ll NT = 1LL * T;
            dijkstra( i );

            for(int j = 0 ; j < n ; j++)if( i != j and d[j] <= NT )
                adj2[i].pb(j) , cost2[i].pb(C);
            
        }
        for(int i = 0 ; i < n ; i++)
            adj[i] = adj2[i] , cost[i] = cost2[i];
        /*
        for(int i = 0 ; i < n ; i++){
            cout << i+1 << ": ";
            for(int j = 0 ; j < adj[i].size() ; j++){
                cout << adj[i][j]+1 << " ";
            }
            cout << endl;
        }*/
        
        dijkstra( star - 1 );
        
        if( d[end-1] >= (1LL<<60) ) cout << "-1\n";
        else cout << d[end-1] << '\n';
           
    }
    return 0;
}
