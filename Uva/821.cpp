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

int d[N][N];

int main(){
    int x , y , test = 0;
    while( scanf("%d%d",&x,&y) == 2 ){
        if( x == 0 && y == 0 ) break;
        for(int i = 1 ; i <= 100 ; i++)
            for(int j = 1 ; j <= 100 ; j++)
                d[i][j] = inf;
        
        for(int i = 1 ; i <= 100 ; i++)
            d[i][i] = 0;
            
        d[x][y] = 1;
        while( scanf("%d%d",&x,&y) == 2 ){
            if( x == 0 ) break;
            d[x][y] = 1;
        }
        int ans = 0 , n = 0;
        for(int k = 1 ; k <= 100 ; k++)
            for(int i = 1 ; i <= 100 ; i++)
                for(int j = 1 ; j <= 100 ; j++)
                    d[i][j] = min( d[i][j] , d[i][k] + d[k][j] );
        
        for(int i = 1 ; i <= 100 ; i++)
            for(int j = 1 ; j <= 100 ; j++)if( i != j )
                if( d[i][j] != inf ) ans += d[i][j] , n++;
        //cout << ans << " " << n << endl;
        printf("Case %d: average length between pages = %.3lf clicks\n", ++test , 1.0 * ans / n );
    }
    return 0;
}
