#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
#define inf (1<<30)
#define eps 1e-8
#define ll long long

vector<int> adj[105];
bool vis[105];
int n;

void build(){
    for(int i = 0 ; i < n + 1 ; i++) adj[i].clear();
    int a[100] , ct = 0;
    while( 1 ){
        string s;
        getline( cin , s );
        stringstream in(s);
        int x , y;
        in >> x;
        while( in >> y ){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        if(s=="0") break;
    }
}

bool f(int x){
    int ct = 0;
    for(int i = 1 ; i <= n ; i++) ct+=(vis[i]);
    return (ct<n-1);
}

void dfs(int u , int x){
    if( vis[u] || u == x ) return;
    vis[u] = 1;
    vector<int> v = adj[u];
    for(int i = 0 ; i < v.size() ; i++) dfs( v[i] , x );
}

void solve(){
    int res = 0;
    for(int i = 1 ; i <= n ; i++){
        memset( vis , 0 , sizeof(vis) );
        dfs( (i==1)?(i+1):1 , i );
        res += f( i );
    }
    printf("%d\n",res);
}

int main(){
    while( scanf("%d",&n) == 1 ){  string s; getline(cin,s); // dummy
        if( n == 0 ) break;
        build();
        solve();
    }
}