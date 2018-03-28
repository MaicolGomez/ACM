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
#define MOD1 1000000007
#define MOD2 1000000009
#define ios ios::sync_with_stdio(0)
#define N 100000

ll f(ll a,int b){
    if( b == 0 ) return 1;
    if( b&1 ) return a * f( a , b - 1 ) % MOD1;
    ll t = f( a , b / 2 );
    return t * t % MOD1;
}

int main(){
    ios;
    int k;
    string s;
    cin >> k >> s;
    
    ll A = 0 , B = 0 , pot1 = 1 , pot2 = 1 , inv = f( 27 , MOD1 - 2 );
    int ans = 0;
    for(int i = 0 ; i < k ; i++){
        A = A + pot1 * (s[i] - 'a' + 1);
        A %= MOD1;
        if( i != k - 1 )pot1 *= 27;
        pot1 %= MOD1;
        B = B * 27 + (s[i] - 'a' + 1);
        B %= MOD1;
    }
    if( A == B ) ans++;
    
    for(int i = k ; i < s.size() ; i++){
        B = (B - (s[i-k] - 'a' + 1) * pot1) * 27 + (s[i] - 'a' + 1);
        B %= MOD1;
        if( B < 0 or B >= MOD1 ) B = (B + MOD1)%MOD1;
        
        A = (A - (s[i-k] - 'a' + 1)) * inv + (s[i] - 'a' + 1) * pot1;
        A %= MOD1;
        if( A < 0 or A >= MOD1 ) A = (A + MOD1)%MOD1;
        if( A == B ) ans++;
    }
    
    cout << ans << "\n";
    
    return 0;
}
