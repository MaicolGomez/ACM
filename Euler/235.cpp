#include<bits/stdc++.h>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf (1<<29)
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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0)
#define N 100000

long double f(long double mid){
    long double S = 0 , r = 1.0;
    for(int i = 1 ; i <= 5000 ; i++){
        S += (900 - 3 * i) * r;
        r *= mid;
    }
    return S;
}

int main(){
    long double lo = 0.01 , hi = 1.01;
    int it = 100000;
    printf("%.12lf %.12lf\n", double( f( 0.15 ) ) , double( f( 0.998999 ) ) );
    while( it-- ){
        long double mid = (lo + hi) / 2;
        if( f( mid ) > -6*1e11 ) lo = mid;
        else hi = mid;
        if( it == 0 ) printf("%.12lf %.12lf\n", double( f(mid) ) , double( mid ) );
    }
    return 0;
}
