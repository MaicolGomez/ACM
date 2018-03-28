#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<sstream>
using namespace std;
#define inf (1<<29)
#define eps 1e-8
#define ll long long
#define vi vector<int>
#define all(v) v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define fi first
#define se second
#define L(x) ((x<<1)+ 1)
#define R(x) L(x)+1
#define M(x,y) ((x+y)>>1)
#define N 100000
int MOD , B , P , n;

ll pot[N+5] , T[N+5] , inv , potinv[N+5] , A[N+5];

void update(int x,ll val){
    while( x <= n ){
        T[x] += val;
        if( T[x] >= MOD ) T[x] %= MOD;
        x += (x&-x);
    }
}

ll query(int x){
    ll ans = 0;
    while( x ){
        ans += T[x];
        x -= (x&-x);
        if( ans >= MOD ) ans %= MOD;
    }
    return ans%MOD;
}

ll fastpow( ll a , ll b ){
    if( b == 0 ) return 1;
    if( b&1 )
        return ( a*fastpow( a , b - 1 ) )%MOD;
    ll t = fastpow( a , b/2 )%MOD;
    return (t*t)%MOD;
}

int main(){
    int q ;
    ll x , y;
    pot[0] = potinv[0] = 1;
    while( scanf("%d%d%d%d",&B,&MOD,&n,&q) == 4 ){
        if( !B ) break;
        inv = fastpow( B%MOD , MOD - 2 );
        me(T,0);
        me(A,0);
        for(int i = 1 ; i <= n ; i++)
            pot[i] = (pot[i-1] * B) % MOD , potinv[i] = (potinv[i-1] * inv)%MOD; //fastpow( pot[i] , MOD - 2 );
        char s[2];
        while( q-- ){
            scanf("%s %lld %lld",&s,&x,&y);
            if( s[0] == 'E' ){
                update( x , ( (pot[n-x] * y + MOD)%MOD - A[x] + MOD)%MOD );
                A[x] = ( pot[n-x] * y + MOD )%MOD;
            }
            else printf("%lld\n",  ( ( (query( y ) - query( x-1 ) + MOD)% MOD) * potinv[n-y])%MOD );
        }
        printf("-\n");
    }
}
