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
#define N 1005

int n , m , k , a[N][N] , t[N] , M[N][12] , f[N] , p[N];

void pre(int r){
    for(int i = 0 ; i < m ; i++)
        M[i][0] = t[i];
    
    for(int j = 1 ; (1<<j) <= n ; j++)
        for(int i = 0 ; i + (1<<j) - 1 < n ; i++)
            if( M[i][j - 1] > M[i + (1 << (j - 1)) ][j - 1] )
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

int query(int x,int y){
    if( y >= m ){
        int a = x , b = m - 1;
        int c = y - m;
        int k = 1;
        int ans = -inf , ans2 = -inf;
        for( ; (1<<k) <= b - a + 1 ; k++)
        k--;
        if( M[a][k] >= M[b - (1<<k) + 1 ][k] ) ans = M[a][k];
        else ans = M[b - (1<<k) + 1 ][k];
        a = 0 , b = c;
        k = 1;
        for( ; (1<<k) <= b - a + 1 ; k++)
        k--;
        if( M[a][k] >= M[b - (1<<k) + 1 ][k] ) ans2 = M[a][k];
        else ans2 = M[b - (1<<k) + 1 ][k];
        return max( ans , ans2 );
    }
    else if( x < 0 ){
        int a = 0 , b = y;
        int k = 1;
        int ans = -inf , ans2 = -inf;
        for( ; (1<<k) <= b - a + 1 ; k++)
        k--;
        if( M[a][k] >= M[b - (1<<k) + 1 ][k] ) ans = M[a][k];
        else ans = M[b - (1<<k) + 1 ][k];
        a = m - 1 + x + 1 , b = m - 1;
        k = 1;
        for( ; (1<<k) <= b - a + 1 ; k++)
        k--;
        if( M[a][k] >= M[b - (1<<k) + 1 ][k] ) ans2 = M[a][k];
        else ans2 = M[b - (1<<k) + 1 ][k];
        return max( ans , ans2 );
    }
    else{
        int a = x , b = y;
        for( ; (1<<k) <= b - a + 1 ; k++)
        k--;
        if( M[a][k] >= M[b - (1<<k) + 1 ][k] ) return M[a][k];
        else return M[b - (1<<k) + 1 ][k];
    }
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        scanf("%d%d",&n,&m,&k);
        if( k >= m ) k = m;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                sc(a[i][j]);
        
        int best = -inf, pos = -1;
        for(int i = 0 ; i < m ; i++){
            t[i] = a[0][i];
            if( t[i] > best ) best = t[i] , pos = i;
        }
        if( n == 1 ) printf("%d %d\n",best , pos);
        else{
            int ans = -inf;
            for(int i = 1 ; i < n ; i++){
                pre( i - 1 );
                for(int j = 0 ; j < m ; j++)
                    f[i] = a[i][j] + max( query( j , j + k - 1 ) , query( j - k + 1 , j ) );
                
               ans = -inf;
                for(int j = 0 ; j < m ; j++){
                    t[i] = f[i];
                    if( t[i] > ans )
                        ans = t[i];
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
