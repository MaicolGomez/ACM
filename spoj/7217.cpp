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
#define N 22

int a[N][N];

int main(){
    int n , m;
    while( scanf("%d%d",&n,&m) == 2 ){
        int x , y;
        sc(x),sc(y);
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                sc(a[i][j]);
        
        int t[N][N];
        t[x][y] = 0;
        for(int i = x ; i <= n ; i++)
            for(int j = y ; j <= m ; j++){
                if( i == x && y == j ) continue;
                if( i == x ) t[i][j] = t[i][j-1] + a[i][j];
                else if( j == y ) t[i][j] = t[i-1][j] + a[i][j];
                else t[i][j] = a[i][j] + min( t[i-1][j] , t[i][j-1] );
            }
        if( t[n][m] <= a[x][y] ) printf("Y %d\n", a[x][y] - t[n][m] );
        else printf("N\n");
    }
    return 0;
}
