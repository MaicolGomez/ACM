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
#define N 1005

map<int,ll> m;

ll f(int n){
    if( n == 0 )
        return 0;
    
    if( m.find(n) != m.end() ) return m[n];
    ll ret = n;
    
    m[n] = max( ret , f(n/2) + f(n/3) + f(n/4) );
    
    return m[n];
}

int main(){
    int n;
    while( sc(n) == 1 ){
        printf("%lld\n",f(n));
    }
    return 0;
}
