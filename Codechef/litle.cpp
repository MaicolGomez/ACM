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
#define N 52

double t[N][1<<17];
int P[N] , A[N] , B[N] , n ;

double f(int x,int mask){
    if( x == n ) return 1.0;
    double &ret = t[x][mask];
    if( ret > -0.5 ) return ret;
    ret = 0;
    if( (mask&(1<<A[x])) == 0 and P[x] > 0 ) ret = 0.01 * P[x] * f( x + 1 , mask|(1<<A[x]) );
    if( (mask&(1<<B[x])) == 0 and 100 - P[x] > 0 ) ret += 0.01 * (100 - P[x]) * f( x + 1 , mask|(1<<B[x]) );
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        sc(n);
        for(int i = 0 ; i < n ; i++)
            scanf("%d%d%d",&P[i],&A[i],&B[i]);
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < 1<<17 ; j++)
                t[i][j] = -1.0;
        
        printf("%.10lf\n",f( 0 , 0 ));
        
    }
    return 0;
}
