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
#define MOD 10009
#define N 1000000

bool prime[N+5];

void sieve(){
    me( prime , 1 );
    prime[0] = prime[1] = 0;
    for(int i = 2 ; i * i <= N ; i++)
        if( prime[i] )
            for(int j = i*i ; j <= N ; j+=i)
                prime[j] = 0;
}

int main(){
    sieve();
    int n , a , b;
    while( sc(n) == 1 ){
        a = n;
        b = 0;
        while( n ){
            b = b * 10 + n % 10;
            n /= 10;
        }
        bool P = prime[a] , E = prime[b]&&(a!=b);
        if( !P ) printf("%d is not prime.\n",a);
        else if( E ) printf("%d is emirp.\n",a);
        else printf("%d is prime.\n",a);
    }
    
    return 0;
}
