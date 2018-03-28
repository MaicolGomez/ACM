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
#define MOD 1000000007
#define N 3

struct Mat{
    int n , m[N][N];
    Mat(){}
    Mat( int _n , bool ok = 1 ){
        me(m,0);
        n = _n;
        if(ok)
            for(int i = 0 ; i < n ; i++)
                m[i][i] = 1;
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

inline Mat operator*( Mat &A , Mat &B ){
    Mat X;
    X.n = A.n;
    for(int i = 0 ; i < A.n ; i++)
        for(int j = 0 ; j < A.n ; j++){
            ll temp = 0;
            for(int k = 0 ; k < A.n ; k++)
                temp += (ll)(A.m[i][k])*B.m[k][j]; // need define MOD
            X.m[i][j] = temp%MOD;
        }
    return X;
}

inline void fastpow( int m[3][3] , ll y ){
    if( y == 1 ) return;
    int P[N][N] , R[N][N];;
    me(P,0);
    for(int i = 0 ; i < N ; i++) P[i][i] = 1;
    while( y ){
        if(y & 1){
            //P = P * x;
            for(int i = 0 ; i < N ; i++)
                for(int j = 0 ; j < N ; j++){
                    ll temp = 0;
                        for(int k = 0 ; k < N ; k++)
                            temp += (ll)(P[i][k])*m[k][j]; // need define MOD
                    R[i][j] = temp%MOD;
                }
            memcpy(P,R,3*3*sizeof(int));
        }
        y >>= 1;
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++){
                ll temp = 0;
                for(int k = 0 ; k < N ; k++)
                    temp += (ll)(m[i][k])*m[k][j]; // need define MOD
                R[i][j] = temp%MOD;
            }
        memcpy( m , R,3*3*sizeof(int));
        //x = x * x;
    }
    memcpy( m,P,3*3*sizeof(int));
    return;
}

int main(){
    int tc;
    ll n;
    sc(tc);
    while( tc-- ){
        scl(n);
        if( n <= 1 ){
            if( n == 0 ) printf("0\n");
            else printf("2\n");
            continue;
        }
        int m[3][3];
        m[0][0] = 1 , m[0][1] = 2 , m[0][2] = 1;
        m[1][0] = 0 , m[1][1] = 5 , m[1][2] = 3; 
        m[2][0] = 0 , m[2][1] = 3 , m[2][2] = 2;
        fastpow( m , n - 1 );
        printf("%d\n", (2LL*m[0][0] + 5LL*m[0][1] + 3LL*m[0][2])%MOD );
    }
    return 0;
}
