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
#define N 505

int d[N][N] , R[N];
bool A[N];

char s[N];

int main(){
    int tc , n , m , x;
    sc(tc);
    int test = 0;
    while ( tc-- ){
        
        
        scanf("%d %d",&m,&n); gets( s );
        
        me(A,0);
        for(int i = 0 ; i < n + 1 ; i++)
            for(int j = 0 ; j < n + 1 ; j++)    
                d[i][j] = inf;
        
        for(int i = 0 ; i < n + 1 ; i++)
            d[i][i] = 0 , R[i] = inf;
    
        
        
        int x;
        for(int i = 0 ; i < m; i++){
            sscanf(gets(s),"%d\n",&x);
            A[x] = 1;
        }
        int u , v , w;
        while ( gets(s) ){
            if ( sscanf(s,"%d %d %d",&u,&v,&w) != 3 ) break;
            d[u][v] = d[v][u] = w;
        }
        
        for(int k = 1 ; k <= n ; k++)
            for(int i = 1 ; i <= n ; i++)
                for(int j = 1 ; j <= n ; j++)
                    d[i][j] = min( d[i][j] , d[i][k] + d[k][j] );
        
        for(int i = 1 ; i <= n ; i++)if( !A[i] ){
            for(int j = 1 ; j <= n ; j++)if( A[j] )
                R[i] = min( R[i] , d[i][j] );             
        }
        
        int temp = 0;
        for(int i = 1 ; i <= n ; i++)if( !A[i] )
            temp = max( temp , R[i] );
        
        int pos = 1;
        for(int i = 1 ; i <= n ; i++)if( !A[i] ){
            int h = 0;
            for(int j = 1 ; j <= n ; j++)if( j != i || !A[j] ){
                int dmin = inf;
                for(int k = 1 ; k <= n ; k++)if( k == i || A[k] )
                    dmin = min( dmin , d[j][k] );
                
                h = max( h , dmin );
            }
            
            if( h < temp ){
                temp = h;
                pos = i;
            }
        }
        printf("%d\n",pos);
        if(tc) printf("\n");
        
    }
    return 0;
}
