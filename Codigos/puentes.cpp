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
