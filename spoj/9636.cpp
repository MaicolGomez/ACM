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
#define N 62;

int n , t[N][N][N] , a[N];

int f(int L1,int L2,int R1,int R2){

    
}

int main(){
    a[0] = 0;
    while( sc(n) == 1 && n != -1 ){
        for(int i = 1 ; i <= n ; i++)
            sc(a[i]);
        
        sort( a + 1 , a + 1 + n );
        for(int i = 0 ; i <= n ; i++)
            for(int j = 0 ; j <= n ; j++)
                for(int k = 0 ; k <= n ; k++)
                    me( t[i][j][k] , -1 );
        int ans = f( 0 , 0 , 0 , 0 );
    }
    return 0;
}
