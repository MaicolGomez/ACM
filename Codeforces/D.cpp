#include<bits/stdc++.h>
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
#define N 1005

int x[N] , y[N] , z[N];
int p[N] , q[N] , r[N];

int main(){
    int n , m;
    while( cin >> n >> m ){
        for(int i = 0 ; i < n ; i++)
            cin >> x[i] >> y[i] >> z[i];
        
        for(int i = 0 ; i < m ; i++)
            cin >> p[i] >> q[i] >> r[i];
        
        int ans = 0;
        bool ok = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if( q[j] >= y[i] and q[j] <= y[i] + z[i] and x[i] >= p[j] and x[i] <= p[j] + r[j] ){
                    ok = 1;
                    int a = min( y[i] + z[i] - q[j] , q[j] - y[i] );
                    int b = min( p[j] + r[j] - x[i] , x[i] - p[j] );
                    a = min( a , b );
                    ans = max( ans , a );
                }
            }
        }
        if( !ok ) ans = 0;
        cout << ans << "\n";
    }
    return 0;
}
