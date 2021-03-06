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
#define NMAX 5005

vector<int> adj[NMAX];
vector<int> articulation;
bool visited[NMAX];
int d[NMAX] , lowpt[NMAX] , pi[NMAX];
int timer , n;

void dfs(int u) {
    int sons=0, v;
    bool art = false;
    visited[u] = true; lowpt[u] = d[u] = timer++;
    for( int i = 0 ; i < adj[u].size() ; i++){
        v = adj[u][i];
        if(!visited[ adj[u][i] ]){
            sons++;
            pi[v] = u;
            dfs(v);
            lowpt[u] = min( lowpt[u] ,  lowpt[v] );
            if ( (pi[u] != -1) && (lowpt[v] >= d[u])) art = true;
        }
        else if ( v!= pi[u] ) lowpt[u] = min( lowpt[u] , d[v]);
    }
    if( art ) articulation.push_back(u);
    else if (pi[u] == -1 && sons > 1 ) articulation.push_back(u);
}

void articulations(){
    articulation.clear();
    timer = 0;
    for(int i = 0 ; i <= n ; i++){
        visited[i] = false;
        pi[i] = -1;
    }
    for(int i = 1 ; i <= n ; i++)
        if( !visited[i] )
            dfs(i);
    sort(all(articulation));
    printf("%d", int( articulation.size() ));
    for(int i = 0 ; i < articulation.size() ; i++)
        printf(" %d",articulation[i]);
    printf("\n");
}

char S[NMAX];

int main(){
    int m , k;
    while(sc(n) == 1 && n){
        
        for(int i = 0 ; i <= n ; i++) adj[i].clear();
        int x , y;
        gets(S);
        while( gets(S) ){
            if( S[0] == '0' ) break;
            stringstream in(S);
            in >> x;
            while( in >> y ){
                adj[x].pb(y);
                adj[y].pb(x);
            }
        }
        articulations();
    }
    return 0;
}
