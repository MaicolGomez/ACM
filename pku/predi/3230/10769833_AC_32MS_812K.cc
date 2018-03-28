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
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf (1<<30)
#define eps 1e-8
#define ll unsigned long long
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mk(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define fi first
#define se second
#define N 105
#define mp(a,b) make_pair(a,b)

int n , m , t[N][N] , city[N][N] , day[N][N];

int f(int x,int y){
    if( y == m ) return 0;
    int &ret = t[x][y];
    if( ret != -inf ) return ret;
    ret = -city[x][x] + day[y][x] + f( x , y + 1 );
    for(int i = 0 ; i < n ; i++)if( i != x )
        ret = max( ret , -city[x][i] + day[y][i] + f( i , y + 1 ) );
    return ret;
}

int main(){
    while( scanf("%d%d",&n,&m) == 2 && (n||m) ){
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                sc( city[i][j] );
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                sc( day[i][j] );
        for(int i = 0 ; i < n ; i++)
            fill_n( t[i] , m + 1 , -inf );
        printf("%d\n",f(0 , 0));
    }
}