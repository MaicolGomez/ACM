#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<queue>
using namespace std;
#define inf (1<<29)
#define eps 1e-8
#define ll long long
#define vi vector<int>
#define all(v) v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define L(x) ((x<<1)+ 1)
#define R(x) L(x)+1
#define M(x,y) ((x+y)>>1)
#define N 105

vector<int> adj[N] , cost[N];
int d[N];

int main(){
    int n , m;
    while( scanf("%d%d",&n,&m) == 2 && n ){
        int x , y , z;
        for(int i = 1 ; i <= n ; i++)
            adj[i].clear(), cost[i].clear();
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&x,&y,&z);
            adj[x].pb(y);
            adj[y].pb(x);
            cost[x].pb(z);
            cost[y].pb(z);
        }
        priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > Q;
        for(int i = 1 ; i <= n ; i++)
            d[i] = inf;
        d[1] = 0;
        Q.push( mp(0,1) );
        while( !Q.empty() ){
            pii q = Q.top(); Q.pop();
            int u = q.se , di = q.fi;
            for(int i = 0 ; i < adj[u].size() ; i++){
                int vec = adj[u][i];
                if( d[vec] > d[u] + cost[u][i] ){
                    d[vec] = d[u] + cost[u][i];
                    Q.push( mp( d[vec] , vec ) );
                }
            }
        }
        printf("%d\n",d[n]);
    }
}
