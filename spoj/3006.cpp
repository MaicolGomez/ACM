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
#define N 15

int n;
pair<double , double> A[2][N];
double t[1<<N][N][2];

double dis(int i,int k1,int j,int k2){
    return sqrt( Q( A[k1][i].fi - A[k2][j].fi ) + Q( A[k1][i].se - A[k2][j].se ) );
}

double f(int mask,int last,int k){
    if( mask == 0 ) return 0;
    if( t[mask][last][k] > -0.5 ) return t[mask][last][k];
    double ret = 1e10;
    for(int i = 0 ; i < n ; i++)if( mask&(1<<i) ){
        ret = min( ret , dis( last , k , i , 0 ) + f( mask^(1<<i) , i , 1 ) );
        ret = min( ret , dis( last , k , i , 1 ) + f( mask^(1<<i) , i , 0 ) );
    }
    return t[mask][last][k] = ret;
}

int main(){
    int test = 1;
    while( ~sc(n) and n ){
        double cons = 0;
        for(int i = 0 ; i < n ; i++){
            scanf("%lf%lf%lf%lf",&A[0][i].fi,&A[0][i].se,&A[1][i].fi,&A[1][i].se);
            cons += dis( i , 0 , i , 1 );
        }
        for(int i = 0 ; i < 1<<n ; i++)
            for(int k = 0 ; k < n ; k++)
                for(int j = 0 ; j < 2 ; j++)
                    t[i][k][j] = -1.0;
                    
        double ans = 1e10;
        int x = (1<<n) - 1;
        for(int i = 0 ; i < n ; i++)
            ans = min( ans , min( f( x^(1<<i) , i , 0 ) , f( x^(1<<i) , i , 1 ) ) );
        
        printf("Case %d: %.5lf\n",test++, ans + cons );
    }
    return 0;
}
