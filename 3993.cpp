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

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n , m , x , y;
        scanf("%d%d",&n,&m);
        vector< int > adj[n];
        int in[n];
        me(in,0);
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&x,&y); x--,y--;
            cout << x << " -- " << y << endl;
            adj[x].pb( y );
            in[ y ]++;
        }
        cout << in[0] << " " << in[1] << " " << in[2] << endl;
        queue<int> Q;
        for(int i = 0 ; i < n ; i++){
            sort( all(adj[i]) );
            if( !in[i] ) Q.push( i );
        }
        int r = 0;
        bool can = 1;
        vector<bool> vis( n , 0 );
        vi ans;
        while( !Q.empty() ){
            int u = Q.front(); Q.pop();
            ans.pb( u );
            vis[u] = 1;
            r++;
            if( !can ) break;
            for(int i = 0 ; i < adj[u].size() ; i++){
                int v = adj[u][i];
                if( vis[v] ) can = 0;
                else{
                    in[v]--;
                    if( !in[v] ) Q.push( v );
                }
            }
        }
        if( r != n ) can = 0;
        if( can ){
            for(int i = 0 ; i < ans.size() ; i++){
                if( i ) printf(" ");
                printf("%d",ans[i]+1);
            }
            printf("\n");
        }
        else printf("Low IQ\n");
    }
    return 0;
}
