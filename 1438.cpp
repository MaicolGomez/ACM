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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define N 1005

ll f(ll b,int p){
    ll a = 1;
    for(int i = 0 ; i < p ; i++)
        a *= b;
    return a;
}

int main(){
    ll n;
    while( cin >> n ){
        if( n == 0 ) break;
        /*vi v;
        for(int i = 2 ; i * i <= n ; i++){
            if( n % i == 0 ){
                int p = 0;
                while( n % i == 0 ){
                    p++;
                    n /= i;
                }
                if( p == 1 ) break;
                v.pb(p);
            }
        }
        if( n > 1 || v.size() == 0 ) printf("1\n");
        else{
            int ans = v[0];
            for(int i = 1 ; i < v.size() ; i++)
                ans = __gcd( ans , v[i] );
            printf("%d\n",ans);
        }*/
        bool nega = 0;
        if( n < 0 ) nega = 1;
        int ans = 1;
        for(int i = 2 ; i <= 32 ; i++){
            if( nega && i % 2 == 0 ) continue;
            ll g = (ll)pow( (nega?-1:1)*n , 1.0/i );
            for(ll b = g - 2 ; b <= g + 2 ; b++){
                ll k = f( (nega?-1:1)*b , i );
                //cout << n << " " << i << " " << g << " " << k << endl;
                if( k == n ){
                    ans = i;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
