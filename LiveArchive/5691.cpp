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
#define N 700

int C[N][N] , A[N][N] , S , T;
bool vis[N];
char s[N][N];
int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , 1 , -1 };

bool dfs(int u){
    if( u == T ) return 1;
    if( vis[u] ) return 0;
    vis[u] = 1;
    for(int i = 0 ; i < T + 1 ; i++){
        if( C[u][i] and dfs( i ) ){
            C[u][i]--;
            C[i][u]++;
            return 1;
        }
    }
    return 0;
}

int maxFlow(){
    int flow = 0;
    me(vis,0);
    while( dfs( S ) ){
        flow++;
        me(vis,0);
    }
    return flow;
}

int main(){
    int tc , r , c , test = 1;
    sc(tc);
    while( tc-- ){
        int n;
        sc(n);
        r = n , c = n;
        int p = 0 , q = 0;
        for(int i = 0 ; i < r ; i++)
            for(int j = 0 ; j < c ; j++)
                if( (i+j) % 2 == 0 ) A[i][j] = p++;
                else A[i][j] = q++;
        
        for(int i = 0 ; i < r ; i++)
            scanf("%s",s[i]);
        
        me(C,0);
        S = p + q;
        T = S + 1;
        for(int i = 0 ; i < r ; i++)
            for(int j = 0 ; j < c ; j++)
                if( (i+j) % 2 == 0 and s[i][j] == '#' ){
                    C[ S ][ A[i][j] ] = 1;
                    for(int k = 0 ; k < 4 ; k++){
                        int u = i + dx[k] , v = j + dy[k];
                        if( u >= 0 and u < r and v >= 0 and v < c and s[u][v] == '#' ){
                            C[ A[i][j] ][ p + A[u][v] ] = 1;
                            C[ p + A[u][v] ][ T ] = 1;
                        }
                    }
                }
        int flow = maxFlow();
        printf("Case %d: %d\n", test++, flow );
    }
    return 0;
}
