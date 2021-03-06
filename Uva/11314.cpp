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
#define ios ios::sync_with_stdio(0);
#define N 100001

double ax , ay , bx , by;

double f(double c , double d){
    return sqrt( Q(ax - bx) + Q(ay - by) ) + sqrt( Q(bx) + Q(by - c) ) + sqrt( Q(c) + Q(d) ) + sqrt( Q(ax - d) + Q(ay) );
}

double ternary(double dx){
    double lo = 0 , hi = 1e8;
    int i = 100;
    while( i-- ){
        double cx1 = lo + (hi - lo) / 3 , cx2 = lo + 2 * (hi - lo) / 3;
        if( f( cx1 , dx ) > f( cx2 , dx ) ) lo = cx1;
        else hi = cx2;
    }
    return f( lo , dx );
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        scanf("%lf%lf%lf%lf",&ax,&ay,&bx,&by);
        double lo = 0 , hi = 1e8;
        int it = 100;
        double best = 1e10;
        while( it-- ){
            double dx1 = lo + (hi - lo) / 3 , dx2 = lo + 2 * ( hi - lo ) / 3;
            double g1 = ternary( dx1 ) , g2 = ternary( dx2 );
            best = min( g1 , g2 );
            if( g1 > g2 ) lo = dx1;
            else hi = dx2;
        }
        printf("%.3lf\n",best);
    }
    return 0;
}
