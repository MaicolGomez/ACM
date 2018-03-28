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
#define N 10005
#define ALF 27
char s[N];
int R[N][ALF];
int A[ALF] , B[N][ALF];

int main(){
    int tc;
    sc(tc);
    while(tc--){
        scanf("%s",s);
        me(A,0);
        me(B,0);
        me(R,0);
        int n = strlen(s) , x = 0;
        for(int i = 0 ; i < n ; ){
            while( i < n && s[i] != '#' )
                R[x][ s[i++] - 'a' ]++;
            x++;
            i++;
        }
        for(int i = n - 1 ; i >= 0 ; i--)
            for(int j = 0 ; j < ALF ; j++)
                B[i][j] = B[i+1][j] + R[i][j];
        
        int ans = 0;
        for(int i = 0 ; i + 4 <= x ; i++){
            int m1 = 0 , m2 = 0;
            for(int j = 0 ; j < ALF ; j++){
                A[j] += R[i][j];
                m1 = max( m1 , A[j] );
                m2 = max( m2 , B[i+3][j] );
            }
            int S = 0;
            int r1 = 0 , r2 = 0;
            for(int j = 0 ; j < ALF ; j++){
                r1 = max( r1 , R[i+1][j] );
                r2 = max( r2 , R[i+2][j] );
            }
            if( r1 == 0 || r2 == 0 || m1 == 0 || m2 == 0 ) continue;
            S = r1 + r2 + m1 + m2;
            if( S + 3 > ans ) ans = S + 3;
        }
        printf("%d\n",ans);
    }
    return 0;
}
