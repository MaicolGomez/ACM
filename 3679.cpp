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
#define N 100001
#define C 2000

int t[105][2055] , a[105];

int main(){
    int tc , test = 1 , n;
    sc(tc);
    while(tc--){
        sc(n);
        int sum = 0 , z = 0;
        for(int i = 1 ; i < n + 1 ; i++)
            sc(a[i]) , z += a[i] == 0 , sum += a[i];
        
        me(t,-1);
        t[0][0] = 0;
        
        for(int i = 1 ; i < n + 1 ; i++){
            for(int j = 0 ; j <= sum + 1 ; j++){
                if( t[i-1][j] != -1 and j + a[i] <= sum )
                    t[i][j + a[i]] = max( t[i-1][j] , t[i][j+a[i]]  );
                
                if( t[i-1][j] != -1 ){
                    if( j - a[i] >= 0 ) t[i][j - a[i]] = max( t[i][j - a[i]] , t[i-1][j] + a[i] );
                    if( a[i] - j >= 0 ) t[i][a[i] - j] = max( t[i][a[i] - j] , t[i-1][j] + j );
                    t[i][j] = max( t[i][j] , t[i-1][j] );
                }
            }
        }
        if( t[n][0] == 0 and z == 0 ) t[n][0] = -1;
        printf("Case %d: %d\n",test++,t[n][0]);
        
        
    }
    return 0;
}
