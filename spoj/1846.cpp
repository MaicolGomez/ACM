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
#define N 1005

vi adj[N];
int in[N];

void clean(int n){
    me(in,0);
    for(int i = 0 ; i < n ; i++)
        adj[i].clear();
}

int test = 0;
bool solve(){
    int n , m;
    if( scanf("%d%d",&n,&m) != 2 ) return 0;
    if(test++) cout << endl;   
    clean( n );
    for(int i = 0 ; i < m ; i++){
        int x , t , y;
        cin >> x; x--;
        cin >> t;
        for(int j = 0 ; j < t ; j++){
            cin >> y; y--;
            adj[ y ].pb( x );
            in[x]++;
        }
    }
    priority_queue<int> Q;
    for(int i = 0 ; i < n ; i++)
        if( in[i] == 0 ) Q.push( -i );
        
    bool first = 0;
    while( !Q.empty() ){
        int u = Q.top(); Q.pop();
        u = -u;
        if( first ) cout << " ";
        cout << u + 1;
        first = 1;
        for(int i = 0 ; i < adj[u].size() ; i++){
            int v = adj[u][i];
            in[v]--;
            if( in[v] == 0 ) Q.push( -v );
        }
    }
    cout << endl;
    return 1;
}

int main(){
    while( solve() ){}
    return 0;
}
