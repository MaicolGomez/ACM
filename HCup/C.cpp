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
#define N 2005

void get(string s , int &a,int &b){
	for(int i = 0 ; i < s.size() ; i++)
		if( s[i] == '-' ) s[i] = ' ';	
	
	stringstream in(s);
	in >> a >> b;
}

int a , b , t[N][N] , r[N][N];

int f(int x,int y){
	if( x == a and y == b ) return 1;
	int &ret = t[x][y];
	if( ret != -1 ) return ret;
	ret = 0;
	if( x < a ) ret += f( x + 1 , y );
	if( ret >= MOD ) ret -= MOD;
	if( y < b and y + 1 < x ) ret += f( x , y + 1 );
	if( ret >= MOD ) ret -= MOD;
	return ret;
}

int g(int x,int y){
	if( x == a and y == b ) return 1;
	int &ret = r[x][y];
	if( ret != -1 ) return ret;
	ret = 0;
	if( x < a and (x + 1 <= y or y == b) ) ret += g( x + 1 , y );
	if( ret >= MOD ) ret -= MOD;
	if( y < b ) ret += g( x , y + 1 );
	if( ret >= MOD ) ret -= MOD;
	return ret;
}

int main(){
	int tc;
	cin >> tc;
	for(int tt = 1 ; tt <= tc ; tt++){
		cout << "Case #" << tt <<" : ";
		string s;
		cin >> s;
		a = b = 0;
		get( s , a , b );
		me(t,-1);
		me(r,-1);
		cout << f( 0 , 0 ) << " " << g( 0 , 0 ) << "\n";
	}
}
