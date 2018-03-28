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
#define N 75

int t[N][N] , T;

int f(int n,int p){
    if( p == 1 )
        return n >= T;
    int &ret = t[n][p];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = T ; i <= n ; i++)
        ret += f( n - i , p - 1 );
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        me(t,-1);
        int n , p;
        sc(p),sc(n),sc(T);
        printf("%d\n",f( n , p ));
    }
    return 0;
}
