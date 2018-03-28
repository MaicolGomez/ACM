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
#define N 17
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
    void clean(){
        me(m,0);
    }
    Mat operator*( Mat A ){
        Mat X( A.n , 0 );
        for(int i = 0 ; i < A.n ; i++)
            for(int j = 0 ; j < A.n ; j++)
                for(int k = 0 ; k < A.n ; k++)
                    X.m[i][j] = (X.m[i][j] +  A.m[i][k] * m[k][j])%MOD;
                
        return X;
    }
    void resize(int _n){
        n = _n;
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
    void print(){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++)
                cout << m[i][j] << " ";
            puts("");
        }
    }
};

ll F[N];
int k;
ll solve(Mat X , ll n){
    if( n <= k ){
        ll ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += F[i];
            if( ans >= MOD ) ans %= MOD;
        }
        return ans;
    }
    X = X.fastpow( X , n );
    ll ans = 0;
    for(int i = 0 ; i < X.n ; i++){
        ans += X.m[0][i] * F[ X.n - i - 1 ];
        if( ans >= MOD ) ans %= MOD;
    }
    return ans;
}

int main(){
    int tc;
    ll n , m;
    sc(tc);
    while(tc--){
        sc(k);
        Mat X(k+1,0);
        F[k] = 0;
        for(int i = k-1 ; i >= 0 ; i--)
            scl(F[i]);
        
        for(int i = k ; i >= 1 ; i--)
            scl( X.m[k][i] );
        
        X.m[0][0] = X.m[0][1] = 1;
        for(int i = 1 ; i < k ; i++)
            X.m[i][i+1] = 1;
        scl(n) , scl(m) , scl(MOD);
        for(int i = 0 ; i < X.n ; i++){
            F[i] %= MOD;
            for(int j = 0 ; j < X.n ; j++)
                X.m[i][j] %= MOD;
        }
        ll ans = ( solve( X , m ) - solve( X , n - 1 ) + MOD )%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
