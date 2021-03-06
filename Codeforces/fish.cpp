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
#define N 18

int n ;
double p[N][N] ;
double t[1<<N];

double f(int mask){
    if( mask == (1<<n) - 1 ) return 1;
    double &ret = t[mask];
    if( ret > -0.5 ) return ret;
    int x = __builtin_popcount( mask ) + 1; //estado + revivido
    int tot = x * (x - 1) / 2;
    ret = 0.0;
    for(int i = 0 ; i < n ; i++)if( mask&(1<<i) )
        for(int j = 0 ; j < n ; j++)if( !(mask&(1<<j)) )
            ret += p[i][j] * f( mask^(1<<j) ) / tot;
    return ret;
}

int main(){
    while( sc(n) == 1 ){
        //cout << n << endl;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++){
                cin >> p[i][j];
                //cout << p[i][j] << " ";
            }
        for(int i = 0 ; i < 1<<n ; i++)
            t[i] = -1.0;
        for(int i = 0 ; i < n ; i++)
            printf("%.8lf ", f( (1<<i) ) );
        printf("\n");
    }
    return 0;
}
