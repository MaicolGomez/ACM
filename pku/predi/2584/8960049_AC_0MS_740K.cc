#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
#define oo 100
int c[50][50];
vector<int> adj[50];
map<char , int > M;
bool vis[50];
int S , T;

int path(int x,int hastaX){//devuelve en el tramo: x->T
    if(x==T)return oo;
    if(vis[x])return 0;
    vis[x]=1;
    vector<int> &v=adj[x];
    for(int i=0;i<v.size();++i){
        int y=v[i];
        if(!c[x][y])continue;
        int z=path(y,min(c[x][y],hastaX));
        if(z>0){
            int desdeX=min(c[x][y],z);           
            int mini=min(hastaX,desdeX);
            c[x][y]-=mini;
            c[y][x]+=mini;
            return desdeX;
        }
    }
    return 0;
}

int maxFlow(){
    int flow=0;
    while(1){
    	memset(vis,0,sizeof(vis));
        int val=path(S,oo);
        if(!val)break;
        flow+=val;
    }
    return flow;
}

int asigna(char g){
    if(g == 'S') return 0;
    if(g == 'M') return 1;
    if(g == 'L') return 2;
    if(g == 'X') return 3;
    if(g == 'T') return 4;
}

void conecta(int nodo , int x , int y){
    for(int i = x; i <= y ; i++){
        adj[i].push_back(nodo);
        adj[nodo].push_back(i);
        c[i][nodo] = 1;
        c[nodo][i] = 0;
    }
}

void doit(){
    for(int i = 0 ; i < 50 ; i++) adj[i].clear();
    int x , a;
    string s;
    cin >> x;
    S = 5 + x , T = S + 1;
    for(int i = 5 ; i < 5 + x ; i++){
        adj[i].push_back(T);
        adj[T].push_back(i);
        c[i][T] = 1;
        c[T][i] = 0;
        cin >> s;
        int p = asigna(s[0]);
        int q = asigna(s[1]);
        conecta(i, p , q );
    }
    for(int i = 0 ; i < 5 ; i++){
        cin >> a;
        adj[S].push_back(i);
        adj[i].push_back(S);
        c[S][i] = a;
        c[i][S] = 0;
    }
    cin >> s;
    /*for(int j = 0 ; j<= T ; j++){
        for(int i = 0 ; i < adj[j].size() ; i++) cout<<j<<"-->"<<adj[j][i]<<"  cap: "<<c[j][adj[j][i]]<<endl;
    }*/
    if(maxFlow() == x ) puts("T-shirts rock!");
    else puts("I'd rather not wear a shirt anyway...");
}

int main(){
    string s;
    while(cin >> s){
        if( s == "ENDOFINPUT" ) break;
        doit();
    }
}
