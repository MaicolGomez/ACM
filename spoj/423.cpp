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
#define N 21

ll t[1<<N];
int n , m[N][N];

ll f(int mask){
    if( mask == 0 ) return 1;
    ll &ret = t[mask];
    if( ret != -1 ) return ret;
    ret = 0;
    int player = n - __builtin_popcount(mask);
    for(int i = 0 ; i < n ; i++)if( mask&(1<<i) && m[player][i] )
        ret += f( mask^(1<<i) );
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        sc(n);
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                sc(m[i][j]);
        for(int i = 0 ; i < (1<<n)+5 ; i++)
            t[i] = -1;
        
        printf("%lld\n",f( (1<<n)-1 ));
    }
    return 0;
}
