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
#define N 100
int n;
int t[N] , w[N] , dp[N][N*N+205];

int f(int x,int S){
    if( x == n ){
        if( S >= N*N ) return 0;
        return inf;
    }
    int &ret = dp[x][S];
    if( ret != -1 ) return ret;
    
    ret = t[x] + f( x + 1 , S + t[x] );
    ret = min( ret , f( x + 1 , S - w[x] ) );
    return ret;
}

int main(){
    while( cin >> n ){
        for(int i = 0 ; i < n ; i++)
            cin >> t[i] >> w[i];
        
        me(dp,-1);
        cout << f( 0 , N*N ) << '\n';
    }
    return 0;
}
