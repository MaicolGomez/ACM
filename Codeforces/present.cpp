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
#define fi first
#define se second
#define MOD 10009
#define N 5005

int t[N] , x[N] , y[N] , pa[N];

int main(){
    int n , w , h;
    pair< pii , int > P[N];
    while( cin >> n >> w >> h ){
        x[0] = w , y[0] = h;
        for(int i = 1 ; i <= n ; i++){
            cin >> P[i].fi.fi >> P[i].fi.se;
            P[i].se = i;
        }
        sort( P + 1 , P + 1 + n );
        for(int i = 1 ; i <= n ; i++)
            x[i] = P[i].fi.fi , y[i] = P[i].fi.se;
        
        x[n+1] = inf , y[n+1] = inf;
        for(int i = 0 ; i < n + 2 ; i++)
            t[i] = 1;
        me( pa , -1 );
        for(int i = n ; i >= 0 ; i--)
            for(int j = n + 1 ; j > i ; j--)
                if( x[i] < x[j] && y[i] < y[j] )
                    if( t[j] + 1 > t[i] ){
                        t[i] = t[j] + 1;
                        pa[i] = j;
                    }
        
        cout << t[0] - 2 << endl;
        int k = 0;
        while( pa[k] != -1 ){
            if( k ) cout << P[k].se << " ";
            k = pa[k];
        }
        cout << endl;
    }
    return 0;
}
