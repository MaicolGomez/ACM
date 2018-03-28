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
#define N 32

int n , m , C[N] , cost[N][N] , in[N][N];
int t[N][N][1024];

int f(int x,int y,int life){
    if( x == n ) return 0;
    int &ret = t[x][y][life];
    if( ret != -1 ) return ret;
    ret = f( x + 1 , 0 , life );
    if( y == 0 )
        if( life >= C[x] ){
            ret = max( ret , f( x + (y + 1 == m) , (y + 1)%m , life - C[x] ) );
            if( life >= C[x] ){
                for(int i = 1 ; i * cost[x][y] + C[x] <= life ; i++)
                    ret = max( ret , in[x][y] * i + f( x + (y + 1 == m) , (y + 1)%m , life - cost[x][y] * i - C[x] ) );
            }
        }
    if( y > 0 ){
        ret = max( ret , f( x + (y + 1 == m) , (y + 1)%m , life ) );
        if( life >= cost[x][y] ){
            for(int i = 1 ; i * cost[x][y] <= life ; i++)
                    ret = max( ret , in[x][y] * i + f( x + (y + 1 == m) , (y + 1)%m , life - cost[x][y] * i ) );
        }
    }
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 0 ; i < n ; i++)
            sc(C[i]);
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                sc(cost[i][j]);
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                sc(in[i][j]);
    
        me(t,-1);
        printf("%d\n",f( 0 , 0 , k ));
    }
    return 0;
}
