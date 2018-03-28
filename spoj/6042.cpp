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
#define MOD 761238923
#define N 105

int n , t[N][N];

int f(int x,int used){
    if( x == n + 1 )
        return used == n;
    int &ans = t[x][used];
    if( ans != -1 ) return ans;
    ans = 0;
    for(int i = 0 ; i + used <= x ; i++){
        ans += f( x + 1 , used + i );
        if( ans >= MOD ) ans -= MOD;
    }
    return ans;
}

int main(){
    while( sc(n) == 1 && n ){
        me(t,-1);
        printf("%d\n",f(1,0));
    }
    return 0;
}
