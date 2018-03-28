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
#define N 101

bool c[N][N];
ll t[1<<19][20];
int n , m;

ll f(int mask,int cur,int start){
    ll &ret = t[mask][cur];
    if( ret != -1 ) return ret;
    ret = 0;
    if( c[cur][start] ) ret = 1;
    
    for(int i = start + 1 ; i < n ; i++)if( !(mask&(1<<i)) and c[cur][i] )
        ret += f( mask|(1<<i) , i , start );
    
    return ret;
}

int main(){
    while( scanf("%d%d",&n,&m) == 2 ){
        me(c,0);
        int a , b;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&a,&b); a--,b--;
            c[a][b] = c[b][a] = 1;
        }
        ll ans = 0;
        for(int i = 0 ; i < n ; i++){
            me(t,-1);
            for(int j = i + 1 ; j < n ; j++)
                for(int k = i + 1 ; k < n ; k++)if( j != k and c[i][j] and c[j][k] ){
                   ans += f( (1<<i)|(1<<j)|(1<<k) , k , i );
                }
        }
        cout << ans / 2 << "\n";
    }   
    return 0;
}
