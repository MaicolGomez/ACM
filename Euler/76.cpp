#include<bits/stdc++.h>
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
#define ios ios::sync_with_stdio(0)
#define N 105

ll t[N][N];

ll f(int x,int a){
    if( x >= 100 ) return x == 100;
    if( a == 100 ) return 0;
    ll &ret = t[x][a];
    if( ret != -1 ) return ret;
    ret = f( x + a , a ) + f( x , a + 1 );
    return ret;
}

int main(){
    me(t,-1);
    cout << f( 0 , 1 ) << endl;
    return 0;
}
