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

char s[N][N];
int d[N][N];
int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , -1 , 1 };

int main(){
    int r , c;
    while( scanf("%d%d",&r,&c) == 2 and (r||c) ){
        for(int i = 0 ; i < r ; i++)
            scanf("%s",s[i]);
        
        int x1 , y1 , x2 , y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2); x1--,y1--,x2--,y2--;
        for(int i = 0 ; i < r ; i++)
            for(int j = 0 ; j < c ; j++)
                d[i][j] = inf;
        
        d[x1][y1] = 0;
        priority_queue< pair< int , pii > > Q;
        Q.push( mp( 0 , mp(x1,y1) ) );
        while( !Q.empty() ){
            pair< int , pii > q = Q.top(); Q.pop();
            int x = q.se.fi , y = q.se.se , di = -q.fi;
            for(int i = 0 ; i < 4 ; i++){
                int u = x + dx[i] , v = y + dy[i];
                if( u >= 0 and u < r and v >= 0 and v < c and d[u][v] == inf ){
                    int nd;
                    if( s[u][v] == 'X' ) nd = di;
                    else nd = di + 1;
                    d[u][v] = nd;
                    if( u == x2 and v == y2 ) goto xx;
                    Q.push( mp( -nd , mp( u , v ) ) );
                }
            }
        }
        xx:
        printf("%d\n",d[x2][y2]);
    }
    return 0;
}
