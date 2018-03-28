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


#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

struct Point
{
    double x, y;
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    double mod2() { return x*x + y*y; }
    double mod()  { return sqrt(x*x + y*y); }
    double arg()  { return atan2(y, x); }
    Point ort()   { return Point(-y, x); }
    Point unit()  { double k = mod(); return Point(x/k, y/k); }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

bool operator ==(const Point &a, const Point &b)
{
    return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS;
}
bool operator !=(const Point &a, const Point &b)
{
    return !(a==b);
}
bool operator <(const Point &a, const Point &b)
{
    if(abs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y + EPS < b.y;
}

double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }
Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}

Point P[505];
double R[505];

int main(){
    int n;
    while( sc(n) == 1 and n ){
        Point C;
        scanf("%lf%lf", &C.x,&C.y);
        for(int i = 0 ; i < n ; i++)
            scanf("%lf%lf%lf",&P[i].x,&P[i].y,&R[i]);
        
        vector< pair<double ,double > > e;
        for(int i = 0 ; i < n ; i++){
            Vector c = C - P[i];
            double l = c.mod() , a = R[i];
            double b = sqrt( l*l - a*a );
            Vector x( (a * c.x + b * c.y)/c.mod2() , (a * c.y - b * c.x)/c.mod2() );
            Point aa = lineIntersection( C , P[i] + x.unit() * a , Point(0,0) , Point(1,0) );
            //cout << aa.x << " " << aa.y << endl;
            Vector xx( (a * c.x - b * c.y)/c.mod2() , (a * c.y + b * c.x)/c.mod2() );
            Point bb = lineIntersection( C , P[i] + xx.unit() * a , Point(0,0) , Point(1,0) );
            //cout << bb.x << " " << bb.y << endl;
            e.pb( mp( min(aa.x,bb.x) , max(aa.x,bb.x) ) );
        }
        sort( all(e) );
        double begin = e[0].fi  , end = e[0].se;
        for(int i = 1 ; i < e.size() ; i++){
            if( e[i].fi > end ){
                printf("%.2f %.2f\n",begin,end);
                begin = e[i].fi , end = e[i].se;
            }
            else end = max( end , e[i].se );
        }
        printf("%.2f %.2f\n",begin,end);
        
        printf("\n");
    }
    return 0;
}
