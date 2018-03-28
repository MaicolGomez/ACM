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
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf (1<<30)
#define eps 1e-8
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mk(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define fi first
#define se second
#define N 110
#define mp(a,b) make_pair(a,b)

int main(){
    int n;
    while( scanf("%d",&n) == 1 && n ){
        vi a(n) , b(n);
        for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
        for(int i = 0 ; i < n ; i++) scanf("%d",&b[i]);
        sort( all(b) ); //reverse( all(b) );
        sort( all(a) );
        int ans = 0 , ha = 0 , hb = 0 , ta = n - 1 , tb = n - 1;
        for(int i = 0 ; i < n ; i++){
            if( a[ha] > b[hb] ) ans++ , ha++, hb++;
            else if( a[ta] > b[tb] ) ans++ , ta-- , tb--;
            else ans -= (a[ha] != b[tb] ) , ha++, tb--;
        }
        printf("%d\n", 200*ans );
    }
}