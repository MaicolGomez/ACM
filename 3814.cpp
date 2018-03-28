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
#define MOD 10001
#define ios ios::sync_with_stdio(0);
#define N 10001

int main(){
    int n;
    while( sc(n) == 1 ){
        vi x(n);
        for(int i = 0 ; i < n ; i++) sc(x[i]);
        bool solve = 0;
        for(int a = 0 ; a < N and !solve ; a++)
            for(int b = 0 ; b < N ; b++){
                if( solve ) break;
                int y = x[0];
                bool ok = 1;
                for(int i = 0 ; i < n ; i++){
                    if( y != x[i] ){ ok = 0; break; }
                    y = ( a * y + b ) % MOD;
                    y = ( a * y + b ) % MOD;
                }
                if( ok ){
                    for(int i = 0 ; i < n ; i++)
                        printf("%d\n", (a * x[i] + b) % MOD );
                    
                    solve = 1;
                    break;
                }
            }
    }
    return 0;
}
