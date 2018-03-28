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
#define MOD 1000
#define N 55

struct Mat{
    int n;
    int m[N][N];
    Mat( int _n ){
        me(m,0);
        n = _n;
        for(int i = 0 ; i < n ; i++)
            m[i][i] = 1;
    }
    void clean(){
        me(m,0);
    }
    Mat operator*( Mat A ){
        Mat X( A.n );
        X.clean();
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
                cout << m[i][j] << "";
            puts("");
        }
    }
};

int A[N];
int main(){
    int tc , n , p;
    sc(tc);
    while( tc-- ){
        sc(n),sc(p);
        for(int i = 0 ; i < n ; i++)
            sc(A[i]) , A[i] %= MOD;
        Mat X(n);
        X.clean();
        int c;
        for(int i = 0 ; i < n ; i++){
            sc(c);
            for(int k , j = 0 ; j < c ; j++){
                sc(k);
                X.m[i][k] = 1;
            }
        }
        X = X.fastpow( X , p );
        for(int i = 0 ; i < n ; i++){
            if( i ) printf(" ");
            int ans = 0;
            for(int j = 0 ; j < n ; j++){
                ans += X.m[i][j] * A[j];
                ans %= MOD;
            }
            printf("%d",ans);
        }
        printf("\n");
    }
    return 0;
}
