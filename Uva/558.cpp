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
#define N 1001

vi adj[N] , cost[N]; 
int d[N] , n;

bool BellmanFord(int s){
    for(int i = 0 ; i < n ; i++){
       d[i] = inf;
    }
    d[s] = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        for(int u = 0 ; u < n ; u++)
            for(int j = 0 ; j < adj[u].size() ; j++){
                int v = adj[u][j];
                if( d[v] > d[u] + cost[u][j] )
                    d[v] = d[u] + cost[u][j];
            }
    }
    for(int u = 0 ; u < n ; u++)
        for(int j = 0 ; j < adj[u].size() ; j++){
            int v = adj[u][j];
            if( d[v] > d[u] + cost[u][j] )
                return 1;
        }
    return 0;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int m , x , y , c;
        scanf("%d%d",&n,&m);
        for(int i = 0 ; i < n ; i++) adj[i].clear(), cost[i].clear();
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&x,&y,&c);
            adj[x].pb(y); cost[x].pb(c);
        }
        if( BellmanFord(x) ) printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}
