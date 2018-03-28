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
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf (1<<30)
#define eps 1e-8
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mk(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define fi first
#define se second
#define N 105
#define mp(a,b) make_pair(a,b)

int n , a[N] , r;
double t[N][N] , v , b , f , e , S[N*N];

double g(int pos,int last){
    if( pos == n ) return 0.0;
    double &ret = t[pos][last];
    if( ret > -0.5 ) return ret;
    ret = 1e50;
    for(int i = pos + 1 ; i <= n ; i++){        
        double x = S[ a[i] - a[last] ];
        if( i == n) ret = min( ret , x + g( i , last )  );
        if( i != n ) ret = min( ret , b + x + g( i , i ) ); 
    }
    return ret;
}

int main(){
    while( sc(n) == 1 && n ){
        a[0] = 0;
        for(int i = 1 ; i <= n ; i++) sc(a[i]);
        scanf("%lf",&b);
        scanf("%d%lf%lf%lf",&r,&v,&e,&f);
        S[0] = 0.0;
        for(int i = 0 ; i <= a[n] + 2 ; i++){
            double t;
            if( i >= r ) t = 1.0 / ( v - e * (i - r) );
            else t = 1.0 / ( v - f * (r - i) );
            S[i+1] = S[i] + t;
        }
        for(int i = 0 ; i <= n+1 ; i++) fill_n( t[i] , n + 1 , -1.0 );
        printf("%.4lf\n", g( 0 , 0  ) );
    }
}
