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
#define N 505

int n , k , T , t[N][N] , a[N];

int f(int x,int y){
    if( x == n )
        return ((y==k)?0:(-inf));
    
    int &ret = t[x][y];
    if( ret != -1 ) return ret;
    ret = f( x + 1 , y );
    if( y < k ){
        int mini = inf;
        for(int i = x ; i <= min( x + T - 1 , n - 1 ) ; i++){
            mini = min( mini , a[i] );
            ret = max( ret , mini * (i - x + 1) + f( i + 1 , y + 1 ) );
        }
    }
    return ret;
}

int main(){
    while( scanf("%d%d%d",&n,&k,&T) == 3 ){
        for(int i = 0 ; i < n ; i++)
            sc(a[i]);
        me(t,-1);
        int ans = f( 0 , 0 );
        printf("%d\n",ans);
    }
    return 0;
}
