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
#define ios ios::sync_with_stdio(0)
#define N 100000

int main(){
    int test = 0 , n , q;
    while( scanf("%d%d",&n,&q) == 2 and (n||q) ){
        if( test++ ) printf("\n");
        vector< pair< ll , ll > > P( n );
        for(int i = 0 ; i < n ; i++)
            scanf("%lld%lld",&P[i].fi,&P[i].se);
        
        vll S( n , 0 );
        ll T = 0;
        for(int i = 1 ; i < n ; i++){
            S[i] = S[i-1] + P[i-1].fi * P[i].se - P[i].fi * P[i-1].se;
            T += P[i-1].fi * P[i].se - P[i].fi * P[i-1].se;
        }
        T += P[n-1].fi * P[0].se - P[0].fi * P[n-1].se;
        T = abs( T );
        int a , b;
        while( q-- ){
            scanf("%d%d",&a,&b);
            ll A = S[b] - S[a];
            A += P[b].fi * P[a].se - P[b].se * P[a].fi;
            A = abs( A );
            ll B = T - A;
            ll ans = A;
            if( A > B ) ans = B;
            printf("%lld",ans/2);
            if( ans % 2 == 0 ) printf(".0\n");
            else printf(".5\n");
        }
        
    }
    return 0;
}
