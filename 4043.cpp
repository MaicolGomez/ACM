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
#define ios ios::sync_with_stdio(0)

int M[10005];

int main(){
    int n , m;
    while( scanf("%d%d",&n,&m) == 2 ){
        int MOD = m;
        me(M,-1);
        M[0] = 0;
        int ans = 0 , S = 0 , x;
        for(int i = 1 ; i <= n ; i++){
            sc(x);
            S += x;
            S = (S%m + m)%m;
            if( M[S] != -1 )
                ans = max( ans , i - M[S] );
            else M[S] = i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
