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
#define N 50

ll t[N][4];

ll f(int x,int last){
    if( x == 0 ){
        return 1;
    }
    ll &ret = t[x][last];
    if( ret != -1 ) return ret;
    ret = f( x - 1 , 1 - last );
    if( x - 2 >= 0 ) ret += f( x - 2 , 1 - last );
    return ret;
}

int main(){
    int n;
    me(t,-1);
    while( sc(n) == 1 ){
        cout << (f(n-1,0) + f(n-1,1)) << endl;
    }
    return 0;
}
