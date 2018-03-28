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
#define MOD 1000000007
#define N 1005

int main(){
    int tc , n;
    int aa , bb , cc;
    sc(tc);
    while( tc-- ){
        scanf("%d%d%d%d",&aa,&bb,&cc,&n);
        ll ans = 1;
        priority_queue < int , vector<int>, less <int> > L;
	    priority_queue < int , vector<int>, greater <int> > R;
        L.push( 1 );
        for(int i = 2 ; i <= n ; i++){
            ll med;
            int a = L.top() , b = (R.size()>0)?(R.top()):0;
            int l1 = L.size() , l2 = R.size();
            if( l1 + l2&1 == l1 + 1 ) med = (a + b)/2;
            else med = a;
            if( med >= MOD ) med %= MOD;
            med = ( (1LL*aa*med) + (1LL * bb * i) + cc )%MOD;
            ans += med;
            if( l2 == 0 ){
                int g = b;
                if( g > med ){
                    L.pop();
                    L.push( med );
                    R.push( g );
                }
                else R.push( med );
                continue;
            }
            if( l1 == l2){
                if( med >= b ){
                    R.pop();
                    R.push( med );
                    L.push( b );
                }
                else L.push( med );
            }
            else{
                if( med >= a ) R.push( med );
                else{
                    L.pop();
                    L.push( med );
                    R.push( a );
                }
            }
        }
        printf("%lld\n",ans); 
    }
    
    return 0;
}
