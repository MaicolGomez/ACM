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

#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 2055

int R , C , S[N][N] , a[N][N];

int main(){
    while( scanf("%d%d",&R,&C) == 2 and (R||C) ){
    
        for(int i = 1 ; i < R + 1 ; i++)    
            for(int j = 1 ; j < C + 1 ; j++)
                sc(a[i][j]);
        
        me(S,0);
        for(int i = 1 ; i < R + 1 ; i++)
            for(int j = 1 ; j < C + 1 ; j++)
                S[i][j] = a[i][j] + S[i-1][j] + S[i][j-1] - S[i-1][j-1];
        
        int ans = 0;
        for(int i = 1 ; i < R + 1 ; i++)
            for(int j = 1 ; j < C + 1 ; j++)if( a[i][j] ){
                int lo = 0 , hi = min( R - i , C - j  ) + 2;
                while( lo + 1 < hi ){
                    int mid = M(hi,lo);
                    if( S[i+mid-1][j+mid-1] - S[i+mid-1][j-1] - S[i-1][j+mid-1] + S[i-1][j-1] == Q(mid) ) lo = mid;
                    else hi = mid;
                }
                ans = max( ans , lo );
            }
        printf("%d\n",ans);
    }
    return 0;
}
