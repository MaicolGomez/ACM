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
#define N 102

struct Mat{
    int n;
    int m[N][N];
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
                    X.m[i][j] |= A.m[i][k] & m[k][j]; // need define MOD
                
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

int main(){
    int C , L ,  a , b;
    while( scanf("%d%d",&C,&L) == 2 && (C||L) ){
        Mat X( C , 0 );
        for(int i = 0 ; i < L ; i++){
            sc(a),sc(b); a--,b--;
            X.m[a][b] = X.m[b][a] = 1;
        }
        int s , f , d;
        sc(s),sc(f),sc(d); s--,f--;
        X = X.fastpow( X , d );
        if( X.m[s][f] ) printf("Yes, Teobaldo can travel.\n");
        else printf("No, Teobaldo can not travel.\n");
    }
    return 0;
}
