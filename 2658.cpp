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
#define N 100000

int t[1<<15+1][183][5];

int f(int n,int x,int r){
	if( n == 0 and r >= 0 ) return 1;
	if( x == 0 or r == 0 ) return 0;
	int &ret = t[n][x][r];
	if( ret != -1 ) return ret;
	ret = f( n , x - 1 , r );
	if( n - x * x >= 0 ) ret += f( n - x * x , x , r - 1 );
	return ret;
}

int main(){
	me( t , -1);
	int n;
	while( sc(n) == 1 and n ){
		printf("%d\n",f( n , int(sqrt(n) + 1) , 4 ));
	}
	
	return 0;
}
