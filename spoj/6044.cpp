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
#define N 501

pii A[N];
int n;

double f(double x,double y){
    double best = 0;
    for(int i = 0 ; i < n ; i++)
        best = max( best , sqrt( Q(x - A[i].fi) + Q(y - A[i].se) ) );
    return best;
}

double TY(double x){
    double lo = 0 , hi = 1e4;
    int it = 50;
    while( it-- ){
        double y1 = lo + (hi - lo) / 3 , y2 = lo + 2 * (hi - lo) / 3;
        if( f( x , y1 ) > f( x , y2 ) ) lo = y1;
        else hi = y2;
    }
    return f( x , lo );
}

double TX(){
    double lo = 0 , hi = 1e4;
    int it = 50;
    while( it-- ){
        double x1 = lo + (hi - lo) / 3 , x2 = lo + 2 * (hi - lo) / 3;
        if( TY(x1) > TY(x2) ) lo = x1;
        else hi = x2;
    }
    return TY( lo );
}

int main(){
    sc(n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d%d",&A[i].fi,&A[i].se);
    
    
    printf("%.2lf\n", 2 * TX() );
    return 0;
}
