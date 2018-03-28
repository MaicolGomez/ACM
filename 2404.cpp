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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define N 100005

int a[N];

int main(){
    int n , t , ans = 0;
    sc(n) , sc(t);
    for(int i = 0 ; i < n ; i++)
        sc(a[i]);
    
    sort( a , a + n );
    int l = 0 , r = n - 1;
    while( l < r ){
        if( a[l] + a[r] <= t ){
            l++ , r--;
            ans++;
        }
        else r-- , ans++;
    }
    if( l == r ) ans++;
    printf("%d\n",ans);
    return 0;
}
