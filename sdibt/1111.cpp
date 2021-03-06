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

struct Point{
    double x , y;
    Point(){}
    Point(double X,double Y){
        x = X , y = Y;
    }
    double mod(){ return sqrt( Q(x) + Q(y) ); }
    Point ort(){ return Point(-y , x); }
    void read(){ scanf("%lf%lf",&x,&y); }
};

Point operator-(Point A,Point B){ return Point( A.x - B.x , A.y - B.y ); }
Point operator+(Point A,Point B){ return Point( A.x + B.x , A.y + B.y ); }
Point operator*(double s,Point A){ return Point( s * A.x , s * A.y ); }
double dis(Point A,Point B){ return sqrt( Q(A.x - B.x) +  Q(A.y - B.y) ); }
double cross(Point A,Point B){ return A.x * B.y - A.y * B.y; }
double dot(Point A,Point B){ return A.x * B.x + A.y * B.y; }
Point lineIntersection(Point A,Point B,Point C,Point D){
    double s = ( dot( C - A , (D - C).ort() ) / dot( B - A , (D - C).ort() ) );
    return A + s * ( B - A );
}
bool in(Point A,Point B,Point C){
    return min( A.x , B.x ) - eps <= C.x and C.x <= max( A.x , B.x ) + eps and min( A.y , B.y ) - eps <= C.y and C.y <= max( A.y , B.y );
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        Point A , B , O( 0 , 0 );
        A.read(), B.read();
        double R;
        scanf("%lf",&R);
        Point C = lineIntersection( Point(0 , 0) , Point(0 , 0) + (B-A).ort() , A , B );
        if( C.mod() < R and in( A , B , C ) ){
            double d1 = (Point(0,0) - A).mod() , d2 = (Point(0,0) - B).mod();
            double c = (A - B).mod();
            double alfa = acos( R / d1 ) , beta = acos( R / d2 ) , tita = acos( (Q(d1) + Q(d2) - Q(c))/( 2 * d1 * d2 ) );
            if( tita < 0 ) tita += 2 * pi;
            double angle = tita - alfa - beta;
            double ans = sqrt( d1 * d1 - R * R ) + sqrt( d2 * d2 - R * R );
            ans += angle * R;
            printf("%.3lf\n",ans);
        }
        else printf("%.3lf\n",dis( A , B ));
    }
    return 0;
}
