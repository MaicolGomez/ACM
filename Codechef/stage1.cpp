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
#define N 55

char s[N][N];

int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , -1 , 1 };

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int r , c;
        sc(r),sc(c);
        for(int i = 0 ; i < r ; i++)
            scanf("%s",s[i]);
        int ans = 0;
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++)if( s[i][j] != '#' ){
                int mini = inf;
                for(int k = 0 ; k < 4 ; k++){
                    int u = i + dx[k] , v = j + dy[k] , ct = 0;
                    while( u >= 0 and u < r and v >= 0 and v < c and s[u][v] == '^' ){
                        ct++;
                        u += dx[k] , v += dy[k];
                    }
                    mini = min( mini , ct );
                }
                if( mini >= 2 ) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
