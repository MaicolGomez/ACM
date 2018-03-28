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
#define ios ios::sync_with_stdio(0)
#define N 2005

vi adj[N];
vi cost[N];

int solve(int u,int p,int k){
    int m1 = 0 , m2 = 0;
    for(int i = 0 ; i < adj[u].size() ; i++){
        if( adj[u][i] == p ) continue;
        int r = cost[u][i] + solve( adj[u][i] , u , 0 );
        if( r > m1 ){
            m2 = m1;
            m1 = r;
        }
        else if( r > m2 ) m2 = r;
    }
    if( !k ) return max( m1 , m2 );
    else return m1 + m2;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n , a , b , c;
        sc(n);
        for(int i = 0 ; i < n ; i++)
            adj[i].clear() , cost[i].clear();
        for(int i = 0 ; i < n - 1 ; i++){
            scanf("%d%d%d",&a,&b,&c); a--,b--;
            adj[a].pb(b); cost[a].pb(c);
            adj[b].pb(a); cost[b].pb(c);
        }
        int best = 0;
        for(int i = 0 ; i < n ; i++)
            best = max( best , solve( i , -1 , 1 ) );
        printf("%d\n", best );
    }
    return 0;
}
