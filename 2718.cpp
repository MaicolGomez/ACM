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
    ll n;
    while( scl(n) == 1 ){
        ll S = 0;
        vector< pair< int , pii > > v;
        for(ll i = 1 ; i <= min( 10000001LL , n ) ; i++){
            ll lo = i , hi = 10000001;
            while( lo + 1 < hi ){
                ll m = M(lo , hi);
                ll a = m , b = m + 1 , c = 2 * m + 1;
                if( a % 2 == 0 ) a /= 2;
                else if( b % 2 == 0 ) b /= 2;
                else c /= 2;
                if( a % 3 == 0 ) a /= 3;
                else if( b % 3 == 0 ) b /= 3;
                else c /= 3;
                
                if( a * b * c - S <= n ) lo = m;
                else hi = m;
            }
            ll a = lo , b = lo + 1 , c = 2 * lo + 1;
            if( a % 2 == 0 ) a /= 2;
            else if( b % 2 == 0 ) b /= 2;
            else c /= 2;
            if( a % 3 == 0 ) a /= 3;
            else if( b % 3 == 0 ) b /= 3;
            else c /= 3;
            if( a * b * c - S == n ) v.pb( mp( lo - i + 1 , mp( i , lo ) ) );
            S += i * i;
        }
        sort( all(v) );
        reverse( all(v) );
        printf("%d\n",(int)v.size());
        for(int i = 0 ; i < v.size() ; i++){
            printf("%d",v[i].fi );
            for(int j = v[i].se.fi ; j <= v[i].se.se ; j++)
                printf(" %d",j);
            printf("\n");
        }
    }
    return 0;
}
