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
#define N 100

char s[N/4][N];
int r , c;
bool vis[N][N];
int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , 1 , -1 };

void dfs(int x,int y,char z){
    s[x][y] = z;
    vis[x][y] = 1;
    for(int i = 0 ; i < 4 ; i++){
        int u = x + dx[i] , v = y + dy[i];
        if( u >= 0 && u < r && v >= 0 && v < c && s[u][v] == ' ' && !vis[u][v] )
            dfs( u , v , z );
    }
}

int main(){
    while( gets(s[0]) ){
        r = 1;
        while( gets(s[r]) ){
            r++;
            if( s[r-1][0] == '_' ) break;
            c = max( c , (int)strlen(s[r-1]) );
        }

        me(vis,0);
        
        for(int i = 0 ; i < r-1 ; i++)
            for(int j = 0 ; j < strlen(s[i]) ; j++)
                if( s[i][j] != ' ' && s[i][j] != 'X' && !vis[i][j] ){

                    dfs( i , j , s[i][j] );
                }
        for(int i = 0 ; i < r ; i++)
            puts(s[i]);
        
        
    }
    return 0;
}
