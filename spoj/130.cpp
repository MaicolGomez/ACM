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
#define N 10002

ll t[N] ;
int n;
pair< pii ,int> P[N];

int find(int lo ,int x){
    if( P[lo].fi.fi >= x ) return lo;
    if( P[n-1].fi.fi < x ) return n;
    int hi = n - 1;
    while( lo + 1 < hi ){
        int mid = (hi+lo)/2;
        if( P[mid].fi.fi < x ) lo = mid;
        else hi = mid;
    }
    return hi;
}

ll f(int x){
    if( x == n )
        return 0;
    ll &ret = t[x];
    if( t[x] != -1 ) return ret;
    ret = f(x + 1);
    int next = find( x + 1 , P[x].fi.se );
    ret = max( ret , P[x].se + f( next ) );
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while(tc--){
        sc(n);
        int x , m , g;
        for(int i = 0 ; i < n ; i++){
            sc(x),sc(m),sc(g);
            P[i].fi.fi = x , P[i].fi.se = x + m , P[i].se = g;
        }
        sort( P , P + n );
        me(t,-1);
        cout << f( 0 ) << '\n';
    }
    return 0;
}
