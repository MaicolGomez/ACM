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
#define fi first
#define se second
#define MOD 10009
#define N 2005

int n , m;
ll t[N][N] , T[N][N] , S[N][N];

int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            scl(t[i][j]);
    
    int K = m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            T[i+j][i-j+K] = t[i][j];
    
    for(int i = 1 ; i <= n + m ; i++)
        for(int j = 1 ; j <= n + m ; j++)
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + T[i][j];
    
    int q , nx , r , ny , x , y;
    sc(q);
    while( q-- ){
        sc(nx) , sc(ny) , sc(r); nx++,ny++;
        x = nx + ny , y = nx - ny + K;
        int x1 = max( 1 , x - r ) , y1 = max( y - r , 1 );
        int x2 = min( n + m , x + r ) , y2 = min( n + m , y + r );
        
        ll ans = S[x2][y2] - S[x2][y1-1] - S[x1-1][y2] + S[x1-1][y1-1];
        
        printf("%lld\n",ans);
    }
    return 0;
}
