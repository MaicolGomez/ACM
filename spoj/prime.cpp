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
#define N 463500

bool prime[N+5] , es[N+5];
vector<int> v;

void criba(){
    memset( prime , 1 , sizeof(prime) );
    prime[0] = prime[1] = 0;
    for(int i = 2 ; i * i <= N ; i++) if( prime[i] )
        for(int j = i*i ; j <= N ; j+=i) prime[j] = 0;
    for(int i = 2 ; i<= N ; i++)
    	if(prime[i])
    		v.push_back(i);
}

void solve(){
    int A , B;
    scanf("%d%d",&A,&B);
    for(int i = 0 ; i <= B-A ; i++) es[i] = 1;
    for(int i = 0 ; i < v.size() ; i++){
        ll x = ( (A-1)/v[i] + 1 ) * v[i];
        if( x <= N && prime[x] ) x += v[i];
        for(int j = x ; j <= B ; j+=v[i])
        	es[j-A] = 0;
    }
    for(int i = 0 ; i <= B-A ; i++)
    	if( es[i] )
    		printf("%d\n",i+A);
}

int main(){
    criba();
    int test;
    sc(test);
    for(int i = 0 ; i < test ; i++)
        solve();
    
}

