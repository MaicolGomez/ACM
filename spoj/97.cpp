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
#define N 505

int t[N][N] , x[N] , y[N] , n;

int f(int pos,int w){
    if( pos == n )
        return 0;
    int &ret = t[pos][w];
    if( ret != -1 ) return ret;
    ret = f( pos + 1 , w );
    if( x[pos] <= w ) ret = max(ret , y[pos] + f( pos + 1 , w - x[pos] ) );
    return ret;
}

int main(){
    int w;
    while( scanf("%d%d",&w,&n) == 2 && n||w ){
        for(int i = 0 ; i < n ; i++)
            sc(x[i]),sc(y[i]);
            
        me(t,-1);
        int ans = 0 , P = 0;
        for(int i = 1 ; i <= w ; i++)
            if( f(0,i) > ans ){
                ans = f(0,i);
                P = i;
            }
        printf("%d %d\n",P,ans);
    }
    return 0;
}
