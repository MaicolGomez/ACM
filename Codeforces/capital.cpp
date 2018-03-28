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
#define N 200005

int n;
vector< pii > adj[N];
int A[N] , ct , best;

int dfss(int u , int pa){
    
    int ret = 0;
    for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
        int v = adj[u][i].fi;
        if( v == pa ) continue;
        ret += (adj[u][i].se == 0);
        ret += dfss( v , u );
    }
    return ret;
}

void dfs(int u,int have,int pa){
    if( have < best ){
        best = have;
        ct = 0;
        A[ct++] = u;
    }
    else if( have == best ) A[ct++] = u;
    
    for(int i = adj[u].size() -  1 ; i >= 0 ; i--){
        int v = adj[u][i].fi;
        if( v == pa ) continue;
        if( adj[u][i].se ) dfs( v , have + 1 , u );
        else dfs( v , have - 1 , u );
    }

}

int main(){
    while( sc(n) == 1 ){
        int x , y;
        for(int i = 0 ; i < n + 1 ; i++)
            adj[i].clear();
        for(int i = 0 ; i < n - 1 ; i++){
            scanf("%d%d",&x,&y);
            adj[x].pb( mp(y,1) );
            adj[y].pb( mp(x,0) );
        }
        best = dfss( 1 , -1 );
        ct = 0;
        dfs( 1 , best , -1 );
        printf("%d\n",best);
        sort( A , A + ct );
        for(int i = 0 ; i < ct ; i++){
            if(i) printf(" ");
            printf("%d",A[i]);
        }
        printf("\n");
    }
    return 0;
}
