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

string tostring(ll x){
    string s = "";
    while(x){
        s += (x%10 + '0');
        x /= 10;
    }
    reverse(all(s));
    return s;
}

string s;
int len;
ll t[12][50][50][2];

ll f(int pos,int a,int b,bool menor){
    if( pos == len )
        return (a == b) and (a > 0);
    
    ll &ret = t[pos][a][b][menor];
    if( ret != -1 ) return ret;
    ret = 0;
    int limsup = (menor)?9:(s[pos] - '0');
    //cout << pos << " " << a << " " << b << " " << menor << " " << limsup << endl;
    for(int i = 0 ; i <= limsup ; i++){
        if( a + i <= 45 ) ret += f( pos + 1 , a + i , b , menor|(i < (s[pos] - '0') ) );
        if( b + i <= 45 ) ret += f( pos + 1 , a , b + i , menor|(i < (s[pos] - '0') ) );
    }
    return ret;
}

int main(){
    ll a , b;
    while( scanf("%lld%lld",&a,&b) == 2 and (a||b) ){
        me(t,-1);
        s = tostring(b);
        len = s.size();
        ll ans = f( 0 , 0 , 0 , 0 );
        if( a > 1 ){
            s = tostring(a-1);
            len = s.size();
            me(t,-1);
            ans -= f( 0 , 0 , 0 ,0 );
        }
        printf("%lld\n",ans);
    }
    return 0;
}
