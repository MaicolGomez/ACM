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

#define N 1005

int t[N][N] , MOD;

int f(int n,int mod){
    if( n == 1000 )
        return inf;
    if( mod == 0 )
        return n;
    int &ret = t[n][mod];
    if( ret != -1 ) return ret;
    ret = inf;
    for(int i = 0 ; i < 10 ; i++){
        int r = f( n + 1 , ( mod * 10 + i ) % MOD );
        if( r < ret ){
            ret = r;
        }
    }
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        sc(MOD);
        me(t,-1);
        int ans = inf;
        for(int i = 1 ; i < 10 ; i++)
            ans = min( ans , f( 1 , i%MOD ) );
        printf("%d\n",ans);
    }
    return 0;
}
