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
#define N 105

struct Point{
    double x , y;
    Point(){}
    Point(double X,double Y){ x = X , y = Y; }
    void read(){
        scanf("%lf%lf",&x,&y);
    }
    void pri(){ cout << x << " -- " << y << "\n"; }
    double mod(){ return sqrt( x * x + y * y ); }
    Point ort(){ return Point( -y , x );  }
};

Point operator-(Point A,Point B){ return Point( A.x - B.x , A.y - B.y ); }
Point operator+(Point A,Point B){ return Point( A.x + B.x , A.y + B.y ); }
Point operator*(double k,Point A){ return Point( k * A.x , k * A.y  ); }
double dot(Point A,Point B){ return A.x * B.x + A.y * B.y; }
double cross(Point A,Point B){ return A.x * B.y - A.y * B.x; }


Point lineIntersection(Point A,Point B,Point C,Point D){
    double s = dot( C - A , (D - C).ort() ) / dot( B - A , (D - C).ort() );
    return A + s * (B - A);
}

Point P[N] , Q[N];
int n , m;

double drecta(Point A,Point B,Point C){
    Point X = lineIntersection( A , A + (C - B).ort() , B , C );
    if( min(C.x,B.x) <= X.x + eps and X.x <= max(C.x,B.x) + eps  and min(B.y,C.y) <= X.y + eps and X.y <= max(B.y,C.y) )
        return (A - X).mod();
    return 1e100;
}

void solve(){
    double ans = 1e20;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            ans = min( ans , (P[i] - Q[j]).mod() );
    
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)if( abs( cross( P[i] - Q[j] , P[i] - Q[(j+1)%m] ) ) > eps )
            ans = min( ans , drecta( P[i] , Q[j] , Q[(j+1)%m] ) );
        
        
    for(int i = 0 ; i < m ; i++)
        for(int j = 0 ; j < n ; j++)if( abs( cross( Q[i] - P[j] , Q[i] - P[(j+1)%n] ) ) > eps )
            ans = min( ans , drecta( Q[i] , P[j] , P[(j+1)%n] ) );
    
    printf("%.10lf\n",ans/2);
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        sc(n);
        for(int i = 0 ; i < n ; i++)
            P[i].read();
        sc(m);
        for(int i = 0 ; i < m ; i++)
            Q[i].read();
        solve();
    }
    return 0;
}
