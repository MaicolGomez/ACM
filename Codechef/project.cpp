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
#define N 101

ll C[N][N];
ll A[N];

int main(){
    C[0][0] = 1;
    int r = 0;
    for(int i = 1 ; i <= 65 ; i++){
        C[i][0] = C[i][i] = 1;
        ll x = 1;
        bool end = 0;
        for(int j = 1 ; j < i ; j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            x = max( x , C[i][j] );
            if( C[i][j] >= (ll)(1e18) ) end = 1;
        }
        A[i] = x;
        if( end ) break;
    }
    int tc;
    sc(tc);
    while( tc-- ){
        ll n;
        scl(n);
        if( n == 2 ) printf("2\n");
        else{
            for(int i = 1 ; i <= 65 ; i++)
                if( A[i] >= n ){
                    printf("%d\n",i);
                    break;
                }
        }
    }
    return 0;
}
