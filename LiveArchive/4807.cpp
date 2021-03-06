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
    Point ort(){ return Point( -y , x ); }
    void read(){
        scanf("%lf%lf",&x,&y);
    }
};

bool operator<(Point A,Point B){ if( abs( A.x - B.x ) > eps ) return A.x < B.x; return A.y < B.y; }
bool operator==(Point A,Point B){ return (abs(A.x - B.x) < eps and abs(A.y - B.y) < eps); }
Point operator-(Point A,Point B){ return Point( A.x - B.x , A.y - B.y ); }
Point operator+(Point A,Point B){ return Point( A.x + B.x , A.y + B.y ); }
Point operator*(double s,Point A){ return Point( s * A.x , s * A.y ); }
Point operator/(Point A,double s){ return Point( A.x / s , A.y / s ); }
double cross(Point A,Point B){ return A.x * B.y - A.y * B.x; }
double dot(Point A,Point B){ return A.x * B.x + A.y * B.y; }
Point liineIntersection(Point A,Point B,Point C,Point D){
    double s = dot( (C-A) , (D - C).ort() )/dot( (B-A) , (D - C).ort() );
    return A + s * ( B - A );
}

int main(){
    int n;
    while( sc(n) == 1 and n ){
        Point P[n];
        for(int i = 0 ; i < n ; i++)
            P[i].read();
        
        int ans = min( n , 2 );
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)if( i != j ){
                Point A[105];
                int r = 0;
                for(int k = 0 ; k < n ; k++)if( abs( cross( P[k] - P[i] , P[j] - P[i] ) ) > eps ){
                    Point X = (P[i] + P[j])/2;
                    Point Y = (P[i] + P[k])/2;
                    A[r++] = liineIntersection( X , X + (P[i] - P[j]).ort() , Y , Y + (P[i] - P[k]).ort() );
                }
                if( r == 0 ) continue;
                sort( A , A + r );
                int ct = 1 ;
                Point cur = A[0];
                for(int k = 1 ; k < r ; k++){
                    if( A[k] == cur ) ct++;
                    else{
                        ans = max( ans , ct + 2 );
                        cur = A[k];
                        ct = 1;
                    }
                }
                ans = max( ans , ct + 2 );
            }
        printf("%d\n",ans);
    }
    return 0;
}
