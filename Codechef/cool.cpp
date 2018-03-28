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

ll H(ll n){
    ll r = (ll)sqrt( n ) , ans = 0 , g;
    for(int i = 1 ; i <= r ; i++){
        ans += n / i;
        g = n / i;
    }
    ll last = n;
    for(int i = 1 ; i < g ; i++){
        ll next = n/( i + 1 );
        ans += (last - next) * i;
        last = next;
    }
    return ans;
}

ll gcd(ll x,ll y){
    if( y == 0 ) return x;
    return gcd( y , x%y );
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        ll x;
        scl(x);
        ll n = H(x) , y = x * x;
        ll g = gcd( n , y );
        printf( "%lld/%lld\n", n / g , y / g );
    }
    return 0;
}
