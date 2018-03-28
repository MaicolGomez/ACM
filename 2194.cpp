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
#define N 105
#define range( x , y , R , C ) (x >= 0 && x < R && y >= 0 && y < C)

int m[N][N] , C[N][N];
bool vis[N][N];
int n;
int dx[8] = { -1 , -1 , -1 , 0 , 1 , 1 , 1 , 0 };
int dy[8] = { 1 , 0 , -1 , -1 , -1 , 0 , 1 , 1 };

int count(int x,int y){
    int t = 0;
    for(int i = 0 ; i < 8 ; i++){
        int u = x + dx[i] , v = y + dy[i];
        if( range(u,v,n,n) && m[u][v] == 2 ) t++;
    }
    return t;
}

void dfs(int x,int y){
    if( vis[x][y] ) return;
    vis[x][y] = 1;
    int cont = count( x , y );
    C[x][y] = cont;
    if( cont == 0 )
        for(int i = 0 ; i < 8 ; i++){
            int u = x + dx[i] , v = y + dy[i];
            if( range( u , v , n , n) ) dfs( u , v );
        }
}

int main(){
    int t;
    while( sc(n) , sc(t) , n  ){
        
        int x , y;
        me(vis,0);
        me(m,0);
        for(int i = 0 ;  i < t ; i++){
            sc(x) , sc(y); x--,y--;
            m[x][y] = 2;
        }
        
        sc(x),sc(y); x--,y--;
        
        if( m[x][y] == 2 ) printf("oops!\n");
        else{
            dfs( x , y );
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if( !vis[i][j] ) printf(".");
                    else printf("%d",C[i][j]);
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
