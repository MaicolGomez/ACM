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

int n , x[N] , y[N] , t[N][31];

int f(int pos,int volumen){
    if( pos == n )
        return 0;
    int &ret = t[pos][volumen];
    if( ret != -1 ) return ret;
    ret = f( pos + 1 , volumen );
    if( volumen >= y[pos] ) ret = max( ret , x[pos] + f( pos + 1 , volumen - y[pos] ) );
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        sc(n);
        for(int i = 0 ; i < n ; i++)
            sc(x[i]) , sc(y[i]);
        
        me(t,-1);
        int g , ans = 0 , vol;
        sc(g);
        while( g-- ){
            sc(vol);
            ans += f( 0 , vol );
        }
        printf("%d\n",ans);
    }
    return 0;
}
