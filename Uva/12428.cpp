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

int main(){
    ll n , m;
    int tc;
    sc(tc);
    while(tc--){
        scanf("%lld%lld",&n,&m);
        if( m <= n - 1 )
            printf("%lld\n",m);
        else if( m * 2 >= n * n - n )
            printf("%d\n",0);
        else{
            for(ll i = 1 ; i <= n ; i++){
                if( i * (i-1) / 2 + n - i < m ){}
                else{
                    cout << n - i  << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
