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
#define N 100001

int x;
vi adj[N];

int bfs(int u , int n){
    vi d( n , -1 );
    queue<int> Q;
    Q.push( u );
    d[u] = 0;
    int ans = 0;
    while( !Q.empty() ){
        u = Q.front(); Q.pop();
        for(int i = 0 ; i < adj[u].size() ; i++){
            int v = adj[u][i];
            if( d[v] == -1 ){
                x = v;
                d[v] = d[u] + 1;
                ans = d[v];
                Q.push( v );
            }
        }
    }
    return ans;
}

int f(){
    int n , a , b;
    sc(n);
    for(int i = 0 ; i < n ; i++)
        adj[i].clear();
    for(int i = 0 ; i < n - 1 ; i++){
        scanf("%d%d",&a,&b); a--,b--;
        adj[a].pb(b),adj[b].pb(a);
    }
    bfs( 0 , n );
    return bfs( x , n );
}

int main(){
    freopen( "input.txt" , "r" , stdin );
    freopen( "output.txt" , "w" , stdout );
    int n;
    while( sc(n) == 1 ){
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            ans += f();
        printf("%d\n",ans);
    }
    return 0;
}
