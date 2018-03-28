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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define N 55

int R , C;
bool used[N][N];
vector<string> m;
int dx[8] = { 1 , 1 , 1 , 0 , 0 , -1 , -1 , -1 };
int dy[8] = { 1 , 0 , -1 , 1 , -1 , 1 , 0 , -1 };

int dfs(int x,int y,char toy){
    if( toy == 'Z' ) return 26;
    used[x][y] = 1;
    int ans = int(toy - 'A') + 1;
    for(int i = 0 ; i < 8 ; i++){
        int u = x + dx[i] , v = y + dy[i];
        if( u >= 0 && u < R && v >= 0 && v < C && !used[u][v] && m[u][v] == toy + 1 ){
            ans = max( ans , dfs( u , v , toy + 1 ) );
        }
    }
    return ans;
}

int main(){
    int test = 0;
    while( cin >> R >> C ){
        if( R == 0 && C == 0 ) break;
        vector<string> v(R);
        for(int i = 0 ; i < R ; i++)
            cin >> v[i];
        m = v;
        int ans = 0;
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++)if( v[i][j] == 'A' ){
                me( used , 0 );
                int x = dfs( i , j , 'A' );
                ans = max( ans , x );
            }
        }
        cout << "Case " << ++test << ": " << ans << endl;
    }
    return 0;
}
