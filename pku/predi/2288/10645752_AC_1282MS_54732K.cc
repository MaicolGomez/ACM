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
#define inf (1LL<<60)
#define eps 1e-8
#define ll long long
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
#define N 15
#define mp(a,b) make_pair(a,b)

int cost[N] , con[N][N] , n;
ll t[1<<14][N][N] , ways[1<<14][14][14];

ll f(int mask, int x, int last){
    if( mask == (1<<n) - 1 ) {
        ways[mask][x][last] = 1;
        t[mask][x][last] = 0;
        return ways[mask][x][last];
    }
    if( ways[mask][x][last] != -1 ) return ways[mask][x][last];
    ll ret = 0 , mx = 0;
    for(int i = 0 ; i < n ; i++){
        if( (mask&(1<<i)) == 0 && ( x == 13 || con[x][i] ) ){
            ll val = cost[i];
            if( con[x][i] ) val += cost[i] * cost[x];
            if( con[i][last] ) val += cost[i] * cost[x] * cost[last];
            ll w = f( mask|(1<<i) , i , x );
            if( w > 0 && val + t[mask|(1<<i)][i][x] > mx ){
                mx = val + t[mask|(1<<i)][i][x];
                ret = w;
            }
            else if( w > 0 && val + t[mask|(1<<i)][i][x] == mx ){
                ret += w;
            }
        }
    }
    if( ret == 0 ) mx = 0;
    ways[mask][x][last] = ret;
    t[mask][x][last] = mx;
    return ret;
}

int main(){
    int tc , m , a , b;
    scanf("%d",&tc);
    for(int cas = 0 ; cas < tc ; cas++){
        scanf("%d%d",&n,&m);
        me( con , 0 );
        for(int i = 0 ; i < n ; i++) scanf("%d",&cost[i]);
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&a,&b); a-- , b--;
            con[a][b] = con[b][a] = 1;
        }
        me( t , 0 );
        me( ways , -1 );
        ll r = f( 0 , 13 , 13 );
        if( r % 2 == 0 )
            r /= 2;
        printf("%lld %lld\n", t[0][13][13] , r );
    }
}