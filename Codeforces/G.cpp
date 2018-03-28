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

double T;

double f(vi v,int n,int k){
	if( k == 0 ){
		double ans = 0;
		for(int i = 0 ; i < n ; i++)
			for(int j = i + 1 ; j < n ; j++)
				if( v[i] > v[j] ) ans++;
		return ans;
	}
	double ans = 0;
	for(int i = 0 ; i < n ; i++)
		for(int j = i ; j < n ; j++){
			vi r;
			r = v;
			reverse( r.begin() + i , r.begin() + j + 1 );
			ans += f( r , n , k - 1 );
		}
	cout << "\n";
	return ans;
}

int main(){
	double F[7];
	F[1] = 1;
	for(int i = 2 ; i <= 6 ; i++)
		F[i] = F[i-1] * i;
		
	int n , k;
	while( cin >> n >> k ){
		vi v(n);
		for(int i = 0 ; i < n ; i++)
			cin >> v[i];
		
		double ans = 0;
		ans = f( v , n , k );
		T = 1;
		for(int i = 0 ; i < k ; i++) T *= n * (n+1) / 2;
		printf("%.12lf\n", ans / T );
	}
}
