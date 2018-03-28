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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define N 105

set<ll> S;
vi P;

void criba(){
    bool prime[N];
    me(prime,1);
    prime[0] = 0;
    for(int i = 2 ; i * i <= N - 5 ; i++)
        if(prime[i])
            for(int j = i * i ; j <= N - 5 ; j +=i )
                prime[j] = 0;
    for(int i = 1 ; i <= 100 ; i++)if( prime[i] )
        P.pb( i );
}
int mod;
void f(int t,int n,ll x){
    if( n == 0 ){
        S.insert(x);
        return;
    }
    if( n - P[t] >= 0 )
        f( t ,  n - P[t] , (x * P[t])%mod );
    if( n - P[t+1] >= 0 )
        f( t + 1 , n , x );
}

int main(){
    criba();
    int tc;
    sc(tc);
    while(tc--){
        int n;
        sc(n),sc(mod);
        S.clear();
        f( 0 , n , 1 );
        printf("%d\n",(int)S.size());
    }
    return 0;
}
