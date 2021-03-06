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
#define N 100001

int a[N] , n;

int f(int i){
    int lo = i , hi = n - 1;
    if( a[n-1] <= 2 * a[lo] ) return 0;
    if( a[lo+1] > 2 * a[lo] ) return n - 1 - lo;
    while( lo + 1 < hi ){
        int mid = M(lo,hi);
        if( a[mid] <= 2 * a[i] ) lo = mid;
        else hi = mid;
    }
    //cout << i << " - " << lo << endl;
    return n - 1 - lo;
}

int main(){
    freopen( "input.txt" , "r" , stdin );
    freopen( "output.txt" , "w" , stdout );
    while( sc(n) == 1 ){
        for(int i = 0 ; i < n ; i++)
            sc(a[i]);
        
        sort( a , a + n );
        int ans = inf;
        for(int i = 0 ; i < n ; i++)
            ans = min( ans , i + f( i ) );
        cout << ans << endl;
    }
    return 0;
}
