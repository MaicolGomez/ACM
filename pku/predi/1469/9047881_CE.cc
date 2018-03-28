#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> adj[402];
int cap[402][402];
bool vis[402];
int S,T;

int dfs(int u,int predi){
    if(u==T)return predi;
    if(vis[u])return 0;
    vis[u] = 1;
    vector<int> &v=adj[u];
    for(int i = 0 ; i < v.size() ; i++){
        int vec = v[i];
        if(cap[u][vec]<=0) continue;
        int r = dfs(vec,min(predi,cap[u][vec]));
        if(r>0){
            cap[u][vec]-=r;
            cap[vec][u]+=r;
            return r;
        }
    }
    return 0;
}

int maxFlow(){
    int flow = 0;
    while(1){
        memset(vis,0,sizeof(vis));
        int r = dfs(S,10);
        if(!r)break;
        flow+=r;
    }
    return flow;
}

void make(int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
    cap[x][y] = 1;
    cap[y][x] = 0;
}

void doit(){
    int n , p;
    scanf("%d%d",&p,&n);
    S = n+p;
    T = S+1;
    for(int i = 0 ; i <= T ; i++) adj[i].clear();
    for(int i = 0 ; i < p ; i++){
        int t,a;
        scanf("%d",&t);
        for(int j = 0 ; j < t ; j++){
            scanf("%d",&a);
            make(i,p+a-1);
        }
        make(S,i);
    }
    for(int i = p ; i < p+n ; i++){
        make(i,T);
    }
    //cout<<maxFlow()<<endl;
    if(maxFlow()==p)puts("YES");
    else puts("NO");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){doit();}
}
