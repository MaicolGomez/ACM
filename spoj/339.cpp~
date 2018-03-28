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
#define N 12
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

int main(){
    MOD = 1000000000LL;
    int tc , k , n;
    sc(tc);
    while(tc--){
        sc(k);
        Mat X(k,0);
        for(int i = 0 ; i < k ; i++)
            scl(F[i]) , F[i] %= MOD;
        
        for(int i = 0 ; i < k ; i++)
            scl( X.m[0][i] ) ,  X.m[0][i] %= MOD;
            
        for(int i = 1 ; i < k ; i++)
            X.m[i][i-1] = 1;
        
        sc(n) , scl(MOD);
        if( n <= k )
            printf("%lld\n" , F[n-1] );
        else{
            X = X.fastpow( X , n - k );
            ll ans = 0;
            for(int i = 0 ; i < k ; i++)
                ans = (ans + X.m[0][i] * F[ k - i - 1 ]  )%MOD;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
