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
#define ios ios::sync_with_stdio(0)
#define N 100000

double area(ll a,ll b,ll c){
    double s = a + b + c;
    s /= 2.0;
    return sqrt( s * (s - a) * (s - b) * (s - c) );
}

struct cosa{
    double x;
    cosa(double X){ x = X;}
};

bool operator<(cosa A,cosa B){ return A.x + eps < B.x; }

int main(){
    int n , tc;
    while( cin >> n ){
        map< cosa , int > m;
        double a , b , c;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> a >> b >> c;
            cosa x = cosa( area(a,b,c)/(a + b + c) );
            m[ x ]++;
            ans = max( ans , m[x] );
        }
        
        cout << ans << "\n";
    }
    return 0;
}
