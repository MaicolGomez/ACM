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
#define N 100005

ll a[N] , A[N] , B[N]; // Array and max and ACUMAX L -> R
ll C[N] , D[N]; //MIN L -> R

ll P[N] , Q[N]; //maximos  L <- R
ll R[N] , S[N]; //minimos  L <- R

int main(){
    int tc , n;
    sc(tc);
    while(tc--){
        sc(n);
        for(int i = 0 ; i < n ; i++)
            scl(a[i]);
        
        A[0] = a[0];  C[0] = a[0];
        B[0] = A[0];  D[0] = a[0];
        for(int i = 1 ; i < n ; i++){
            A[i] = max( a[i] , A[i-1] + a[i] );
            B[i] = max( A[i] , B[i-1] );
            C[i] = min( a[i] , C[i-1] + a[i] );
            D[i] = min( C[i] , D[i-1] );
        }
        
        P[n-1] = a[n-1]; R[n-1] = a[n-1];
        Q[n-1] = a[n-1]; S[n-1] = a[n-1];
        for(int i = n - 2 ; i >= 0 ; i--){
            P[i] = max( a[i] , P[i+1] + a[i] );
            Q[i] = max( P[i] , Q[i+1] );
            R[i] = min( a[i] , R[i+1] + a[i] );
            S[i] = min( R[i] , S[i+1] );
        }
        
        ll ans = -(1LL<<60);
        for(int i = 0 ; i < n - 1 ; i++){
            //cout << B[i] << " " << S[i+1] << " -- " << D[i] << " " << Q[i+1] << '\n';
            ans = max( ans , max( abs( B[i] - S[i+1] ) , abs( D[i] - Q[i+1] ) ) );
        }
        printf("%lld\n",ans);
        
    }
    return 0;
}
