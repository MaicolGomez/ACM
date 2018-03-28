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
#define N 100001

bool f(int x,int y){
    if( x < y ) swap( x , y );
    int a , b;
    if( (x + y - 1) % 2 == 0 ){
        a = (x + y - 1)/2;
        b = a - y;
        if( a >= 0 and b >= 0 ) return 1;
    }
    return 0;
}

int main(){
    int tc , test;
    sc(tc);
    ll n;
    while( tc-- ){
        scanf("%d%lld",&test,&n);
        n *= 2;
        int ans = 0;
        for(ll i = 2 ; i * i <= n ; i++)if( n % i == 0 ){
            ans += f( i , n / i );
        }
        printf("%d %d\n",test,ans);
    }
    return 0;
}
