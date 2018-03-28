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
#define N 10000

bool prime[N+5];
vi v;

void sieve(){
    me( prime , 1 );
    prime[0] = prime[1] = 0;
    for(int i = 2 ; i <= N ; i++)
        if( prime[i] )
            for(int j = i*i ; j <= N ; j+=i)
                prime[j] = 0;
     for(int i = 2 ; i <= N ; i++)
        if( prime[i] ) v.pb( i );
}

bool isprime(int n){
    for(int i = 0 ; i < v.size() && v[i] < n ;i++)
        if( n%v[i] == 0 ) return 0;
    return 1;
}

int main(){
    sieve();
    int x , n = v.size();
    while( sc(x) == 1 ){
        if( x & 1 ){
            if( x <= 3 ) printf("%d is not the sum of two primes!\n",x);
            else if( !isprime( x - 2 ) ) printf("%d is not the sum of two primes!\n",x);
            else printf("%d is the sum of %d and %d.\n", x , 2 , x - 2 );
        }
        else{
            int ini = x/2 - 1 - (x&1);
            ini -= ((ini&1)<1);
            bool ok = 1;
            for(int i = ini ; i >= 3 ; i --){
                if( isprime( i ) && isprime( x - i ) ){
                    printf("%d is the sum of %d and %d.\n",x,i,x-i);
                    ok = 0;
                    break;
                }
            }
            if( ok ) printf("%d is not the sum of two primes!\n", x );
        }
    }
    return 0;
}
