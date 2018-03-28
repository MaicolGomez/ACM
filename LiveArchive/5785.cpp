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
#define N 105

int d[N][N] , p[N] , C[N][N];

int main(){
    int n , test = 0;
    while( sc(n) == 1 and n ){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                sc(d[i][j]);
                if( d[i][j] == 0 ) d[i][j] = inf;
                else C[i][j] = d[i][j];
            }
            d[i][i] = 0;
        }
        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    d[i][j] = min( d[i][j] , d[i][k] + d[k][j] );
        int x;
        sc(x);
        for(int i = 0 ; i < x ; i++)
            sc(p[i]);
        
        int cur = 0 , ans = 0;
        while(1){
            int st = p[cur];
            while( cur < x - 1 and d[st][ p[cur] ] +  C[ p[cur] ][ p[cur+1] ] == d[ st ][ p[cur+1] ] )
                cur++;
            if( cur != x - 1 ) cur++, ans++;
            if( cur == x - 1 ) break;
        }
        printf("Case %d: %d\n",++test,ans);
    }
    return 0;
}
