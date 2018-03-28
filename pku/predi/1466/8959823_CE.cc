#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int n , S , T;
vector<int> adj[600];
int cap[600][600];
int sexo[600];
bool vis[600];

bool find(int u){
    if( u == T ) return 1;
    if( vis[u] ) return 0;
    vis[u] = 1;
    vector<int> &v = adj[u];
    for(int i = 0 ; i < v.size() ; i++){
        int vec = v[i];
        if( cap[u][vec] > 0 && find(vec) ){
            cap[u][vec]--;
            cap[vec][u]++;
            return 1;
        }
    }
    return 0;
}

int maxFlow(){
    int flow = 0;
    memset( vis , 0 , sizeof(vis) );
    while( find( S ) ){
        memset( vis , 0 , sizeof(vis) );
        flow++;
    }
    return flow;
}

void f(){
    int a , b , c;
    scanf("%d: (%d)",&a,&b);
    sexo[a] = -1;
    for(int i = 0 ; i < b; i++){
        scanf("%d",&c);
        adj[a].push_back(c);
    }
}

void color(int u , int sex){
    if( sexo[u] != -1 ) return;
    sexo[u] = sex;
    for(int i = 0 ; i < adj[u].size() ; i++) color( adj[u][i] , 1 - sex );
}

void g(int x , int y){
    cap[x][y] = 1;
    cap[y][x] = 0;
}

void doit(){
    S = n , T = n+1;
    for(int i = 0 ; i <= n+1 ; i++) adj[i].clear();
    for(int i = 0 ; i < n ; i++) f();
    for(int i = 0 ; i < n ; i++) color(i,0);
    for(int i = 0 ; i < n ; i++){
        if(sexo[i]){
            adj[i].push_back(T);
            adj[T].push_back(i);
            g( i , T );
        }
        else{
            vector<int> &v = adj[i];
            for(int j = 0 ; j < v.size() ; j++) g( i , v[j] );
            adj[S].push_back(i);
            adj[i].push_back(S);
            g( S , i );
        }
    }
    /*for(int j = 0 ; j<= n+1 ; j++){
        for(int i = 0 ; i < adj[j].size() ; i++) cout<<j<<"-->"<<adj[j][i]<<" "<<sexo[j]<<" "<<sexo[adj[j][i]]<<"  cap: "<<cap[j][adj[j][i]]<<endl;
    }*/
    printf("%d\n", n - maxFlow() );
}

int main(){
    memset(cap , 0 , sizeof(cap) );
    while( scanf("%d",&n) == 1 ) doit();
}
