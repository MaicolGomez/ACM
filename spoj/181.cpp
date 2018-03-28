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

int t[N][25][82] , w , h , n , x[N] , y[N] , z[N];

int f(int pos,int b,int c){
    b = min( b , w ) , c = min( c , h );
    if( b >= w && c >= h )
        return 0;
    if( pos == n ) return inf;
    int &ret = t[pos][b][c];
    if( ret != -1 ) return ret;
    ret = min( f(pos + 1 , b , c ) , z[pos] + f( pos + 1 , b + x[pos] , c + y[pos] ) );
    return ret;
}


int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        sc(w),sc(h);
        sc(n);
        for(int i = 0 ; i < n ; i++)
            sc(x[i]),sc(y[i]),sc(z[i]) , me( t[i] , -1 );
        
        printf("%d\n",f(0,0,0));
    }
    return 0;
}
