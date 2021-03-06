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
#define N 1001

int f[N][N][2] , t[N][N][2] , pa[N][N][2];
int n;
int a[2] = { 2 , 5 };

int g(int x,int y,int h){
    if( x == n or y == n ) return inf;
    if( x == n - 1 and y == n - 1 )
        return f[x][y][h];
    
    int &ret = t[x][y][h];
    if( ret != -1 ) return ret;
    
    
    ret = f[x][y][h] + g( x + 1 , y , h ); pa[x][y][h] = 0;
    if( ret > f[x][y][h] + g( x , y + 1 , h) ){
        ret = f[x][y][h] + g( x , y + 1 , h);
        pa[x][y][h] = 1;
    }
    return ret;
}

int main(){
    while( sc(n) == 1 ){
        int x , p = -1 , q = -1;
        me(f,0);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                sc(x);
                int r = x , s = x;
                while( r % 2 == 0 and r ){
                    f[i][j][0]++;
                    r /= 2;
                }
                while( x % 5 == 0 and x ){
                    f[i][j][1]++;
                    x /= 5;
                }
                if( s == 0 ) p = i , q = j;
            }
        }
        
        me(t,-1);
        me(pa,-1);
        int h = 0;
        if( g( 0 , 0 , 0 ) > g( 0 , 0 , 1 ) )
            h = 1;
        
        string s = "";
        int y = 0; x = 0;
        
        if( p >= 0 and g( 0 , 0 , h ) > 1 ){
            cout << "1\n";
            for(int i = 0 ; i < p ; i++) cout << 'D';
            for(int i = 0 ; i < q ; i++) cout << 'R';
            for(int i = 0 ; i < n - p - 1 ; i++) cout << 'D';
            for(int i = 0 ; i < n - q - 1 ; i++) cout << 'R';
            cout << '\n';
            continue;
        }
        
        cout << g( 0 , 0 , h ) << '\n';
        
        while( 1 ){
            //cout << x << " " << y << " " << h << " " << pa[x][y][h] << '\n';
            if( pa[x][y][h] == 0 ){
                cout << 'D';
                x += 1;
            }
            else{
                cout << 'R';
                y += 1;
            }
            if( x == n - 1 and y == n - 1 ) break;
        }
        cout << '\n';
    }
    return 0;
}
