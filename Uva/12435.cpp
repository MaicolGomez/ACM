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
#define MOD 10009
#define N 1005

ll x[N] , y[N] , d[N*N];

int main(){
    
    int tc;
    sc(tc);
    for(int test = 1 ; test <= tc ; test++){
        printf("Case %d: ",test);
        int n;
        sc(n);
        int ct = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> x[i] >> y[i];
            for(int j = 0 ; j < i ; j++)
                d[ct++] = Q( x[i] - x[j] ) + Q( y[i] - y[j] );
        }
        sort( d , d + ct );
        int ans = 1 + unique( d , d + ct ) - d;
        cout << ans << '\n';
        
    }
    
    return 0;
}
