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
#define fi first
#define se second
#define MOD 1000000007
#define N 1000000  

int main(){
    long long n, tc, r, a;
    string s;
    string::size_type sz = 0;
    cin >> tc;
    while( tc-- ){
    	cin >> r >> s;
    	stringstream in(s);
    	in >> n;
    	long long ans = 0, a = n, pot = 1;
    	while( a ){
    		if( (a % 10) >= 8 ){
    			ans = 0;
    			break;
    		}
    		ans += (a%10) * pot;
    		pot *= 8;
    		a /= 10;
    	}
    	cout << r << " " << ans << " " << n << " ";
    	a = n, pot = 1;
    	ans = 0;
    	while( a ){
    		ans += (a%10) * pot;
    		pot *= 16;
    		a /= 10;
    	}
    	cout << ans << endl;
    }
    return 0;
}

