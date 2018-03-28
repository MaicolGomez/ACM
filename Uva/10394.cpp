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
#define N 20000000

bool prime[N+5];

void sieve(){
    for(int i = 2 ; i * i <= N ; i++)
        if( !prime[i] )
            for(int j = i*i ; j <= N ; j+=i)
                prime[j] = 1;
}

int A[1000005];

int main(){
    sieve();
    int ct = 0;
    for(int i = 3 ; ct < 100000 ; i += 2)
        if( !prime[i] ){
            if(!prime[i+2] )
                A[ct++] = i;
            else i += 2;
        }

    int n;
    while( sc(n) == 1 ){
        n--;
        printf("(%d, %d)\n",A[n], A[n] + 2 );
    }
    return 0;
}
