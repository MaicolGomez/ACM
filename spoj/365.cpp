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
#define N 205

int n , x[N] , y[N] , t[3*N][3*N];

int f(int w,int h){
    if( w == 0 || h == 0 )
        return 0;
    int &ret = t[w][h];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = 0 ; i < n ; i++)
        if( x[i] <= w && y[i] <= h ){
            ret = max( ret , x[i] * y[i] + f( w - x[i] , y[i] ) + f( w , h - y[i] ) );
            ret = max( ret , x[i] * y[i] + f( w - x[i] , h ) + f( x[i] , h - y[i] ) );
        }
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int w , h;
        sc(w),sc(h);
        sc(n);
        me(t,-1);
        for(int i = 0 ; i < n ; i++)
            scanf("%d%d",&x[i],&y[i]) , t[x[i]][y[i]] = x[i] * y[i];
            
        int ans = w * h - f( w , h );
        printf("%d\n",ans);
    }
    return 0;
}

