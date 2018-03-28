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
#define N 1005

int n , x[N] , y[N] , t[N][2];

int f(int pos,int last){
    if( pos == n )
        return 0;
    int &ret = t[pos][last];
    if( ret != -1 ) return ret;
    if( last == 0 )
        ret = max( abs( y[pos-1] - y[pos] ) + x[pos] + f( pos + 1 , 0 ) , abs( y[pos-1] - x[pos] ) + y[pos] + f( pos + 1 , 1 ) );
    else
        ret = max( abs( x[pos-1] - y[pos] ) + x[pos] + f( pos + 1 , 0 ) , abs( x[pos-1] - x[pos] ) + y[pos] + f( pos + 1 , 1 ) );
    return ret;
}

int main(){
    while( sc(n) == 1 ){
        for(int i = 0 ; i < n ; i++)
            sc(x[i]) , sc(y[i]);
        
        me(t,-1);
        int ans = max( x[0] + f( 1 , 0 ) , y[0] + f( 1 , 1 ) );
        printf("%d\n",ans);
    }
    return 0;
}
