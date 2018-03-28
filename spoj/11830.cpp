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
#define ios ios::sync_with_stdio(0);
#define N 3

ll MOD;

struct Mat{
    int n;
    ll m[N][N];
    Mat( int _n , bool ok = 1 ){
        me(m,0);
        n = _n;
        if(ok)
            for(int i = 0 ; i < n ; i++)
                m[i][i] = 1;
    }
    Mat operator*( Mat A ){
        Mat X( A.n , 0 );
        for(int i = 0 ; i < A.n ; i++)
            for(int j = 0 ; j < A.n ; j++)
                for(int k = 0 ; k < A.n ; k++)
                    X.m[i][j] = (X.m[i][j] + A.m[i][k] * m[k][j] )%MOD; // need define MOD
                
        return X;
    }
    Mat fastpow( Mat x , ll y ){
        Mat P( x.n );
        while( y ){
            if(y & 1) P = P * x;
        
            y >>= 1;
            x = x * x;
        }
        return P;
    }
    void resize(int _n){
        n = _n;
    }
    void clean(){
        me(m,0);
    }
    void print(){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++)
                cout << m[i][j] << " ";
            puts("");
        }
    }
};

ll f(ll x){
    if( x == 0 ) return 1;
    if( x&1 ) return 0;
    Mat X( 2 );
    X.m[0][0] = 4 , X.m[0][1] = MOD - 1;
    X.m[1][0] = 1 , X.m[1][1] = 0;
    ll e = (x - 2)/2;
    X = X.fastpow( X , e );
    return ( X.m[0][0] * 3 + X.m[0][1] ) %MOD;
}

ll g(ll x){
    if( x < 1 ) return 0;
    if( x == 1 ) return 1;
    if( x % 2 == 0 ) return 0;
    Mat X(3);
    X.m[0][0] = 1 , X.m[0][1] = 1 , X.m[0][2] = 0;
    X.m[1][0] = 0 , X.m[1][1] = 4 , X.m[1][2] = MOD - 1;
    X.m[2][0] = 0 , X.m[2][1] = 1 , X.m[2][2] = 0;
    ll e = (x - 1)/2;
    X = X.fastpow( X , e );
    return ( X.m[0][0] + X.m[0][1] * 3  + X.m[0][2] )%MOD;
}

int main(){
    int n , m , x , y , tc;
    sc(tc);
    while( tc-- ){
        scanf("%d%d%d%d%lld",&n,&m,&x,&y,&MOD);
        if( n == 1 ){
            if( (y - 1)%2 == 0 and (m - y)%2 == 0 ) printf("%lld\n", 1LL%MOD );
            else printf("0\n");
        }
        else if( n == 2 or n == 4 ) printf("0\n");
        else{
            if( m % 2 == 0  ){
                printf("0\n");
                continue;
            }
            if( x == 1 or x == 3 ){
                ll s1 = f( y - 1 ) , s2 = f( m - y );
                ll g1 = g( y - 2 ) , g2 = g( m - y - 1 );
                printf("%lld\n", ( s1 * s2 + s1 * g2 + s2 * g1 ) % MOD );
            }
            else{
                ll g1 = g( y - 1 ) , g2 = g( m - y );
                printf("%lld\n", ( ((2 * g1)%MOD) * g2) %MOD );
            }
        }
    }
    return 0;
}
