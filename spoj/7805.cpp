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
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 100001

int n;
double W , L , x[20] , y[20];

double h(int a,int b){
    double ans = 1e20;
    double x1 = -x[a] , y1 = y[a];
    //cout << x[a] << " " << y[a] << " --> " << x1 << " " << y1 << endl;
    ans = min( ans , sqrt( Q( y[b] - y1 ) + Q( x[b] - x1 ) ) );
    x1 = 2 * W - x[a] , y1 = y[a];
    //cout << x[a] << " " << y[a] << " --> " << x1 << " " << y1 << endl;
    ans = min( ans , sqrt( Q( y[b] - y1 ) + Q( x[b] - x1 ) ) );
    
    y1 = -y[a] , x1 = x[a];
    ans = min( ans , sqrt( Q( y[b] - y1 ) + Q( x[b] - x1 ) ) );
    y1 = 2 * L - y[a], x1 = x[a];
    ans = min( ans , sqrt( Q( y[b] - y1 ) + Q( x[b] - x1 ) ) );
    return ans;
}

double t[1<<18][18];
double D[20][20] , R[20];

double g(int a){
    return min( x[a] , min( W - x[a] , min( y[a] , L - y[a] ) ) );
}

double f(int mask,int last){
    if( mask == 0 ) return R[last];
    double &ret = t[mask][last];
    if( ret > -0.5 ) return ret;
    ret = 1e30;
    for(int i = 0 ; i < n ; i++)if( mask&(1<<i) )
        ret = min( ret , D[last][i] + f( mask^(1<<i) , i ) );
    
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while(tc--){
        scanf("%lf%lf",&W,&L);
        sc(n);
        for(int i = 0 ; i < n ; i++)
            scanf("%lf%lf",&x[i],&y[i]);
        
        double a , b;
        scanf("%lf%lf",&a,&b);
        for(int i = 0 ; i < n ; i++)
            for(int j = i+1 ; j < n ; j++)
                D[i][j] = D[j][i] = h( i , j );
       
        //cout << D[0][1] << " " << D[1][0] << endl;
        for(int i = 0 ; i < n ; i++)
            R[i] = g( i );
        
        for(int i = 0 ; i < 1<< n ; i++)
            for(int j = 0 ; j < n ; j++)
                t[i][j] = -1.0;
        
        double ans = 1e30;
        for(int i = 0 ; i < n ; i++)
            ans = min( ans , sqrt( Q(x[i] - a) + Q(y[i] - b) ) + f( ((1<<n)-1)^(1<<i) , i ) );
        
        printf("%.8lf\n",ans);
        
    }
    return 0;
}
