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
    for(ll i = 100000007LL ; i <= 138902665 ; i += 10){
        ll x = i * i;
        if( x / 100 % 10 == 8 and x / 10000 % 10 == 7 and 
            x / 1000000 % 10 == 6 and x / 100000000 % 10 == 5 and
            x / 10000000000LL % 10 == 4 and x / 1000000000000LL % 10 == 3 ) cout << x << " " << i * 10 << endl;
    }
    
    return 0;
}
