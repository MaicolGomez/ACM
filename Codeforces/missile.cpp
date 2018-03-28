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
#define N 100021
#define llena(d,n,nnn) fill(d,d+n+1,nnn);

int d[N];

struct nodo{
    int x , d;
    nodo(){}
    nodo(int X,int D){
        x = X , d = D;
    }
};

bool operator<(nodo A,nodo B){
    return A.d > B.d;
}

bool vis[N];
int pa[N];
vi adj[N] , cost[N];

int main(){
    int n , m , s;
    while( scanf("%d%d%d",&n,&m,&s) == 3 ){
        int a , b , c;
        
        for(int i = 0 ; i < n + 1 ; i++)
            adj[i].clear() , cost[i].clear();
        
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].pb(b), cost[a].pb(c);
            adj[b].pb(a), cost[b].pb(c);
        }
        int l;
        sc(l);
        
        for(int i = 0 ; i < n + 1 ; i++)
            d[i] = 1000000007 , vis[i] = 0 , pa[i] = -1;
        
        d[s] = 0;
        priority_queue<nodo> Q;
        Q.push( nodo( s , 0 ) );
        while( !Q.empty() ){
            nodo q = Q.top(); Q.pop();
            int x = q.x , di = q.d;
            
            if( vis[x] ) continue;
            vis[x] = 1;
            
            for(int i = adj[x].size() - 1 ; i >= 0 ; i--){
                int v = adj[x][i] , nd = di + cost[x][i];
                if( d[v] > nd ){
                    d[v] = nd;
                    pa[v] = x;
                    Q.push( nodo( v , nd ) );
                }
            }
        }
        
        if( l == 0 ) printf("1\n");
        else{
            int ans = 0;
            for(int i = 1 ; i <= n ; i++){
                if( d[i] == l ) ans++;
                if( d[i] >= l ) continue;
                
                for(int j = adj[i].size() - 1 ; j >= 0 ; j--){
                    int u = i , v = adj[i][j] , costo = cost[u][j];
                    if( d[u] + costo <= l ) continue;
                    if(  l - d[u] + l - d[v] < costo or (2 * l - d[u] - d[v] == costo and u > v) ) ans++;                    
                }
            }
            printf("%d\n",ans );
        }
        
    }
    return 0;
}
