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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define N 1005

int main(){
    int tc;
    sc(tc);
    while(tc--){
        int n;
        sc(n);
        vi v(n);
        int maxi = -1;
        for(int i = 0 ; i < n ; i++)
            sc(v[i]) , maxi = max( v[i] , maxi );
         
         sort(all(v));
         ll ans = 1;
         if( maxi < n ) printf("0\n");
         else{
            ans *= v[0];
            for(int i = 1 ; i < n ; i++){
                ans *= (v[i]-i);
                if( ans >= MOD ) ans %= MOD;
            }
            printf("%lld\n",ans);
         }
    }
    return 0;
}
