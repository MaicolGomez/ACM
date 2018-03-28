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
#define ios ios::sync_with_stdio(0);
#define N 62
#define K 1000

int t[N][N][N] , m[N][N];
int d[N][N];


int main(){
    int c , n , q;
    while( scanf("%d%d%d",&n,&c,&q) == 3 ){
        
        for(int i = 0 ; i <= n ; i++)
            for(int j = 0 ; j < n ; j++)
                for(int k = 0 ; k < n ; k++){
                    if( j == k ) t[i][j][k] = 0;
                    else t[i][j][k] = inf;
                }
                    
        
        for(int ii = 0 ; ii < c ; ii++){
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    sc(d[i][j]);

                
            for(int k = 0 ; k < n ; k++)
                for(int i = 0 ; i < n ; i++)
                    for(int j = 0 ; j < n ; j++)
                        d[i][j] = min( d[i][j] , d[i][k] + d[k][j] );
            
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    t[0][i][j] = min( t[0][i][j] , d[i][j] );
        }
        
        for(int C = 1 ; C <= n ; C++){
            for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++){
                    t[C][i][j] = min( t[C-1][i][k] + t[0][k][j] , t[C][i][j] );
                }
        }
                
        int k , s , e;
        while( q-- ){
            scanf("%d%d%d",&s,&e,&k); s--,e--; k = min( k , n );
            printf("%d\n", t[k][s][e] );
        }
    }
    return 0;
}
