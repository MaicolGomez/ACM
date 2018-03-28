
int n , m , comp[N+10] , ncomp , in[N+10] , cost[N+5], mini[N+5];
vi adj[N+10] , adjT[N+10];
bool vis[N+10];
stack<int> nodes;
void clean(){
    for(int i = 0 ; i < n ; i++){
        mini[i] = inf;
        adj[i].clear();
        adjT[i].clear();
    }
    me(vis,0);
    me(in,0);
}

void dfs1(int u){
    vis[u] = 1;
    for(int i = 0 ; i < adj[u].size() ; i++) if( !vis[ adj[u][i] ] ) dfs1( adj[u][i] );
    nodes.push(u);
}

void dfs2(int u){
    vis[u] = 0;
    for(int i = 0 ; i < adjT[u].size() ; i++) if( vis[ adjT[u][i] ] ) dfs2( adjT[u][i] );
    comp[u] = ncomp;
}

void solve(){
    for(int i = 0 ; i < n ; i++) if( !vis[i] ) dfs1( i );
    ncomp = 0;
    while( !nodes.empty() ){
        int q = nodes.top();
        nodes.pop();
        if( vis[ q ] ){
            dfs2(q);
            ++ncomp;
        }
    }
    for(int i = 0 ; i < n ; i++){
        mini[ comp[i] ] = min( mini[ comp[i] ] , cost[i] );
        for(int j = 0 ; j < adj[i].size() ; j++){
            if( comp[i] != comp[ adj[i][j] ] ) in[ comp[ adj[i][j] ] ]++;
        }
    }
    int res = 0;
    for(int i = 0 ; i < ncomp ; i++) if( !in[i] ) res+=mini[i];
    printf("%d\n",res);
}

int main(){
    while( scanf("%d%d",&n,&m) == 2 && (n||m) ){
        clean();
        for(int i = 0 ; i < n ; i++) scanf("%d",&cost[i]);
        int x , y;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&x,&y);
            x--,y--;
            adj[x].pb(y);
            adjT[y].pb(x);
        }
        solve();
    }
}
