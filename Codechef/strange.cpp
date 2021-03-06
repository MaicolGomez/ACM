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
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 100001

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n , m;
        sc(n),sc(m);
        if( n == 1 or m == 1 ){
            printf("%d\n",max(n,m));
            continue; 
        }
        
        if( n >= m ){
            int g = __gcd( m - 1 , n - 1 );
            int a = (n - 1) / g , b = (m - 1) / g , c = (n - m)/g;
            int ans = min( (m-1) / b , (n-1)/a ) + 1;
            printf("%d\n",ans);
        }
        else{
            int g = __gcd( m - 1 , n - 1 );
            int a = (m - 1) / g , b = ( n - 1 ) / g , c = (m - n)/g;
            int ans = min( (n-1) / b , (m-1)/a ) + 1;
            printf("%d\n",ans);
        }
    }
    return 0;
}
