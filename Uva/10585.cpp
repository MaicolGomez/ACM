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
        x = X,y = Y;
    }
    void read(){ scanf("%lf%lf",&x,&y); }
};

bool operator<( Point A,Point B ){ if( abs(A.x - B.x) > eps ) return A.x < B.x; return A.y < B.y; }
bool operator==(Point A,Point B){ return abs(A.x - B.x) < eps and abs(A.y - B.y) < eps; }
Point operator+(Point A,Point B){ return Point( A.x + B.x , A.y + B.y ); }
Point operator-(Point A,Point B){ return Point( A.x - B.x , A.y - B.y ); }
Point operator*(double s,Point A){ return Point( s * A.x , s * A.y ); }
Point operator/(Point A,double s){ return Point( A.x / s , A.y / s ); }

Point P[N];

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n;
        sc(n);
        set<Point> S;
        Point C( 0 , 0 );
        for(int i = 0 ; i < n ; i++){
            P[i].read();
            C = C + P[i];
            S.insert( P[i] );
        }
        C = C/n;
        bool ok = 1;
        for(int i = 0 ; ok and i < n ; i++){
            Point X = 2 * C - P[i];
            if( S.find( X ) == S.end() ) ok = 0;
        }
        if( ok ) printf("yes");
        else printf("no");
        printf("\n");
    }
    return 0;
}
