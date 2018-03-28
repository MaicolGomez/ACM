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
#define N 105

struct nodo{
    int u;
    double d;
    nodo(){}
    nodo(int U,double D){
        u = U;
        d = D;
    }
};

bool operator<(nodo A,nodo B){
    return A.d > B.d;
}

double d[N];
bool vis[N];
vi adj[N];
vector<double> cost[N];

int main(){
    int n , m , a , b , c;
    while( sc(n) == 1 && n ){
        sc(m);
        for(int i = 0 ; i <= n ; i++)
            d[i] = 1.0 , adj[i].clear() , cost[i].clear();
            
        me(vis,0);
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].pb(b) , cost[a].pb(1.0 - c/100.0);
            adj[b].pb(a) , cost[b].pb(1.0 - c/100.0);
        }
        
        priority_queue<nodo> Q;
        Q.push( nodo( 1 , 0.0 ) );
        d[1] = 0.0;
        while( !Q.empty() ){
            nodo q = Q.top(); Q.pop();
            int u = q.u;
            double dd = q.d;
            if( u == n ) break;
            if( vis[u] ) continue;
            vis[u] = 1;
            for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
                int v = adj[u][i];
                if( dd + (1.0 -  dd) * cost[u][i] < d[v] ){
                    d[v] = dd + (1.0 - dd) * cost[u][i];
                    Q.push( nodo( v , d[v] ) );
                }
            }
        }
        printf("%.6lf percent\n", (1-d[n])*100.0 );
    }
    return 0;
}
