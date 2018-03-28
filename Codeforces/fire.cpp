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
#define ios ios::sync_with_stdio(0);
#define N 2101

int d[N][N];
bool vis[N][N];
int dx[8] = { 1 , -1 , 0 , 0 };
int dy[8] = { 0 , 0 , 1 , -1 };

int main(){
    freopen( "input.txt" , "r" , stdin );
    freopen( "output.txt" , "w" , stdout );
    int n , m;
    while( scanf("%d%d",&n,&m) == 2 ){
        int k , x , y , maxi = -1 , xx , yy;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
             d[i][j] = inf;
        sc(k);
        
        for(int i = 0 ; i < k ; i++){
            scanf("%d%d",&x,&y); x--,y--;
            for(int j = 0 ; j < n ; j++)
                for(int k = 0 ; k < m ; k++)
                    d[j][k] = min( d[j][k] , abs(x-j) + abs(y-k) );
        }
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if( d[i][j] > maxi ) maxi = d[i][j] , xx = i , yy = j;
            
        cout << xx + 1 << " " << yy + 1 << '\n';
    }
    return 0;
}
