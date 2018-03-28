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
int T,S;
vector<int> adj[405];
int cap[405][405];
#define inf 100
map<char,int> M;

int bfs(){
    deque<int> Q(1,S);
    vector<int> p(T+2,-2);
    p[S]=-1;
    int r=inf;
    while(!Q.empty()){
        int u=Q.front();
        if(u==T) break;
        Q.pop_front();
        vector<int> &v=adj[u];
        for(int i=0;i<v.size();i++){
            int vec=v[i];
            if(p[vec]==-2&&cap[u][vec]>0){
                r=min(r,cap[u][vec]);
                p[vec]=u;
                Q.push_back(vec);
            }
        }
    }
    if(Q.empty()) return 0;
    int x=T;
    while(x!=S){
        cap[p[x]][x]-=r;
        cap[x][p[x]]+=r;
        x=p[x];
    }
    return r;
}

int maxFlow(){
    int flow=0;
    while(1){
        int r=bfs();
        if(!r)break;
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

void doit(){
    int n;
    scanf("%d",&n);
    S=0;
    T=6+n;
    string s;
    for(int i=0;i<=T;i++)adj[i].clear();
    for(int i=0;i<n;i++){
        cin >> s;
        int a=M[s[0]];
        int b=M[s[1]];
        for(int j=a;j<=b;j++){
            make(j,6+i,1);
        }
        make(6+i,T,1);
    }
    for(int i=1;i<6;i++){
        int r;
        scanf("%d",&r);
        make(S,i,r);
    }
    cin >> s;
    int t=maxFlow();
    puts(t==n?"T-shirts rock!":"I'd rather not wear a shirt anyway...");
}

int main(){
    string s;
    M['S']=1,M['M']=2,M['L']=3,M['X']=4,M['T']=5;
    while(cin >> s){
        if(s=="ENDOFINPUT")break;
        doit();
    }
}
