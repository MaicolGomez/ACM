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
#define N 20048

map<int,int> M;
int C , ncomp , comp[N];
ll X[N];
vi adj[N] , cost[N];
pair<ll,ll> T[N];

void clean(int m){
    M.clear();
    C = ncomp = 0;
    for(int i = 0 ; i < 2 * m ; i++)
        adj[i].clear() , cost[i].clear() , X[i] = inf;
    me( comp , - 1);
}

int insert(int x){
    if( M.find(x) == M.end() )
        M[x] = C++;
    return M[x];
}

void dfs(int u,int sig){
    comp[u] = ncomp;
    int nsig = sig * -1;
    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i] ;
        ll c = cost[u][i];
        if( comp[v] == -1 ){
            T[v].fi = c - T[u].fi , T[v].se = nsig;
            dfs( v , nsig );
        }
        else if( T[u].se == T[v].se ){
            if( u != v ) X[ ncomp ] = (c - T[u].fi - T[v].fi) / 2 * T[u].se;
            else X[ ncomp ] = (c - T[u].fi) * T[u].se;
            //else X[ ncomp ] = (T[u].fi + T[v].fi -  c)/2;
        }
    }
}

int main(){
    int q , m , x , y , z;
    while( scanf("%d%d",&m,&q) == 2 ){
        if( m == 0 && q == 0 ) break;
        clean( m );
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&x,&y,&z);
            x = insert( x );
            y = insert( y );
            adj[x].pb(y) , cost[x].pb(z);
            adj[y].pb(x) , cost[y].pb(z);
        }
        for(int i = 0 ; i < C ; i++)if( comp[i] == -1 ){
            T[i].fi = 0 , T[i].se = 1;
            dfs( i , 1 );
            ncomp++;
        }
        for(int i = 0 ; i < q ; i++){
            scanf("%d%d",&x,&y);
            if( M.find(x) == M.end() || M.find(y) == M.end() ){
                printf("*\n");continue;
            }
            x = M[x] , y = M[y];
            if( comp[x] != comp[y] ){
                if( X[ comp[x] ] == inf || X[ comp[y] ] == inf ) printf("*\n");
                else printf("%lld\n", T[x].fi + T[y].fi + X[ comp[x] ] * T[x].se + X[ comp[y] ] * T[y].se );
            }
            else{
                if( X[ comp[x] ] == inf ){
                    int g = 1;
                    if( T[x].se == T[y].se ) printf("*\n");
                    else printf("%lld\n", T[x].fi + T[y].fi );
                }
                else{
                    int g = 1;
                    if( x == y ) g++;
                    if( T[x].se == T[y].se ) printf("%lld\n", (T[x].fi + T[y].fi + 2 * T[x].se * X[ comp[x] ])/g );
                    else printf("%lld\n", (T[x].fi + T[y].fi)/g );
                }
            }
        }
        printf("-\n");
    }
    return 0;
}
