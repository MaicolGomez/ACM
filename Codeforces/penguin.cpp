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

int n , a[N] , d;

int f(int x){
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
        ans += abs( x - a[i] )/d;
    return ans;
}

int main(){
    int nn , m ;
    while( cin >> nn >> m >> d ){
        n = nn * m;
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        
        int last = a[0];
        bool ok = 1;
        for(int i = 1 ; i < n ; i++)
            if( (last - a[i])%d != 0 ) ok = 0;
        
        if( ok ){
            sort( a , a + n );
            int ans = min( f(a[0]) , f(a[n-1]) );
            int lo = 0 , hi = n - 1;
            while( lo + 1 < hi ){
                int mid = M( lo , hi );
                ans = min( ans , min( f(a[lo]) , f(a[lo+1]) ) );
                if( f( a[mid] ) <= f(a[mid+1]) ) lo = mid;
                else hi = mid;
            }
            cout << ans << '\n';
        }
        else cout << -1 << '\n';
        
    }
    return 0;
}
