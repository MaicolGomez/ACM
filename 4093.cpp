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
#define N 100000

int main(){
    string s;
    while( cin >> s ){
        ll ans = 0 , pot = 1;
        for(int i = s.size() - 1 ; i >= 0 ; i--){
            if( s[i] >= '0' and s[i] <= '9' ) ans += pot * (s[i] - '0');
            else ans += pot * (s[i] - 'A' + 10);
            pot *= 16;
        }
        cout << ans << "\n";
    }
    return 0;
}
