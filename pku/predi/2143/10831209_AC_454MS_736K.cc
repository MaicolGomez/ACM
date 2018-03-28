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
#define inf 2000000000
#define eps 1e-6
#define ll long long
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
#define N 10

int n , m;
int T[N][N][N];
bool vis[N][N][N]; // x - y - z
int dx[13] = { 1 , 1 , 1 , 0  , 0 , 1 , 1 , 0 , 0 , 1 , 1 , 1 , 1 };
int dy[13] = { -1 , 0 , 1 , 1 , 0 , 0 , 0 , 1 , 1 , 1 , -1 , 1 , -1 };
int dz[13] = { 0 , 0 , 0 , 0 , 1 , 1 , -1 , 1 , -1 , 1 , 1 , -1 , -1 };

void clean(){
    me(T,-1);
    me(vis,0);
}

void put(int x,int y,int color){
    for(int i = 0 ; i < n ; i++)if( vis[x][y][i] == 0 ){
        vis[x][y][i] = 1;
        T[x][y][i] = color;
        //cout << x << " " << y << " " << i << " " << color << endl;
        break;
    }
}

int win(){
    for(int x = 0 ; x < n ; x++){
        for(int y = 0 ; y < n ; y++)if( vis[x][y][0] ){
            for(int z = 0 ; z < n ; z++)if( vis[x][y][z] ){
                int color = T[x][y][z];
                for(int i = 0 ; i < 13 ; i++){
                    int j = 0 , u = x , v = y , w = z;
                    
                    for( ; j < m ; j++ , u += dx[i] , v += dy[i] , w += dz[i] )
                        if( u < 0 || u >= n || v < 0 || v >= n || w < 0 || w >= n || !vis[u][v][w] || T[u][v][w] != color ) break;
                        
                    if( j == m ) return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    int p ,x , y;
    while( cin >> n >> m >> p , n , m , p ){
        clean();
        bool ok = 0;
        for(int i = 1 ; i <= p ; i++){
            cin >> x >> y; x--,y--;
            put( x , y , i % 2 );
            if( !ok && win() ){
                cout << ( (i&1)?"Black":"White" ) << " " << i << '\n';
                ok = 1;
            }
        }
        if( !ok ) cout << "Draw\n";
    }
}