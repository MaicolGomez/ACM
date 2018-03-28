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

int f(int n){
	if( n == 2 ) return 1;
	if( n < 3 || n % 2 == 0 ) return 0;
	if( n == 3 ) return 1;
	for(int i = 3 ; i * i <= n ; i += 2)
		if( n % i == 0 ) return 0;
	return 1;
}

int main(){
    int n;
    while( sc(n) == 1 ){
    	for(int i = n ; ; i--){
    		if( f( i ) ){
    			printf("%d\n",i);
    			break;
    		}
    	}
    }
    return 0;
}

