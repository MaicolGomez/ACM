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
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 100005

int L[N] , R[N] , a[N];

int main(){
    int n;
    while( ~sc(n) and n ){
        for(int i = 0 ; i < n ; i++)
            sc(a[i]);
        
        L[0] = -1;
        for(int i = 1 ; i < n ; i++){
            L[ i ] = i - 1;
            while( L[i] != -1 and a[ L[i] ] >= a[ i ] ){
                L[i] = L[ L[i] ];
            }
        }
        R[n-1] = n;
        for(int i = n - 2 ; i >= 0 ; i--){
            R[i] = i + 1;
            while( R[i] != n and a[ R[i] ] >= a[ i ] ){
                R[i] = R[ R[i] ];
            }
        }
        ll ans = 0;
        for(int i = 0 ; i < n ; i++)
            ans = max( ans , ( 1LL * R[i] - L[i] - 1 ) * a[i] );
        
        printf("%lld\n",ans);
    }
    return 0;
}
