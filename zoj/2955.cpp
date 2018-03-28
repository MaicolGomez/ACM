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
#define inf (1LL<<50)
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
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 100*105

int a[105];
ll t[N];

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n , S;
        scanf("%d%d",&n,&S);
        for(int i = 0 ; i < n ; i++)
            sc(a[i]);
        
        ll ans = inf;
        sort( a , a + n );
        t[0] = 0;
        for(int i = 1 ; i <= 100*100 ; i++){
            t[i] = inf;
            for(int j = 0 ; j < n ; j++)
                if( a[j] and i - a[j] >= 0 ) t[i] = min( t[i] , 1 + t[i - a[j]] );
                else break;
            if( t[i] != inf and (S - i)%a[n-1] == 0 ) ans = min( ans , t[i] + (S - i)/a[n-1] );
        }
        if( ans >= inf ) ans = -1;
        printf("%lld\n",ans);
    }
    return 0;
}
