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
#define N 105

int n , k;
vi T[N];
bool is[N][N];
pair< int , char > ans[N];

bool in( int ind , int x ){
	for(int i = ind ; i < n ; i += k)
		if( !is[i][x] ) return 0;
	return 1;
}

ll F[N];

int main(){
	ios;
	F[0] = 1;
	for(int i = 1 ; i < 21 ; i++)
		F[i] = F[i-1] * i;
		
	string a , b;
	int ct = 0;
	while( cin >> k >> a >> b ){
		//ct++;
		//if( ct == 271 ) cout << k << "\n" << a << "\n" << b << "\n";
		n = a.size();
		
		bool can = 1;
		for(int i = 0 ; i < n ; i += k){
			string x = a.substr( i , k );
			string y = b.substr( i , k );
			sort( all(x) ); sort( all(y) );
			//cout << x << " " << y << endl;
			if( x != y ) can = 0;
		}
		if( !can ){
			cout << "0\n";
			continue;
		}
		
		me(is,0);
		for(int i = 0 ; i < N ; i++)
			T[i].clear();
			
		for(int i = 0 ; i < N ; i++)
			ans[i].fi = 0 , ans[i].se = '0';
				
		for(int i = 0 ; i < n ; i += k){
			int p = i , q = i + k - 1;
			for(int j = p ; j <= q ; j++)
				for(int kk = p ; kk <= q ; kk++)
					if( b[j] == a[kk] ) T[j].pb( kk - p ) , is[j][ kk - p ] = 1;
		}
		
		ll ret = 1;
		for(int i = 0 ; i < n ; i++){
			ans[i].fi = 0 , ans[i].se = '0';
			for(int j = 0 ; j < T[i].size() ; j++){
				int x = T[i][j];
				if( in( i%k , x ) ) ans[i].fi++ , ans[i].se = b[i];
			}
			//cout << ans[i].fi << " " << ans[i].se << "\n";
			if( ans[i].fi == 0 ){
				ret = 0;
				break;
			}
		}
		//cout << "salio\n";
		if( ret == 0 ) cout << ret << "\n";
		else{
			for(int j = 0 ; j < n ; j += k){
				ll sol = 1;
				for(char i = 'a' ; i <= 'z' ; i++){
					int maxi = 0;
					vi v;
					for(int kk = j ; kk < j + k ; kk++)
						if( ans[kk].se == i ) v.pb( ans[kk].fi );
					
					if( v.size() == 0 ) continue;
					sort( all(v) );
					int g = v[0] , ct = 0;
					for(int t = 0 ; t < v.size() ; t++){
						if( v[t] == g ){
							ct++;
							if( ct == g ) sol *= F[g] , ct = 0;
						}
						else{
							ct = 1;
							g = v[t];
							if( ct == g ) sol *= F[g] , ct = 0;
						}
					}
					
				}
				ret = max( ret , sol );
			}
			cout << ret << "\n";
		}
		//break;
	}
	return 0;
}
