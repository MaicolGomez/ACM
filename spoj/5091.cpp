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
#define N 100000

ll t[N+5][5];
int P[5] = { 2 , 3 , 6 , 7 , 8 };

int main(){

    for(int i = 0 ; i < 5 ; i++)
        t[0][i] = 1;
        
    for(int i = 1 ; i <= N ; i++)
        for(int j = 4 ; j >= 0 ; j--)if( i - P[j] >= 0 )
            t[i][j] += t[i - P[j]][j] + ((j<4)?t[i][j+1]:0);
            
    int n , tc;
    sc(tc);
    while(tc--){
        sc(n);
        printf("%lld\n",t[n][0]);
    }
    return 0;
}
