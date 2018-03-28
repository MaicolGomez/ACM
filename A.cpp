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
#define N 5005

ll t[N];

int C( int n , int k )
	t[n][k] = C( n - 1 , k ) + C( n - 1 , k - 1 );


ll f( int n ){
	
	t[1] = t[2] = 1;
	for(int i = 3 ; i <= Limit ; i++)
		t[i] = t[i-1] + t[i-2];
	
	if( n == 1 ) return 1;
	if( n == 2 ) return 1;
	if( t[n] == -1 ){
		t[n] = f( n - 1 ) + f( n - 2 );
		return t[n];
	}
	else return t[n];
}

int main(){
	memset( t , -1 , sizeof(t) );
	for(int i = 1 ; i <= 50 ; i++)
		printf("%d -> %lld\n",i , f(i));
	
}
