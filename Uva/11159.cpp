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
#define N 205

int S , T , nn;
int C[2*N+5][2*N+5] , A[N] , B[N];
bool vis[2*N+5];

int dfs(int u){
    if( u == T ) return 1;
    if( vis[u] ) return 0;
    vis[u] = 1;
    for(int i = 0 ; i < nn ; i++)
        if( C[u][i] and dfs( i ) ){
            C[u][i]--;
            C[i][u]++;
            return 1;
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
    int tc , test = 1;
    sc(tc);
    while( tc-- ){
        int n , m;
        me(C,0);
        sc(n);
        for(int i = 1 ; i <= n ; i++)
            sc(A[i]);
        sc(m);
        for(int j = 1 ; j <= m ; j++)
            sc(B[j]);
        
        S = 0 , T = n + m + 1;
        nn = T + 1;
        for(int i = 1 ; i < n + 1 ; i++){
            C[S][i] = 1;
            for(int j = 1 ; j < m + 1 ; j++){
                C[n + j][T] = 1;
                if( A[i] and B[j] % A[i] == 0 ) C[i][n + j] = 1;
                else if( A[i] == 0 and B[j] == 0 ) C[i][n + j] = 1;
            }
        }
        printf("Case %d: %d\n",test++,maxFlow());
    }
    return 0;
}
