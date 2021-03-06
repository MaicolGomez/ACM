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
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0)

int N,M;
vector<vi> conn;

vi match, vis;

bool dfs(int n) {
  if(vis[n]) return false;
  vis[n]=1;
  for(int i = 0 ; i < M ; i++) if(conn[n][i] && match[i]==-1) { match[i]=n; return true; }
  for(int i = 0 ; i < M ; i++) if(conn[n][i] && dfs(match[i])) { match[i]=n; return true; }
  return false;
}

int matching() {
  int res=0;
  match = vi(M,-1);
  for(int i = 0 ; i < N ; i++) if( vis = vi(N) , dfs(i)) res++;
  return res;
}
int main(){
    ios;
    int tc;
    cin >> tc;
    while( tc-- ){
        int c , d , V , x , y;
        cin >> c >> d >> V;
        char a , b;
        vi clove , chate , dlove , dhate;
        for(int i = 0 ; i < V ; i++){
            cin >> a >> x >> b >> y;
            if( a == 'C' ) clove.pb( x ) , chate.pb( y );
            else dlove.pb( x ) , dhate.pb( y );
        }
        N = clove.size() , M = dlove.size();
        conn = vector<vi> (N , vi(M,0) );
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < M ; j++)
                if( clove[i] == dhate[j] or chate[i] == dlove[j] ) conn[i][j] = 1;
        
        cout << V - matching() << "\n";
    }
    return 0;
}
