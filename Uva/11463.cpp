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
#define N 105

int d[N][N];

int main(){
    int tc , n , m;
    sc(tc);
    for(int test = 1 ; test <= tc ; test++){
        sc(n);
        sc(m);
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++){
                if( i == j ) d[i][j] = 0;
                else d[i][j] = inf;
            }
        int a , b;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&a,&b);
            d[a][b] = d[b][a] = 1;
        }
        
        int s , t;
        scanf("%d%d",&s,&t);
        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    d[i][j] = min( d[i][j] , d[i][k] + d[k][j] );
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            ans = max( ans , d[s][i] + d[i][t] );
        printf("Case %d: %d\n",test,ans);
    }
    return 0;
}
