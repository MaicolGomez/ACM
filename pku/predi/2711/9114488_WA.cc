#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<deque>
#include<string>
using namespace std;
int T,S,R,C,d;
vector<int> adj[805];
int cap[805][805];
bool vis[805];
bool conec[805][805];
#define inf 100
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int dispo[805][805];

int dfs(int u,int predi){
    if(u==T) return predi;
    if(vis[u]) return 0;
    vis[u]=1;
    vector<int> &v=adj[u];
    for(int i=0;i<v.size();i++){
        int vec=v[i];
        if(cap[u][vec]<=0) continue;
        int r=dfs(vec,min(predi,cap[u][vec]));
        if(r>0){
            cap[u][vec]-=r;
            cap[vec][u]+=r;
            return r;
        }
    }
    return 0;
}


int maxFlow(){
    int flow=0;
    while(1){
        memset(vis,0,sizeof(vis));
        int r=dfs(S,inf);
        if(!r) break;
        flow+=r;
    }
    return flow;
}

void make(int x,int y,int c){
    adj[x].push_back(y);
    adj[y].push_back(x);
    cap[x][y]=c;
    cap[y][x]=0;
}
int cont=0;
void asigna(int nodo,int c,int x,int y,int t){
    if(c==d) return;
    for(int i=0;i<4;i++){
        int u = x+dx[i];
        int v = y+dy[i];
        if(u>=0&&u<R&&v>=0&&v<C){
            int r=C*u+v;
            if(dispo[u][v]>0)make(nodo,r,t);
            asigna(nodo,c+1,u,v,t);
        }
        else if(!conec[nodo][T]){
            make(nodo,T,t);
            conec[nodo][T]=1;
        }
    }
}

void doit(int caso){
    string s;
    scanf("%d%d",&R,&d);
    memset(conec,0,sizeof(conec));
    int a;
    bool clean=0;
    vector<string> vv;
    for(int i=0;i<R;i++){
        cin >> s;
        vv.push_back(s);
        if(!clean){
            clean=1;
            C=(int)s.length();
            S=2*R*C;
            T=S+1;
            for(int j=0;j<=T;j++) adj[j].clear();
        }
        for(int j=0;j<C;j++){
            a=s[j]-'0';
            dispo[i][j]=a;
            int c=C*i+j;
            make(c,c+R*C,a);
        }
    }
    int lizards=0;
    for(int i=0;i<R;i++){
        cin >> s;
        for(int j=0;j<C;j++){
            if(s[j]=='L'){
                lizards++;
                int c=C*i+j;
                make(S,c,1);
            }
        }
    }
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(vv[i][j]!='0'){
                conec[C*i+j+R*C][C*i+j]=1;
                asigna(C*i+j+R*C,0,i,j,dispo[i][j]);
            }
    int t=maxFlow();
    t=lizards-t;
    if(t==0) printf("Case #%d: no lizard was left behind.\n",caso);
    else{
        if(t==1) printf("Case #%d: 1 lizard was left behind.\n",caso);
        else printf("Case #%d: %d lizards were left behind.\n",caso,t);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){doit(i);}
}

