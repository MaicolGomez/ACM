//http://acm.tju.edu.cn/acm/showp1706.html
#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool ok ;
int n,x,a,b,sexo[2005];
vector<int> adj[2005];

void dfs(int nodo, int sex ){
    if(!ok) return;
    if( sexo[nodo] != -1 ){
        if( sexo[nodo] != sex ) ok = 0;
        return;
    }
    sexo[nodo] = sex;
    vector<int> &v = adj[nodo];
    for(int i = 0 ; i < v.size() ; i++) dfs( v[i] , 1-sex );
}

void doit(){
    ok = 1;
    scanf("%d%d",&n,&x);
    for(int i = 0 ; i <= n ; i++) adj[i].clear();
    for(int i = 0 ; i < x ; i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset( sexo , -1 , sizeof(sexo) );  
    for(int i = 1 ; i <= n ; i++){
        //cout<<"nodo: "<<i<<endl;
        if( sexo[i] == -1 ) dfs(i , 0);
    }
    if(ok)puts("No suspicious bugs found!"); 
    else puts("Suspicious bugs found!");
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 1 ; i <= t ; i++){
        printf("Scenario #%d:\n",i);
        doit();
        puts("");
    }
}
