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
#define MOD 1000000000
#define N 105

ll F[N] , A[N];

int main(){
    ios::sync_with_stdio(0);
    F[0] = F[1] = 1;
    for(int i = 2 ; i <= 100 ; i++)
        F[i] = (F[i-1] +F[i-2])%MOD;
    int n , m;
    while( cin >> n >> m ){
        for(int i = 0 ; i < n ; i++)
            cin >> A[i];
        
        cout << m << endl;
        while(m--){
            cin >> t >> x >> y;
            if( t == 1 )
                A[x-1] = y;
            else{
                ll ans = 0;
                for(int i = x ; i <= y ; i++){
                    ans += F[i-x] * A[i];
                    if(ans >= MOD) ans %= MOD;
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}
