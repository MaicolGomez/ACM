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
#define N 102
#define M 5*N
int n , m , pa[N][M] , a[N][M];
ll  t[N][M];


ll f(int x,int last){
    if( x == n ) return a[x][last];
    ll &ret = t[x][last];
    if( ret != -1 ) return ret;
    ret = a[x][last] + f(x+1,last);
    pa[x][last] = 0;
    if( last - 1 >= 0 ){
        ll r = a[x][last] + f( x , last - 1 );
        if( r < ret ){
            ret = r;
            pa[x][last] = -1;
        }
    }
    if( last + 1 < m ){
        ll r = a[x][last] + f( x , last + 1);
        if( r < ret ){
            ret = r;
            pa[x][last] = 1;
        }
    }
    return ret;
}

void print(int x,int last){
    if( x == n-1 ) return;
    if( pa[x][last] == 0 ) printf(" %d",last+1) , print( x + 1 , last);
    else printf(" %d",last + pa[x][last] + 1) , print( x , last + pa[x][last] );
}

int main(){
    me(t,-1);
    sc(n),sc(m);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            sc(a[i][j]);
    
    ll ans = (1LL<<50);
    int x = -1;
    for(int i = 0 ; i < m ; i++){
        ll r = f( 0 , i );
        if( r < ans ){
            ans = r;
            x = i;
        }
    }
    printf("%d",x+1);
    print(0,x);
    printf("\n");
    return 0;
}
