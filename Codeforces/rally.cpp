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
#define N 305

int n , m[N][N] , t[N][N][N];
int dx[2] = { 1 , 0 };
int dy[2] = { 0 , 1 };

int f(int x,int y,int x1){
    if( x == n - 1 && y == n - 1 )
        return m[x][y];
    int &ret = t[x][y][x1];
    if( ret != -1 ) return ret;
    int y1 = x + y - x1;
    if( x == x1 )
        ret = m[x][y];
    else ret = m[x][y] + m[x1][y1];
    int g = -inf;
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            int u = x + dx[i] , v = y + dy[i];
            int r = x1 + dx[j] , s = y1 + dy[j];
            if( r >= 0 && r < n && u >= 0 && u < n && s >= 0 && s < n && v >= 0 && v < n )
                g = max( g , f( u , v , r ) );
        }
    }
    ret += g;
    return ret;
}

int main(){
    while( cin >> n ){
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                cin >> m[i][j];
        
        me(t,-1);
        cout << f( 0 , 0 , 0 ) << endl;
    }
    return 0;
}
