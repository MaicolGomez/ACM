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
#define N 101

int n;
bool vis[N][N];
int dx[8] = { 1 , -1 , 0 , 0 };
int dy[8] = { 0 , 0 , 1 , -1 };

bool dfs(int x,int y,int lo ,int hi){
    if( x == n - 1 and y == n - 1 ) return 1;
    
    vis[x][y] = 1;
    
    for(int i = 0 ; i < 4 ; i++){
        int u = x + dx[i] , v = y + dy[i];
        if( u >= 0 and u < n and v >= 0 and v < n and !vis[x][y] )
            dfs( u , v , lo , hi );
    }
    
    return 0;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        sc(n);
        int lo = 0 , hi = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                sc(a[i][j]) , hi = max( hi , a[i][j] );
        
        int ans = 205;
        me(vis,0);
        while( hi <= 200 ){
            me( vis , 0 );
            while( dfs( 0 , 0 , lo , hi ) ){
                me(vis,0);
                ans = min( ans , hi - lo );
                lo++;
            }
            hi++;
        }
        printf("Scenario #%d:\n");
        printf("%d\n",ans);
    }
    return 0;
}
