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
#define N 10

int MOD;

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
                    X.m[i][j] = (X.m[i][j] +  A.m[i][k] * m[k][j]);//%MOD; // need define MOD
                
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
                cout << m[i][j] << "";
            puts("");
        }
    }
};

int f(int x){
    if( x == 0 ) return 1;
    if( x&1 ) return 0;
    Mat X( 2 );
    X.m[0][0] = 4 , X.m[0][1] = MOD - 1;
    X.m[1][0] = 1 , X.m[1][1] = 0;
    int e = (x - 2)/2;
    X = X.fastpow( X , e );
    return ( X.m[0][0] * 3 + X.m[0][1] ) ;//%MOD;
}

int main(){
    int n;
    while( sc(n) == 1 and n != -1 ){
        printf("%d\n",f(n));
    }
}

