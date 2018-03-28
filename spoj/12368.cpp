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

int n , h , A[N] , a[N] , t[N];

int f(int x){
    if( x == n - 1 ) return 0;
    int &ret = t[x];
    if( ret != -1 ) return ret;
    ret = inf;
    for(int i = x + 1 ; i < n ; i++)
        if( A[i] - A[x] <= (i - x) * h ) ret = min( ret , i - x - 1 + f(i) );
    return ret;
}

int main(){
    while( sc(n) , sc(h) ){
        if( n == -1 ) break;
        for(int i = 0 ; i < n - 1 ; i++){
            sc(a[i]);
            A[i+1] = A[i] + a[i];
        }
        me(t,-1);
        
        int ans = f(0);
        
        if( ans != inf ) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
