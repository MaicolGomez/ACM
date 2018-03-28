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

ll a[N];

int main(){
    int x ;
    ll y , n = 0;
    ll ans , S = 0;
    sc(x);
    for(int i = 0 ; i < x ; i++){
        scl(y);
        if( y < 0 ) a[n++] = y , S += -y;
    }
    ll F;
    scl(F);
    if( n == 0 ) printf("0\n");
    else{
        sort( a , a + n );
        reverse( a , a + n );
        ans = min( S , -a[n-1] * F );
        ll last = 0;
        for(int i = 0 ; i < n ; i++){
            if( -F * a[i] >= ans ) break;
            ans = min( ans , -F * a[i] + S - ( last - a[i] ) * (n - i) );
            S -= (last - a[i]) * (n - i);
            last = a[i];
        }
        cout << ans << "\n";
    }
    return 0;
}
