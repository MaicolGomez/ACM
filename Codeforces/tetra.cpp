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
#define MOD 1000000007
#define N 10000000

int t[N+2][4];
/*
int f(int n,int last){
    if( n == 0 )
        return (last == 0);
    int &ret = dp[n][last];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = 0 ; i < 4 ; i++)if( i != last ){
        ret += f( n - 1 , i );
        if( ret >= MOD ) ret -= MOD;
    }
    return ret;
}
*/
int main(){
    int n;
    t[0][0] = 1;
    t[0][1] = 0;
    t[0][2] = 0;
    t[0][3] = 0;
    for(int n = 1 ; n <= N ; n++){
        for(int last = 0 ; last < 4 ; last++){
            for(int i = 0 ; i < 4 ; i++)if( i != last ){
                t[n][last] += t[n-1][i];
                if( t[n][last] >= MOD ) t[n][last] -= MOD;
            }
        }
    }
    
    while( sc(n) == 1 ){
        printf("%d\n", t[n][0] );
    }
    return 0;
}
