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
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0)
#define N 100000

string s = "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
int L;

ll t[105][10][2] , t2[105][10];

ll f(int x,int last,int menor){
    if( x == L ) return last > 0;
    ll &ret = t[x][last][menor];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = last ; i <= (menor?(9):( s[i] - '0' )) ; i++)
        ret += f( x + 1 , i , menor|( i < (s[i] - '0' ) ) );
    return ret;
}

ll g(int x,int last){
    if( x == L ) return last;
    ll &ret = t2[x][last];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = 0 ; i <= 9 ; i++)if( i >= last )
        ret += g( x + 1 , i );
    return ret;
}

int main(){
    L = s.size();
    me(t,-1);
    me(t2,-1);
    ll ans = f( 0 , 0 , 0 );
    for(int i = 1 ; i < L ; i++)
        ans += g( i , 0 );
    
    for(int i = 1 ; i < L ; i++)
        ans -= 9;
    
    cout << ans << endl;
    return 0;
}
