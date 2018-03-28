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
#define N 500005

int a[N] , n;

bool f( int id , int it1 , int it2 ){
	if( n <= 2 ) return 1;
	int u = a[id] , d = a[id];
	while( it2 >= it1 ){
		bool in = 0;
		if( it1 < n ){
			if( a[it1] == u - 1 ){
				it1++;
				u--;
				in = 1;
				continue;
			}
			else if( a[it1] == d + 1 ){
				it1++;
				d++;
				in = 1;
			}
		}
		if( it2 >= 0 ){
			if( a[it2] == u - 1 ){
				it2--;
				u--;
				in = 1;
				continue;
			}
			else if( a[it2] == d + 1 ){
				it2--;
				d++;
				in = 1;
			}
		}
		if( !in ) return 0;
		
	}
	return 1;
}

int main(){
	int tc;
	sc(tc);
	for(int tt = 1 ; tt <= tc ; tt++){
		printf("Case #%d: ",tt);
		sc(n);
		for(int i = 0 ; i < n ; i++)
			sc(a[i]);
			
		if( f( 0 , 1 , n - 1 ) or f( n - 1 , 0 , n - 2 ) ) printf("yes\n");
		else printf("no\n");
	}
}
