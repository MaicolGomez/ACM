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
#define inf (1<<29)
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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 1005

double l , r , s , t[N];

double f(int n){
    if( n == 0 ) return 0.0;
    double &ret = t[n];
    if( ret > -1e9 ) return ret;
    ret = -1e5;
    ret = (1.0 + f( n - 1 ) ) * r + ( -1.0 + f( n - 1 ) ) * l + f( n - 1 ) * s;
    return ret;
}

int main(){
    int tc , test , n;
    cin >> tc;
    while( tc-- ){
        cin >> test >> n >> l >> r ;
        s = 1.0 - l - r;
        for(int i = 0 ; i < n ; i++)
            t[i] = -1e10;
        printf("%d %.4lf\n",test,f(n));
    }
    return 0;
}
