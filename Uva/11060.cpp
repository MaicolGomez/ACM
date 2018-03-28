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
#define fi first
#define se second
#define MOD 10009
#define N 105

bool vis[N];
vi adj[N];
int in[N];

void clean(int n){
    me(in,0);
    for(int i = 0 ; i < n ; i++)
        adj[i].clear();
}

int main(){
    int n , m , test = 0;
    while( sc(n) == 1 ){
        clean( n );
        map<string ,int > M;
        map<int,string> I;
        char s[52];
        for(int i = 0 ; i < n ; i++){
            scanf("%s",s);
            M[s] = i;
            I[i] = s;
        }
        sc(m);
        char a[52] , b[52];
        for(int i = 0 ; i < m ; i++){
            scanf("%s%s",a,b);
            adj[ M[a] ].pb( M[b] );
            in[ M[b] ]++;
        }
        
        priority_queue<int> Q;
        for(int i = 0 ; i < n ; i++)
            if( in[i] == 0 ) Q.push( -i );
        
        printf("Case #%d: Dilbert should drink beverages in this order:",++test);
        
        while( !Q.empty() ){
            int u = Q.top(); Q.pop();
            u = -u;
            printf(" %s", I[u].c_str() );
            for(int i = 0 ; i < adj[u].size() ; i++){
                int v = adj[u][i];
                in[v]--;
                if( in[v] == 0 ) Q.push( -v );
            }
        }

        printf(".\n\n");
        
    }
    return 0;
}
