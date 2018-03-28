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
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 10001

int a , b , c , t[N];

int f(int n){
    if( n <= 0 ) return (n == 0)?0:(-inf);
    int &ret = t[n];
    if( ret != -1 ) return ret;
    ret = 0;
    ret = max( 1 + f( n - a ) , max( 1 + f( n - b ) , 1 + f( n - c ) ) );
    return ret;
}

int main(){
    int n;
    while( cin >> n >> a >> b >> c ){
        me(t,-1);
        cout << f( n ) << '\n';
    }
    return 0;
}
