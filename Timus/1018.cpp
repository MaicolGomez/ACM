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
#define fi first
#define se second
#define MOD 10009
#define N 105

vi adj2[N] , adj[N] , costo[N] , cost[N];
int n , t[N][N];

int f(int u,int q){
    if( t[u][q] >= 0 )
		return t[u][q];
		
	if( q == 0 )
		return t[u][q] = 0;
	
	if( adj[u].size() == 0 )
		return t[u][q] = 0;
    
    int res = 0;
	
	int v1 = adj[u][0], v2 = adj[u][1];
	res = max( res, f(v1, q-1) + cost[u][0] );
	res = max( res, f(v2, q-1) + cost[u][1] );
	
	for(int s = 1; s <= q-1; ++s)
		res = max( res, f(v1, s-1) + f(v2, q-s-1) + cost[u][0] + cost[u][1] );
	
	return t[u][q] = res;
    
    
}

bool vis[N];

void dirige(int u){
    if( adj2[u].size() == 0 ) return;
    vis[u] = 1;
    for(int i = 0 ; i < adj2[u].size() ; i++)if( vis[ adj2[u][i] ] == 0 ){
        adj[u].pb( adj2[u][i] );
        cost[u].pb( costo[u][i] );
        dirige( adj2[u][i] );
    }
}

int main(){
    int q , a , b , c;
    sc(n) , sc(q);
    for(int i = 0 ; i < n - 1 ; i++){
        sc(a),sc(b),sc(c);
        adj2[a].pb(b); costo[a].pb(c);
        adj2[b].pb(a); costo[b].pb(c);
    }
    dirige( 1 );
    me(t,-1);
    printf("%d\n",f(1 , q));
    return 0;
}
