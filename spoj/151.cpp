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
#define inf (1<<28)
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
#define N 101

int n , t[N][1<<12] , c , d[N][N] , b;
pii work[12];

int f(int last,int mask){
    if( mask == 0 )
        return d[last][b];
    int &ret = t[last][mask];
    if( ret != -1 ) return ret;
    ret = inf;
    for(int i = 0 ; i < c ; i++)if( mask&(1<<i) )
        ret = min( ret , d[ last ][ work[i].fi ] + d[ work[i].fi ][ work[i].se ] + f( work[i].se , mask^(1<<i) ) );
    
    return ret;
}

int main(){
    int tc , r , x , y , di;
    sc(tc);
    while(tc--){
        sc(n),sc(r),sc(b);
        b--;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                d[i][j] = inf;
                
        for(int i = 0 ; i < n ; i++)
            d[i][i] = 0;     
        
        for(int i = 0 ; i < r ; i++){
            sc(x),sc(y),sc(di); x-- , y--;
            d[x][y] = d[y][x] = min( d[x][y] , di );
        }
        
        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    d[i][j] = min( d[i][j] , d[i][k] + d[k][j] );
        
        int z;
        sc(z);
        c = 0;
        for(int i = 0 ; i < z ; i++){
            sc(x),sc(y),sc(r); x--, y--;
            for(int j = 0 ; j < r ; j++)
                work[c++] = mp(x,y);
        }
        //me(t,-1);
        for(int i = 0 ; i < n ; i++)
            memset( t[i] , -1 , sizeof(int)*((1<<c)+2) );
        int ans = f( b , (1<<c) - 1 );
        printf("%d\n",ans);
    }
    return 0;
}
