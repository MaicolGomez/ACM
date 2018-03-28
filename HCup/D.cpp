#include<bits/stdc++.h>
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
#define MOD 1000000007
#define ios ios::sync_with_stdio(0)
#define N 200004
#define C 20

vi adj[N];
int t[N][C+1];

int f(int u,int x){
	if( adj[u].size() == 0 ){
		if( x == 1 ) return 2;
		return 1;
	}
	int &ret = t[u][x];
	if( ret != -1 ) return ret;
	ret = inf;
	for(int j = 1 ; j <= C ; j++)
		if( j != x ){
			int r = j;
			for(int i = 0 ; i < adj[u].size() ; i++){
				int v = adj[u][i];
				r += f( v , j );
			}
			ret = min( ret , r );
		}
	return ret;
}

int main(){
	int tc;
	int g = sc(tc);
	for(int tt = 1 ; tt <= tc ; tt++){
		int n , x;
		g = sc(n);
		for(int i = 0 ; i < n ; i++)
			adj[i].clear();
		me(t,-1);
		for(int i = 0 ; i < n ; i++){
			g = sc(x);
			if( x > 0 ) adj[x - 1].pb( i );
		}
		
		for(int i = n - 1 ; i >= 0 ; i -= 100)
			f( i , 0 );
		
		printf("Case #%d: %d\n",tt,f(0 , 0));
	}
}
