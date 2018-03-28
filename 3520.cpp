#include<bits/stdc++.h>
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
#define ios ios::sync_with_stdio(0)
#define N 100000

int dx[4] = { -1 , 0 , 1 , 0 };
int dy[4] = { 0 , -1 , 0 , 1 };
string s = "ULDR";

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n , m;
        scanf("%d%d",&n,&m);
        vector< vi > v = vector< vi > ( n , vi ( m, 0 ) );
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                sc(v[i][j]);
        
        int x , y;
        scanf("%d%d",&x,&y); x--,y--;
        vector< vector<bool> > vis = vector< vector< bool > > ( n , vector<bool> ( m , 0 ) );
        queue< pair< pii , string > > Q;
        Q.push( mp( mp( x , y ) , "" ) );
        string ans;
        while( !Q.empty() ){
            pair< pii , string > q = Q.front();
            Q.pop();
            int u = q.fi.fi , vv = q.fi.se;
            string r = q.se;
            vis[u][vv] = 1;
            if( u == 0 or u == n - 1 or vv == 0 or vv == m - 1 ){
                if( u == 0 ) r += "U";
                else if( u == n - 1 ) r += "D";
                else if( vv == 0 ) r += "L";
                else r += "R";
                ans = r;
                break;
            }
            if( s.size() >= 200 ) continue;
            for(int i = 0 ; i < 4 ; i++){
                int p = u + dx[i] , q = vv + dy[i];
                if( p >= 0 and p < n and q >= 0 and q < m and !v[p][q] and !vis[p][q] ){
                    string k = r + s[i];
                    Q.push( mp( mp( p , q ) , k ) );
                }
            }
        }
        for(int i = 0 ; i < ans.size() ; i++){
            if( i ) printf(" ");
            printf("%c",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
