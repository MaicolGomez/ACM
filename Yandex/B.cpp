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
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 500000

bool prime[N+5];
int n;
ll A[N];

void criba(){
    me(prime,1);
    prime[0] = prime[1] = 0;
    
    for(int i = 2 ; i * i <= N ; i++)
        if( prime[i] )
            for(int j = i * i  ; j <= N ; j += i)
                prime[j] = 0;
    
    n = 0;
    for(int i = 0 ; i <= N ; i++)
        if( prime[i] ) A[n++] = i;
}

int g(long long x){
    
    ll r = (ll)( sqrt(x+0.5) );
    if( r * r == x ) return r;
    return -1;
}

int main(){
    criba();

    ll r;
    while( cin >> r ){
        for(int i = 0 ; i + 1 < n ; i++){
            ll x = g( A[i] * A[i+1] + 1 );
            if( x != -1 and x <= r ) cout << x << '\n';
        }
    }
    
    return 0;
}
