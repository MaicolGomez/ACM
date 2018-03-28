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

vi adj[N];
bool vis[N];
int in[N];

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n , m;
        sc(n),sc(m);
        for(int i = 0 ; i < n ; i++)
            adj[i].clear() , in[i] = 0 , vis[i] = 0;
        
        int x , y;
        for(int i = 0 ; i < m ; i++){
            sc(x),sc(y); x--,y--;
            adj[x].pb(y);
            in[ y ]++;
            vis[x] = vis[y] = 1;
        }

        queue<int> Q;
        
        for(int i = 0 ; i < n ; i++)
            if( in[i] == 0 )
                Q.push( i );
        
        bool mul = 0;
        
        vi order;
        while( !Q.empty() ){
            int u = Q.front(); Q.pop();
            order.pb(u+1);
            if( Q.size() > 0 ) mul = 1;
            for(int i = 0 ; i < adj[u].size() ; i++){
                int v = adj[u][i];
                in[v]--;
                if( in[v] == 0 ) Q.push( v );
            }
        }
        bool rec = 0;
        for(int i = 0 ; i < n ; i++)
            if( in[i] > 0 ) rec = 1;
        
        if( rec ){
            printf("recheck hints\n");
            continue;
        }
        
        if( mul ){
            printf("missing hints\n");
            continue;
        }
       
        for(int i = 0 ; i < order.size() ; i++){
            if(i) printf(" ");
            printf("%d",order[i]);
        }
        printf("\n");
    }
    return 0;
}


