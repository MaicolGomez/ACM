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
#define eps 1e-7
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
#define N 3000001

double t[N];

int main(){
    for(int i = 1 ; i < N ; i++)
        t[i] = t[i-1] + log10( 1.0 * i );
    
    int tc , a;
    sc(tc);
    while( tc-- ){
        sc(a);
        int lo = 0 , hi = N - 1;
        while( lo + 1 < hi ){
            int mid = M(lo , hi);
            if( t[mid] > mid * log10( 1.0 * a ) ) hi = mid;
            else lo = mid;
        }
        printf("%d\n",hi);
    }
    return 0;
}
