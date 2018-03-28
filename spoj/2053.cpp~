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
#define N 105
#define color 5
struct nodo{
    int x , y , d , mask;
    nodo(){};
    nodo(int X,int Y,int D,int M){
        x = X , y = Y , d = D , mask = M;
    }
};

bool operator<(nodo A,nodo B){
    return A.d > B.d;
}
int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , 1 , -1 };
int R , C , d[N][N][1<<5];
char s[N][N];
bool vis[N][N][1<<5];
int t[256];

int bfs(int xx,int yy){
    for(int i = 0 ; i < R ; i++)
        for(int j = 0 ; j < C ; j++)
            for(int k = 0 ; k < (1<<5) ; k++)
                d[i][j][k] = inf;
    me(vis,0);
    queue<nodo> Q;
    Q.push( nodo( xx , yy , 0 , 0 ) );
    d[xx][yy][0] = 0;
    while( !Q.empty() ){
        nodo q = Q.front(); Q.pop();
        int x = q.x , y = q.y , mask = q.mask , di = q.d;
        //cout << x << " -- " << y << " -- " << mask << endl;
        if( vis[x][y][mask] ) continue;
        if( s[x][y] == 'X' ) return d[x][y][mask];
        vis[x][y][mask] = 1;
        for(int i = 0 ; i < 4 ; i++){
            int u = x + dx[i] , v = y + dy[i];
            if( u >= 0 && u < R && v >= 0 && v < C && s[u][v] != '#' ){
                if( s[u][v] == '.' || s[u][v] == 'X' || s[u][v] == '*' ){
                    if( d[u][v][mask] > di + 1 ){
                        d[u][v][mask] = di + 1;
                        Q.push( nodo( u , v , di + 1 , mask ) );
                    }
                }
                else if( s[u][v] <= 'Z' ){
                    if( (mask&(1<<t[s[u][v]])) && d[u][v][mask] > di + 1 ){
                        d[u][v][mask] = di + 1;
                        Q.push( nodo( u , v , di + 1 , mask ) );
                    }
                }
                else{
                    int nmask = mask|(1<<t[s[u][v]]);
                    if( d[u][v][nmask] > di + 1 ){
                        d[u][v][nmask] = di + 1;
                        Q.push( nodo( u , v , di + 1 , nmask ) );
                    }
                }
            }
        }
        
    }
    return inf;
}

int main(){
    t['r'] = 1; t['g'] = 2; t['y'] = 3; t['b'] = 4;
    t['R'] = 1; t['G'] = 2; t['Y'] = 3; t['B'] = 4;
    while( scanf("%d%d",&R,&C) == 2 && R||C ){
        int x , y;
        for(int i = 0 ; i < R ; i++){
            scanf("%s",s[i]);
            for(int j = 0 ; j < C ; j++)
                if( s[i][j] == '*' ) x = i , y = j;
        }
        int ans = bfs( x , y );
        if( ans < inf ) printf("Escape possible in %d steps.\n",ans);
        else printf("The poor student is trapped!\n");
    }
    return 0;
}
