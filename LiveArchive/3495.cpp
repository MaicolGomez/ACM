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
#define ll unsigned long long
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

ll C(ll x,ll mod){
    return ((Q(x) % mod) * x) % mod;
}

ll get(string s){
    stringstream in(s);
    ll x;
    in >> x;
    return x;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        string s;
        cin >> s;
        ll n = get(s);
        ll lo = 0 , hi = 100000;
        bool good = 0;
        while( lo + 1 < hi ){
            ll mid = M(lo , hi);
            if( Q(mid) * mid >= n ) hi = mid;
            else lo = mid;
        }
        if( Q(hi) * hi == n and s[0] != '0' ) good = 1;
        if( good ) printf("%lld\n",hi);
        else{
            reverse( all(s) );
            ll x = 0 , mod = 10 , need = 0;
            for(int i = 0 ; i < s.size() ; i++){
                need = need + (mod / 10) * (s[i] - '0');
                for(int j = 0 ; j < 10 ; j++){
                    ll nx = x + (mod / 10) * j;
                    if( C(nx , mod) == need ){
                        x = nx;
                        mod *= 10;
                        break;
                    }
                }
            }
            printf("%lld\n",x);
        }
    }
    return 0;
}
