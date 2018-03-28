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
#define N 100005

int a[100] , d[100][N];
bool used[100][N];
int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , 1 , -1 };

int main(){
    freopen( "input.txt" , "r" , stdin );
    freopen( "output.txt" , "w" , stdout );
    int n;
    while( sc(n) == 1 ){
        for(int i = 0 ; i < n ; i++)
            sc(a[i]) , a[i]++;
        
        int r1 , c1 , r2 , c2;
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2); r1--,c1--,r2--,c2--;
        me(d,-1);
        me(used,0);
        d[r1][c1] = 0;
        queue< pii > Q;
        Q.push( mp( r1 , c1 ) );
        while( !Q.empty() ){
            pii q = Q.front(); Q.pop();
            int x = q.fi , y = q.se;
            if( used[x][y] ) continue;
            used[x][y] = 1;
            if( x == r2 && y == c2 ) break;
            for(int i = 0 ; i < 4 ; i++){
                int u = x + dx[i] , v = y + dy[i];
                if( dx[i] == 0 && 0 <= v && v < a[u] && d[u][v] == -1 ){
                    d[u][v] = d[x][y] + 1;
                    Q.push( mp( u , v ) );
                }
                else{
                    v = min( v , a[u] - 1 );
                    if( 0 <= v and d[u][v] == -1 ){
                        d[u][v] = d[x][y] + 1;
                        Q.push( mp(u,v) );
                    }
                }
            }
        }
        printf("%d\n",d[r2][c2]);
    }
    return 0;
}
