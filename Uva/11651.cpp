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
#define N 120

ll MOD;

struct Mat{
    int n;
    unsigned int m[N][N];
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
                    X.m[i][j] = (X.m[i][j] +  A.m[i][k] * m[k][j]);
                
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

Mat f( int b ){
    if( b == 2 ){
        Mat X( 2 );
        X.clean();
        X.m[0][1] = X.m[1][0] = 1;
        //X.print();
        return X;
    }
    Mat X( 110 );
    X.clean();
    int size = b;
    for(int i = 0 ; i < b ; i++)
        for(int j = 0 ; j < b ; j++)
            if( abs(i-j) == 1 ) X.m[i][j] = 1;
    
    int last = b;
    for(int i = 0 ; i < b ; i++){
        int r = max( Q( b-1-i ) , Q( i ) );
        if( r <= 1 ) continue;
        X.m[i][last] = 1;
        size += r - 1;
        for(int j = last ; j < last + r - 1 ; j++){
            int d = j - last + 1;
            if( j < last + r - 2 ) X.m[j][j+1] = 1;
            if( d == 3 ){
                if( i + 2 < b ) X.m[j][i+2] = 1;
                if( i - 2 >= 0 ) X.m[j][i-2] = 1;
            }
            if( d == 8 ){
                if( i + 3 < b ) X.m[j][i+3] = 1;
                if( i - 3 >= 0 ) X.m[j][i-3] = 1;
            }
            if( d == 15 ){
                if( i + 4 < b ) X.m[j][i+4] = 1;
                if( i - 4 >= 0 ) X.m[j][i-4] = 1;
            }
            if( d == 24 ){
                if( i + 5 < b ) X.m[j][i+5] = 1;
                if( i - 5 >= 0 ) X.m[j][i-5] = 1;
            }
        }
        last = last + r - 1;
    }
    X.resize( size );
    return X;
}

int main(){
    int tc , test = 0;
    int p , b;
    sc(tc);
    while(tc--){
        sc(b),sc(p);
        Mat x = f( b );
        x = x.fastpow( x , p );
        unsigned int ans = 0;
        for(int i = 1 ; i < b ; i++)
            for(int j = 0 ; j < b ; j++)
                ans = (ans + x.m[i][j]);
        
        printf("Case %d: ",++test);
        cout << ans << "\n";
    }
    return 0;
}
