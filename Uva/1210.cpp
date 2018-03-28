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
    for(int i = 2 ; i * i <= N ; i++)
        if( prime[i] )
            for(int j = i*i ; j <= N ; j+=i)
                prime[j] = 0;
     for(int i = 2 ; i <= N ; i++)
        if( prime[i] ) v.pb( i );
}

int main(){
    sieve();
    int n , x;
    while( sc(x) , x ){
        int n = v.size() , ans = 0;
        for(int i = 0 ; i < n ; i++){
            int S = 0;
            for(int j = i ; j < n ; j++){
                S += v[j];
                if( S >= x ) break;
            }
            ans += (S==x);
        }
        printf("%d\n",ans);
    }
    return 0;
}
