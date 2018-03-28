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
#define N 55

int n , k , T ;
ll t[N][N][2];

ll f(int x,int y,int last){
    if( x == n )
        return ((y==k&&last==0)?1:0);
    
    ll &ret = t[x][y][last];
    if( ret != -1 ) return ret;
    ret = 0;
    if( y < k ){
        for(int i = x ; i <= min( x + T - 1 , n - 1 ) ; i++)
            ret += f( i + 1 , y + 1 , last^1 );
    }
    return ret;
}

int main(){
    while( scanf("%d%d%d",&n,&k,&T) == 3 ){
        me(t,-1);
        ll ans = 0;
        for(int i = 0 ; i < min( T , n ) ; i++)
            ans += f( i + 1 , 1 , 1 ) + f( i + 1 , 1 , 0 );
        printf("%lld\n",ans);
    }
    return 0;
}
