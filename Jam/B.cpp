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
#define N 12

int n , t[1<<N][N];

int f(int mask,int last,string s){
	if( mask == (1<<n) - 1 )
		return 0;
	//cout << "--> " << mask << endl;
	if( t[mask][last] != -1 ) return t[mask][last];
	int &ret = t[mask][last];
	ret = inf;
	for(int i = 0 ; i < n ; i++){
		if( i == last ) continue;
		string ns = s;
		//cout << ": " << i << endl;
		for(int j = 0 ; j <= i/2 ; j++){
			//cout << i << " " << i - j << endl; 
			if( j == i - j ){
				//cout << "entro\n";
				if( ns[j] == '-' ) ns[j] = '+';
				else ns[j] = '-';
			}
			else{
				if( ns[j] == '-' ) ns[j] = '+';
				else ns[j] = '-';
				if( ns[i-j] == '-' ) ns[i-j] = '+';
				else ns[i-j] = '-';
				swap( ns[j] , ns[i - j] );
			}
		}
		//cout << s << " " << ns << endl;
		int nmask = 0;
		for(int j = 0 ; j < n ; j++)
			if( ns[n - j - 1] == '+' ) nmask ^= (1<<j);
		
		ret = min( ret , 1 + f(nmask , i , ns) );
	}
	return ret;
}

int main(){
	int tc;
	int r = sc(tc);
	for(int tt = 1 ; tt <= tc ; tt++){
		printf("Case #%d: ",tt);
		string s;
		cin >> s;
		n = int(s.length());
		me(t,-1);
		int mask = 0;
		for(int i = 0 ; i < n ; i++)
			if( s[n - i - 1] == '+' ) mask ^= (1<<i);
		printf("%d\n",f(mask,11,s));
	}
}
