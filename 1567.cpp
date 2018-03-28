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
#define eps 1e-7
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

Point operator-(Point A,Point B){ return Point(A.x - B.x,A.y - B.y); }
Point operator+(Point A,Point B){ return Point(A.x + B.x,A.y + B.y); }
Point operator*(double s,Point A){ return Point( s * A.x , s * A.y ); }
double cross(Point A,Point B){ return A.x * B.y - A.y * B.x; }
double dot(Point A,Point B){ return A.x * B.x + A.y * B.y; }

Point lineIntersetion(Point A,Point B,Point C,Point D){
    double s = ( dot( (C - A) , (D - C).ort() ) / dot( (B - A) , (D - C).ort() ) );
    //cout << s << " " << (B-A).x << " " << (B - A).y << endl;
    return A + s * (B - A);
}

int main(){
    printf("INTERSECTING LINES OUTPUT\n");
    int tc;
    sc(tc);
    while( tc-- ){
        Point P[4];
        for(int i = 0 ; i < 4 ; i++)
            P[i].read();
        
        if( abs( cross( P[1] - P[0] , P[3] - P[2] )  ) < eps ){
            if( abs( cross( P[1] - P[0] , P[2] - P[0] ) ) < eps )
                printf("LINE\n");
            else printf("NONE\n");
        }
        else{
            Point Q = lineIntersetion( P[0] , P[1] , P[2] , P[3] );
            printf("POINT %.2f %.2f\n",Q.x,Q.y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
