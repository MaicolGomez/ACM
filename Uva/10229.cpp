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
#define N 20

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


ll pot[2*N+2];

int main(){
    pot[0] = 1;
    for(int i = 1 ; i <= 20 ; i++)
        pot[i] = pot[i-1]*2;
        
    int a , b;
    while( scanf("%d%d",&a,&b) == 2 ){
        MOD = pot[b];
        if( a == 0 ) printf("0\n");
        else if( a == 1 ) printf("1\n");
        else{
            Mat x(2);
            x.m[1][1] = 1 , x.m[1][2] = 1 , x.m[2][1] = 1 , x.m[2][2] = 0;
            x = x.fastpow( x , a - 1 );
            printf("%lld\n", x.m[1][1] );
        }
    }
    return 0;
}
