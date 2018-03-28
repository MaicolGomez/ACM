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
#define N 25

int R , C;
char s[N][N];
int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , 1 , -1 };

struct nodo{
    int x , y , d , mask;
    nodo(){}
    nodo(int X,int Y,int M,int D){
        x = X , y = Y , d = D , mask = M;
    }
};

int d[N][N][1<<11];
bool vis[N][N][1<<11];
map< pii , int > m;

int bfs(int xx,int yy,int n){
    for(int i = 0 ; i < R ; i++)
        for(int j = 0 ; j < C ; j++)
            for(int k = 0 ; k < 1<<n ; k++)
                vis[i][j][k] = 0 , d[i][j][k] = inf;    
    
    queue<nodo> Q;
    Q.push( nodo( xx , yy , 0 , 0 ) );
    d[xx][yy][0] = 0;
    while( !Q.empty() ){
        nodo q = Q.front(); Q.pop();
        int x = q.x , y = q.y , di = q.d , mask = q.mask;
        if( vis[x][y][mask] ) continue;
        vis[x][y][mask] = 1;
        //cout << x << " " << y << " " << mask << endl;
        if( mask == (1<<n) - 1 ) return di;
        for(int i = 0 ; i < 4 ; i++){
            int u = x + dx[i] , v = y + dy[i];
            if( u >= 0 && u < R && v >= 0 && v < C && s[u][v] != 'x' ){
                if( s[u][v] == 'o' || s[u][v] == '.' ){
                    if( d[u][v][mask] > di + 1 ){
                        d[u][v][mask] = di + 1;
                        Q.push( nodo( u , v , mask , di + 1 ) );
                    }
                }
                else{
                    //cout << x << " " << y  << " --> " << u << " " << v << " " << s[u][v] << endl; 
                    int nmask = mask|(1<<m[ mp(u,v) ]);
                    if( d[u][v][nmask] > di + 1 ){
                        d[u][v][nmask] = di + 1;
                        Q.push( nodo( u , v , nmask , di + 1 ) );
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    while( scanf("%d%d",&C,&R) == 2 && (R||C) ){
        m.clear();
        int x , y , ct = 0;
        for(int i = 0 ; i < R ; i++){
            scanf("%s",s[i]);
            for(int j = 0 ; j < C ; j++){
                if( s[i][j] == 'o' ) x = i , y = j;
                else if( s[i][j] == '*' ) m[ mp(i,j) ] = ct++;
            }
        }
        printf("%d\n",bfs( x , y , ct ));
        
    }
    return 0;
}
