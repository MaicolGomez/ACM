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
#define N 32

int x[N] , y[N] , z[N] , n , t[N][6];

void get(int &a,int &b,int i,int type){
    if( type == 0 ) a = x[i] , b = y[i];
    if( type == 1 ) a = y[i] , b = x[i];
    if( type == 2 ) a = x[i] , b = z[i];
    if( type == 3 ) a = z[i] , b = x[i];
    if( type == 4 ) a = y[i] , b = z[i];
    if( type == 5 ) a = z[i] , b = y[i];
}

int f(int last,int type){
    int &ret = t[last][type];
    if( ret != -1 ) return ret;
    int a , b;
    get( a , b , last , type );
    ret = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        int p = x[i] , q = y[i] , r = z[i];
        if( p < a && q < b ) ret = max( ret , r + f( i , 0 ) );
        if( q < a && p < b ) ret = max( ret , r + f( i , 1 ) );
        if( p < a && r < b ) ret = max( ret , q + f( i , 2 ) );
        if( r < a && p < b ) ret = max( ret , q + f( i , 3 ) );
        if( q < a && r < b ) ret = max( ret , p + f( i , 4 ) );
        if( r < a && q < b ) ret = max( ret , p + f( i , 5 ) );
    }
    return ret;
}

int main(){
    while( sc(n) , n ){
        for(int i = 0 ; i < n ; i++)
            sc(x[i]) , sc(y[i]) , sc(z[i]);
            
        x[n] = y[n] = z[n] = inf;
        n++;
        me(t,-1);
        int ans = f(n-1,0);
        printf("%d\n",ans);
    }
    return 0;
}
