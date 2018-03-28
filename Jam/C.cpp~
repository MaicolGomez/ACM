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
#define N 17

int isprime(int n){
	if( n <= 3 ) return 1;
	for(int i = 4 ; i * i <= n ; i++)
		if( n % i == 0 ) return i;
	return 1;
}

int main(){
	int tc;
	int r = sc(tc);
	for(int tt = 1 ; tt <= tc ; tt++){
		printf("Case #%d:\n",tt);
		int n , k;
		int r = scanf("%d%d",&n,&k);
		vector< vi > A;
		vector< string > B;
		for(int i = 0 ; i < (1<<(n-2)) ; i++){
			if( k == 0 ) break;
			bool prime = 0;
			vi ans;
			string s = "1";
			for(int j = n - 3 ; j >= 0 ; j--)
				if( i&(1<<j) ) s += '1';
				else s += '0';
			s += '1';
			for(int b = 2 ; b <= 10 ; b++){
				int num = 1, pow = b;
				for(int t = 0 ; t < n - 2 ; t++){
				 	if( i&(1<<t) ) num += pow;
				 	pow *= b;
				}
				num += pow;
				int x = isprime(num);
				if( x == 1 ){
					prime = 1;
					break;
				}
				else ans.pb( x );
				if( b == 10 ){
					A.pb( ans );
					B.pb( s );
					k--;
				}
			}
			if( prime ) continue;
		}
		for(int i = 0 ; i < A.size() ; i++){
			cout << B[i] ;
			vi &v = A[i];
			for(int j = 0 ; j < v.size() ; j++)
				cout << " " << v[j];
			cout << endl;
		}
	}
}
