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
#define N 22

double t[20];
double pro[1<<20 + 5];

double f(int x){
	if( x == 20 ) return 0;
	double &ret = t[x];
	if( ret > -0.5 ) return ret;
	double k = 1;
	int mask = (1<<x) - 1;
	double p = 0;
	for(int i = 0 ; i < (1<<20) ; i++){
		if( int(mask|i) >= mask ){
			if( int(mask|i) == mask ) p += pro[i];
			else{
				int g = int(mask|i);
				int e = __builtin_popcount( g );			
				k += pro[i] *  f( e );
			}
		}
	}
	ret = k/(1 - p);
	
	return ret;
}

int main(){
	
	int tc;
	cin >> tc;
	double p;
	for(int tt = 1 ; tt <= tc ; tt++){
		cin >> p;
		
		me( t , -1 );
		for(int i = 0 ; i < 1<<20 ; i++){
			double r = 1;
			for(int j = 0 ; j < 20 ; j++){
				if( i&(1<<j) ) r *= p;
				else r *= (1 - p);
			}
			pro[i] = r;		
		}
		
		printf("Case #%d: %.5lf\n",tt,f( 0 ));
	}
	
}
