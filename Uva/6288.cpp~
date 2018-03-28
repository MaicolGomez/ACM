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
#define N 1005

int n , S = 0;
vi adj[N];

int dfs(int x,int pa = -1){
    
    if( adj[x].size() == 0 ) return 1;
    
    int ret = 0 , soon = 0;
    for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
        int v = adj[u][i];
        if( v == pa ) continue;
        ret += dfs( v , u );
        soon++;
    }
    S += ret + 2 + soon - 1;
    return ret + 2 + soon - 1;
}

int main(){
    int tc;
    sc(tc);
    while(tc--){
        sc(n);
        int x , y;
        for(int i = 0 ; i < n - 1 ; i++){
            sc(x),sc(y);
            adj[x].pb(y);
        }
        S = 0;
        dfs(0);
        printf("%d\n",S);
    }
    return 0;
}
