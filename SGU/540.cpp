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
#define eps 1e-8
#define ll long long
#define inf (1<<30)
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
#define N 1000001

pair< double , int > A[N];
double X[N] , D[N] , G[N] , R[N];

int main(){
    int n , s , v11 , v22 , x , r , g , d;
    scanf("%d%d%d%d",&n,&s,&v11,&v22);
    double v1 = v11 , v2 = v22;
    int m = 0;
    for(int nn = 1 ; nn <= n ; nn++){
        scanf("%d%d%d%d",&x,&r,&g,&d);
        X[nn] = x;
        R[nn] = r;
        G[nn] = g;
        D[nn] = d;
        int last = d;
        for(int i = last ; i >= 0 ; i -= (g + r) ){
            int b = i , a = max( 0 , i - g );
            double down = ( 1.0 * s * a ) / x;
            double up = ( 1.0 * s * b ) / x;
            A[ m++ ] = mp( down , 0 );
            A[ m++ ] = mp( up , 1 );
            if( a == 0 ) break;
        }
        last = d + r;
        for(int i = last ; i <= s ; i += (g + r) ){
            int a = i , b = i + g;
            double down = ( 1.0 * s * a ) / x;
            double up = ( 1.0 * s * b ) / x;
            A[ m++ ] = mp( down , 0 );
            A[ m++ ] = mp( up , 1 );
        }
    }
    
    sort( A , A + m );
    int ans = 0 , maxi = 0 , dmax = 0;
    double velocity;
    for(int i = 0 ; i < m ; i++){
        if( A[i].se == 0 ){
            double vel = 1.0 * s / A[i].fi;
            if( ans + 1 > maxi and v1 <= vel and vel <= v2 ){
                maxi = ans + 1;
                velocity = vel;
            }
            else if( ans + 1 == maxi and v1 <= vel and vel <= v2 ){
                if( velocity < vel )
                    velocity = vel;
            }
            ans++;
        }
        else ans--;
    }
    printf("%.10lf\n", velocity );
    printf("%d\n",n - maxi);
    if( n == maxi ) return 0;
    bool space = 0;
    for(int i = 1 ; i <= n ; i++){
        double timer = X[i] / velocity;
        //cout << timer << endl;
        if( timer <= D[i] ){
            if( timer >= D[i] - G[i] ){}
            else{
                if( space )printf(" ");
                printf("%d",i);
                space = 1;
            }
        }
        else{
            timer -= D[i];
            int piso = (int)floor( timer / ( R[i] + G[i] ) );
            timer -= piso * ( R[i] + G[i] );
            //cout << timer << endl;
            if( timer <= R[i] - eps ){
                if( space ) printf(" ");
                printf("%d",i);
                space = 1;
            }
        }
    }
    if( space ) printf("\n");
    return 0;
}
