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
#define N 2002

char s[N][N];
vi adj[N];
int d[N];
bool vis[N];

int main(){
    int R , C;
    while( scanf("%d%d",&R,&C) == 2 ){
        
        
        for(int i = 0 ; i < R + C ; i++)
            adj[i].clear();
            
        for(int i = 0 ; i < R ; i++){
            scanf("%s",s[i]);
            for(int j = 0 ; j < C ; j++){
                if( s[i][j] == '#' ){
                    adj[ i ].pb( j + R );
                    adj[ j + R ].pb( i );
                }
            }
        }
        
        fill( d , d + (R+C) , inf );
        queue<int> Q;
        Q.push( 0 );
        d[0] = 0;
        while( !Q.empty() ){
            int u = Q.front(); Q.pop();
            if( vis[u] ) continue;
            vis[u] = 1;
            if( u == R - 1 ) break;
            for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
                int v = adj[u][i];
                if( d[v] > d[u] + 1 ){
                    d[v] = d[u] + 1;
                    Q.push( v );
                }
            }
        }
        if( vis[R-1] ) cout << d[R-1] << '\n';
        else cout << "-1\n";
        
        
    }
    return 0;
}
