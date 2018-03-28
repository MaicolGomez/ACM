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
#define N 100001

bool good(int x){
    while( x ){
        int r = x % 10;
        if( r == 4 or r == 7 ) return 1;
        x /= 10;
    }
    return 0;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n , ans = 0;
        sc(n);
        for(int i = 1 ; i * i <= n ; i++){
            if( n % i == 0 ){
                ans += good( i );
                if( i * i != n ) ans += good( n / i );
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
