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
#define N 20

int m[N+2][N+2] , t[205][N] , n , k[N+2];

int f(int C,int x){
    if( x == n )
        return C;
    int &ret = t[C][x];
    if( ret != -1 ) return ret;
    ret = inf;
    for(int j = 0 ; j < k[x] ; j++) if( m[x][j] <= C )
        ret = min( ret , f( C - m[x][j] , x + 1 ) );
    return ret;
}

int main(){
    int tc , T;
    sc(tc);
    while( tc-- ){
        sc(T),sc(n);
        for(int i = 0 ; i < n ; i++){
            sc(k[i]);
            for(int j = 0 ; j < k[i] ; j++){
                sc(m[i][j]);
            }
        }
        me(t,-1);
        if( f( T , 0 ) != inf ) printf("%d\n",T - f(T,0));
        else printf("no solution\n");
    }
    return 0;
}
