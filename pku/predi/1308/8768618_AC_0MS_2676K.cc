#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

vector<int> v[1000];
bool m[1001][1001];
int vis[1001];
void dfs( int source ){
    for(int i = 0 ; i < v[source].size() ; i++){
        int vecino = v[source][i];
        if( m[source][vecino] || m[vecino][source] ) continue;
        m[source][vecino] = 1;
        m[vecino][source] = 1;
        vis[vecino]++;
        dfs( vecino );
    }
}

int main(){
    int a , b , c , d;
    int test = 0;
    bool nodo[1001];
    bool conex[1001][1001];
    while( scanf("%d%d",&a,&b) == 2 ){
        test++;
        bool ok = 0;
        if(a == b && a == 0 )goto x;
        if( a == b && a == -1 ) break;  
        memset( m , 0 , sizeof(m) );
        memset( conex , 0 , sizeof(conex) );
        memset( vis,  0 , sizeof(vis) );
        memset( nodo, 0 , sizeof(nodo) );
        for(int i = 0 ; i < 1000; i++) v[i].clear();
        nodo[a] = 1;
        nodo[b] = 1;
        conex[a][b] = 1;
        conex[b][a] = 1;
        v[a].push_back(b);
        v[b].push_back(a);
        while( scanf("%d%d",&c,&d) == 2 ){
            if( d == 0 && c == 0 ) break;
            if( conex[c][d] || conex[d][c] ) ok = 1;
            conex[c][d] = 1;
            conex[d][c] = 1;
            v[c].push_back(d);
            v[d].push_back(c);
            nodo[c] = 1; 
            nodo[d] = 1;
        }
        dfs( a );
        vis[a]++;
        for( int i = 0 ; i <= 1000 ; i++) if( nodo[i] ) if( vis[i] == 0 ) ok = 1; 
        for( int i = 0 ; i <= 1000 ; i++) if( vis[i] >= 2 ) ok = 1;
        x:;
        if( !ok ) cout<<"Case "<<test<<" is a tree."<<endl;
        else cout<<"Case "<<test<<" is not a tree."<<endl;
    }
}
