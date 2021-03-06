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
#define inf INT_MAX
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
#define N 305

int d[N][N];

int main(){
    int n;
    while( sc(n) == 1 ){
        
        for(int i = 0 ; i < n ; i++)
            fill( d[i] , d[i] + n , inf );
            
        for(int i = 0 ; i < n ; i++)
            d[i][i] = 0;
            
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                sc(d[i][j]);
        
        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    d[i][j] = min( d[i][j] , d[i][k] + d[k][j] );
                
        int t;
        sc(t);
        vector< pair< pii , int > > v(t);
        for(int i = 0 ; i < t ; i++){
            sc(v[i].fi.fi),sc(v[i].fi.se),sc(v[i].se);
        }
        for(int r = 0 ; r < t ; r++){
            int a = v[r].fi.fi , b = v[r].fi.se , c = v[r].se; a--,b--;
            if( d[a][b] > c )
                d[a][b] = d[b][a] = c;
            
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    d[i][j] = min( d[i][j] , d[i][a] + d[a][j] );
            
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    d[i][j] = min( d[i][j] , d[i][b] + d[b][j] );
            
            ll S = 0;
            for(int i = 0 ; i < n ; i++)
                for(int j = i+1 ; j < n ; j++)
                    S += d[i][j];
            
            if( r ) printf(" ");
            printf("%lld",S);
        }
        printf("\n");
        
    }
    return 0;
}
