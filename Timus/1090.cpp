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
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 10001

int n , a[N] , is[N] , t[N];

int solve(){
    me( t , 0 );
    int x , ans = 0;
    for(int i = 0 ; i < n ; i++){
        sc(x);
        x = n + 1 - x;
        for(int i = x ; i ; i -= (i&-i) ) ans += t[i];
        for(int i = x ; i <= n ; i += (i&-i) ) t[i]++;
    }
    return ans;
}

int main(){
    int k;
    scanf("%d%d",&n,&k);
    int ans = -1 , c;
    for(int i = 0 ; i < k ; i++){
        int r = solve();
        if( ans < r ){
            ans = r;
            c = i + 1;
        }
    }
    printf("%d\n",c);
    return 0;
}
