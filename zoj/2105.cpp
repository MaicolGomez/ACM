#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<deque>
#include<queue>
#include<map>
#include<climits>
#include<string>
#include<stack>
#include<sstream>
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
#define fi first
#define se second
#define N 1005
#define MOD 7;

bool prime[N];

void pre(){
	me(prime,1);
	prime[0] = prime[1] = 0;
	for(int i = 2 ; i * i <= N ; i++)
		if( prime[i] )
			for(int j = 2 * i ; j <= N ; j += i)
				prime[j] = 0;
}

int main(){
	pre();
    int tc;
    sc(tc);
    while( tc-- ){
    	int L , R;
    	scanf("%d%d",&L,&R);
    	int ct = 0;
    	for(int i = L ; i <= R ; i++)
    		ct += prime[i];
    	
    	printf("%d\n",ct);
    }
}

