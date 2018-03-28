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
#define N 55

int r , c , ct;
int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , 1 , -1 };
bool vis[N][N];
char s[N][N];
char land;

void dfs(int x,int y){
    vis[x][y] = 1;
    ct++;
    for(int i = 0 ; i < 4 ; i++){
        int u = x + dx[i] , v = y + dy[i];
        if( v == -1 ) v = c - 1;
        if( u >= 0 && u < r && v >= 0 && v < c && !vis[u][v] && s[u][v] == land )
            dfs( u , v );
        
    }
}

int main(){
    while( scanf("%d%d",&r,&c) == 2 ){
        for(int i = 0 ; i < r ; i++)
            scanf("%s",s[i]);
        
        int x , y;
        scanf("%d%d",&x,&y); 
        land = s[x][y];
        me(vis,0);
        dfs( x , y );
        int ans = 0;
        for(int i = 0 ; i < r ; i++)
            for(int j = 0 ; j < c ; j++)if( !vis[i][j] && s[i][j] == land ){
                ct = 0;
                dfs( i , j );
                ans = max( ans , ct );
            }
    
        printf("%d\n",ans);
    }
    return 0;
}
