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
#define MOD 10009
#define N 1005

double g , d , r;

double f(double R){
    double h = sqrt( g * g - Q( R - r ) );
    return pi * h *( R * R + R * r + r*r ) / 3;
}

int main(){
    freopen( "frustum.in" , "r" , stdin );
    freopen( "frustum.out" , "w" , stdout );
    while( cin >> g >> d ){
        d /= 2;
        r = d;
        double lo = d , hi = d + g;
        int it = 100;
        while(it--){
            double m1 = (2*lo + hi)/3 , m2 = (lo + 2*hi)/3;
            if( f( m1 ) < f( m2 ) )
                lo = m1;
            else hi = m2;
        }
        
        printf("%.12lf\n",f(lo));
    }
    return 0;
}
