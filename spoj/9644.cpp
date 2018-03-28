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
#define fi first
#define se second
#define MOD 10009
#define N 10005

vi adj2[N] , adj[N];
bool vis[N];
int n , t[N][2] , d;

void dirige(int u){
    vis[u] = 1;
    for(int i = 0 ; i < adj2[u].size() ; i++)if( vis[ adj2[u][i] ] == 0 ){
        adj[u].pb( adj2[u][i] );
        dirige( adj2[u][i] );
    }
}


int dfs(int u,int last){
    if( u == last) return 0;
    if( adj2[u].size() == 0 )
        return -inf;
    vis[u] = 1;
    int ans = 0;
    for(int i=0;i<adj2[u].size();i++)if( !vis[ adj2[u][i] ] )
        ans = max( ans , 1 + dfs( adj2[u][i] , last ));
        
    return ans;
}

int bfs(int u){
    me(vis,0);
    vi di(n+1,inf);
    di[u] = 0;
    queue<int> Q;
    Q.push( u );
    int find;
    while( !Q.empty() ){
        int q = Q.front();
        Q.pop();
        vis[q] = 1;
        for(int i = 0 ; i < adj2[q].size() ; i++)if( !vis[ adj2[q][i] ] ){
            int g = adj2[q][i] , nd = di[q] + 1;
            if( nd < di[g] ){
                find = g;
                di[g] = nd;
                Q.push(g);
                d = max( d , nd );
            }
        }
    }
    return find;
}

int main(){
    int x;
    while( sc(n) == 1 && n != -1 ){
        for(int i = 0 ; i <= n ; i++)
            adj2[i].clear() , adj[i].clear() , vis[i] = 0;
        for(int i = 1 ; i <= n-1 ; i++){
            sc(x);
            adj2[i+1].pb(x);
            adj2[x].pb(i+1);
        }
        //dirige(1);
        d = 0;
        //cout << "llega" << endl;
        int x = bfs( 1 );
        int y = bfs( x );
        //printf("%d\n",d/2);
        me(vis,0);
        printf("%d\n", (dfs(x,y)+1)/2 );
    }
    return 0;
}
