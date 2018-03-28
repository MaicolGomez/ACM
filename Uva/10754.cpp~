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
#define fi first
#define se second
#define N 30

ll MOD;

struct Mat{
    int n;
    ll m[N][N];
    Mat( int _n ){
        me(m,0);
        n = _n;
        for(int i = 1 ; i <= n ; i++)
            m[i][i] = 1;
    }
    Mat operator*( Mat A ){
        Mat X( A.n );
        me(X.m,0);
        for(int i = 1 ; i <= A.n ; i++)
            for(int j = 1 ; j <= A.n ; j++)
                for(int k = 1 ; k <= A.n ; k++)
                    X.m[i][j] = (X.m[i][j] +  A.m[i][k] %MOD * m[k][j]%MOD)%MOD;
                
        return X;
    }
    Mat fastpow( Mat x , ll y ){
        if( y == 0 ) return Mat(x.n);
        if( y & 1 )
            return x * fastpow( x , y - 1 );
        Mat z = fastpow( x , y/2 );
        return  z * z;
    }
};

ll power(ll x,ll y){
    if( y == 0 ) return 1;
    if( y&1 )
        return (x%MOD*power(x,y-1))%MOD;
    ll z = power(x , y/2);
    return (z*z)%MOD;
}

ll F[N];

int main(){
    ll d , tc;
    ll n;
    scl(tc);
    int test = 0;
    while( tc-- ){
        if(test++) printf("\n");
        scanf("%lld%lld%lld",&d,&MOD,&n); n++;
        Mat X(d+1);
        me(X.m,0);
        for(int i = 1 ; i <= d ; i++)
            scl(X.m[1][i]);
        X.m[1][d+1] = 1;
        
        for(int i = 1 ; i <= d + 1 ; i++)
            for(int j = 1 ; j <= d + 1 ; j++){
                X.m[i][j] %= MOD;
                if( X.m[i][j] < 0 ) X.m[i][j] += MOD;
            }
            
        scl(F[1]);
        F[1] %= MOD;
        while( F[1] < 0 ) F[1] += MOD;
        for(int i = 2 ; i <= d+1 ; i++){
            scl(F[i]);
            F[i] %= MOD;
            while( F[i] < 0 ) F[i] += MOD;
        }
        if( d == 0 ){
            printf("%lld\n", F[1] );
            continue;
        }
        
        for(int i = 2 ; i <= d ; i++)
            X.m[i][i-1] = 1;
        X.m[d+1][d+1] = 1;
        if( n <= d ){
            while( F[n+1] < 0 ) F[n+1] += MOD;
            printf("%lld\n",F[n+1]%MOD);
        }
        else{
            X = X.fastpow( X , n - d );
            ll ans = 0;
            for(int i = 1 ; i <= d + 1 ; i++)
                 ans += X.m[1][i] * F[d-i+2] , ans %= MOD;
                 
            while( ans < 0 ) ans += MOD;
            printf("%lld\n",ans%MOD);
        }
    }
}

