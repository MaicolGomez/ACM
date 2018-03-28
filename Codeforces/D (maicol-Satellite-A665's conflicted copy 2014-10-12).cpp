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
#define ios ios::sync_with_stdio(0);
#define N 100001

int T , t[20][2001];

int f(int x,int sz){
    if( sz == 0 ) return 1;
    if( x == 0 ) return 0;
    int &ret = t[x][sz];
    if( ret != -1 ) return ret;
    ret = f( x - 1 , sz );
    ret = (ret + f( x - 1 , sz - 1 ) ) % MOD;
    ret = (ret + f( x - 1 , sz - 1 ) ) % MOD;
    return ret;
}

int main(){
    int n , k;
    me(t,-1);
    while( cin >> n >> k ){
        int ans = 1;
        if( n > 1 ){
            for(int i = 2 ; i <= n ; i++){
                int x = 2;
                T = 2;
                while( x <= n ){
                    x *= i;
                    if( x <= n ) T++;
                }
                //cout << i << " " << T << "\n";
                ans += ( f( T , k ) -1 + MOD ) % MOD;
            }
        } 
        cout << ans << "\n";
    }
    return 0;
}
