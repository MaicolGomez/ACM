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
#define inf (1LL<<50)
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
#define N 100005

int n , a[N][3];
ll t[N][3];

ll f(int x,int y){
    if( y < 0 || y >= 3 ) return inf;
    if( x == n - 1 ){
        if( y == 0 ) return a[x][y] + a[x][y+1];
        if( y == 1 ) return a[x][y];
        return inf;
    }
    ll &ret = t[x][y];
    if( ret != -1 ) return ret;
    ret = f( x + 1 , y );
    ret = min( ret , f( x + 1 , y - 1 ) );
    ret = min( ret , f( x + 1 , y + 1 ) );
    ret = min( ret , f( x , y + 1 ) );
    ret += a[x][y];
    return ret;
}

int main(){
    int test = 1;
    while( sc(n) == 1 && n ){
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < 3 ; j++)
                sc(a[i][j]);
        
        for(int i = 0 ; i < n+2 ; i++)
            me(t[i],-1);
        printf("%d. %lld\n",test++,f(0,1));
    }
    return 0;
}
