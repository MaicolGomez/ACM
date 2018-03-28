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
#define N 10005

int t[N] , m , a[51];

int f(int n){
    int &ret = t[n];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = 0 ; i < m ; i++)
        if( a[i] <= n )
            if( f( n - a[i] ) == 0 ) ret = 1;
    return ret;
}

int main(){
    int n;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
        cin >> a[i];
    
    me(t,-1);
    t[0] = 1;
    int ans = f( n );
    if( ans ) cout << 1 << endl;
    else cout << 2 << endl;
    return 0;
}
