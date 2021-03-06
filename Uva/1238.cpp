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
#define ios ios::sync_with_stdio(0);
#define N 100001

double f(double d,double D){
    double r = d / 2;
    double R = D / 2;
    double h = (D - d)/2;
    return (pi * h * ( R * R + r * r + R * r ) ) / 3;
}

int main(){
    double D , V;
    while( scanf("%lf%lf",&D,&V) == 2 ){
        if( D == 0 and V == 0 ) break;
        double ans = pow( D * D * D - 6 * V /pi  , 1.0/3.0 );
        
        printf("%.3lf\n",ans);
    }
    return 0;
}
