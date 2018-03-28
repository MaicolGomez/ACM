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
#define N 105

vi adj[N];
int cost[N] , d[N] , c[N][N];

int main(){
    int n;
    while( sc(n) == 1 and n != -1 ){
        for(int i = 0 ; i < n ; i++)
            adj[i].clear();
        
        me(c,0);
        for(int i = 0 ; i < n ; i++){
            sc(cost[i]);
            cost[i] *= -1;
            int vec , x;
            sc(vec);
            while( vec-- ){
                sc(x); x--;
                c[i][x] = 1;
                adj[i].pb(x);
            }
        }
        
        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)if( c[i][k] and c[k][j] )
                    c[i][j] = 1;
        
        for(int i = 0 ; i < n ; i++)
            d[i] = inf;
            
        d[0] = 0;
        for(int i = 0 ; i < n - 1 ; i++)
            for(int u = 0 ; u < n ; u++)
                for(int j = 0 ; j < adj[u].size() ; j++){
                    int v = adj[u][j];
                    if( d[v] > d[u] + cost[v] and d[u] + cost[v] < 100 )
                        d[v] = d[u] + cost[v];
                }
        
        bool cycle = 0;
        for(int u = 0 ; u < n ; u++)
            for(int j = 0 ; j < adj[u].size() ; j++){
                int v = adj[u][j];
                if( c[0][u] and c[u][n-1] and d[v] > d[u] + cost[v] and d[u] < 100 and d[v] < 100 )
                    cycle = 1;
            }
        //cout << c[0][n-1] << "\n";
        if( (cycle or d[n-1] < 100) and c[0][n-1] ) printf("winnable\n");
        else printf("hopeless\n");
    }
    return 0;
}
