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

int n , a[N][N];
bool vis[N][N];
int dx[8] = { 1 , -1 , 0 , 0 };
int dy[8] = { 0 , 0 , 1 , -1 };

bool dfs(int x,int y,int lo ,int hi){
    if( x == n - 1 and y == n - 1 ) return 1;
    
    vis[x][y] = 1;
    
    bool solve = 0;
    for(int i = 0 ; !solve and i < 4 ; i++){
        int u = x + dx[i] , v = y + dy[i];
        if( u >= 0 and u < n and v >= 0 and v < n and !vis[u][v] and lo <= a[u][v] and a[u][v] <= hi )
            solve = solve or dfs( u , v , lo , hi );
    }
    
    return solve;
}

int main(){
    int tc;
    sc(tc);
    int test = 1;
    while( tc-- ){
        sc(n);
        int lo = 0 , hi = 0 , maxi = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                sc(a[i][j]) , maxi = max( maxi , a[i][j] );
        
        int ans = 202;
        me(vis,0);
        while( hi <= maxi ){
            me( vis , 0 );
            //cout << lo << " " << hi << endl;
            while( lo <= a[0][0] and a[0][0] <= hi and  dfs( 0 , 0 , lo , hi ) ){
                me(vis,0);
                ans = min( ans , hi - lo );
                lo++;
            }
            hi++;
        }
        printf("Scenario #%d:\n",test++);
        printf("%d\n\n",ans);
    }
    return 0;
}
