#include<bits/stdc++.h>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-5
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
#define ios ios::sync_with_stdio(0)

struct Point{
    double x , y;
    Point(){}
    Point(double X,double Y){ x = X , y = Y; }
    void get(){ cin >> x >> y; }
};

Point operator-(Point A,Point B){ return Point( A.x - B.x , A.y - B.y ); }

double cross(Point A,Point B){ return A.x * B.y - A.y * B.x; }

double area(Point A,Point B,Point C){
    return abs( cross( A - B , C - A ) );
}

int main(){
    int ans = 0;
    Point O( 0 , 0 ) , A , B , C;
    string s;
    for(int i = 0 ; i < 1000 ; i++){
        cin >> s;
        for(int j = 0 ; j < s.size() ; j++)
            if( s[j] == ',' ) s[j] = ' ';
        stringstream in(s);
        in >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
        double S = area( A , B , C );
        if( i < 5 ) cout << S << " " << area( A , O , B ) - area( A , O , C ) - area( B , O , C ) << endl;
        if( abs( S - area( A , O , B ) - area( A , O , C ) - area( B , O , C ) ) < eps ) ans++;
    }
    cout << ans << endl;
    return 0;
}
