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
#define MOD 10009
#define N 105

int t[N][N] , m[N][N];

int main(){
    int n;
    while( sc(n) && n ){
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                sc(m[i][j]);
        
        for(int i = 1 ; i <= n ; i++)
            t[n][i] = m[n][i];
        
        for(int i = n - 1 ; i >= 1 ; i--){
            for(int j = 1 ; j <= n ; j++)
                t[i][j] = m[i][j] + max( t[i+1][j-1] , max( t[i+1][j] , t[i+1][j+1] ) );
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i++)
            ans = max( ans , t[1][i] );
        
        printf("%d\n",ans);
    }
    return 0;
}
