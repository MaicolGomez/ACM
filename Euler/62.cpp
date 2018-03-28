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
    for(ll i = 5000 ; i <= 10000 ; i++){
        ll x = i * i * i;
        vi v;
        while( x > 0 ){
            v.pb( x % 10 );
            x /= 10;
        }
        sort( all(v) );
        int t = 0;
        do{
            if( v[0] == 0 ) continue;
            ll r = 0;
            for(int j = 0 ; j < v.size() ; j++)
                r = r * 10 + v[j];
            
            ll s = (ll)( pow( r , 1.0/3 ) );
            for(ll k = s - 1 ; k <= s + 1 ; k++)
                if( k * k * k == r ){ t++; break; }
            
        }while( next_permutation( all(v) ) );
        
        if( t == 3 ) cout << i << " " << i*i*i << "\n";
        if( t == 4 ) cout << " --> " << i << " " << i*i*i<< "\n";
        if( t == 5 ) cout << " --> 2 " << i << " " << i*i*i<< "\n";
    }
    
    return 0;
}
