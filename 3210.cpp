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

int main(){
    ll c , n , a1 , a2 , b1 , b2 , d1 , d2;
    cin >> c >> n >> a1 >> b1 >> d1 >> a2 >> b2 >> d2;
    int x = 1;
    ll c1 = c , c2 = c , ans;
    while( x < n ){
        cout << x << " " << c1 << " " << c2 << endl;
        while( x < n and a1 * c1 / d1 + b1 < a2 * c2 / d2 + b2 ){
            x++;
            c1 = a1 * c1 / d1 + b1;
        }
        cout << x << " " << c1 << " - " << c2 << endl;
        if( x == n ){ans = c1; break;}
        if( a1 * c1 / d1 + b1 == c2 ) c2 = a2 * c2 / d2 + b2;
        
        while( x < n and a2 * c2 / d2 + b2 < a1 * c1 / d1 + b1 ){
            x++;
            c2 = a2 * c2 / d2 + b2;
        }
        if( x == n ){ ans = c2; break; }
        if( a2 * c2 / d2 + b2 == c1 ) c1 = a1 * c1 / d1 + b1;
    }
    cout << ans << endl;
    return 0;
}
