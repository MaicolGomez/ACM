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

int MOD;

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
                    X.m[i][j] = (X.m[i][j] +  A.m[i][k] * m[k][j])%MOD;
                
        return X;
    }
    Mat fastpow( Mat x , int y ){
        if( y == 0 ) return Mat(x.n);
        if( y & 1 )
            return x * fastpow( x , y - 1 );
        Mat z = fastpow( x , y/2 );
        return  z * z;
    }
};

int F[N];

int main(){
    int n , d;
    while( scanf("%d%d%d",&d,&n,&MOD) == 3 ){
        if( MOD == 0 ) break;
        Mat X(d);
        me(X.m,0);
        for(int i = 1 ; i <= d ; i++)
            scl(X.m[1][i]);
        for(int i = 1 ; i <= d ; i++)
            sc(F[i]);
        
        for(int i = 2 ; i <= d ; i++)
            X.m[i][i-1] = 1;
        if( n <= d )
            printf("%d\n",F[n]%MOD);
        else{
            X = X.fastpow( X , n - d );
            ll ans = 0;
            for(int i = 1 ; i <= d ; i++)
                 ans += X.m[1][i] * F[d-i+1];
            printf("%lld\n",ans%MOD);
        }
    }
}

