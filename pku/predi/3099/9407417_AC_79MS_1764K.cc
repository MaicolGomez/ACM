#include<iostream>
#include<cmath>
#include<cctype>
#include<deque>
#include<cstdio>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define inf (1<<30)

struct nodo{
 int x , y , z , id;
    nodo(int X , int Y, int Z , int ID){
        x = X; y = Y; z = Z; id = ID;    
    }
};

bool m[1001][1001];
vector<int> adj[1001];
int maxi[1001];
int a , b , c, d , pos, k , n;
vector <nodo> v;

int dis(nodo &p , nodo &q){
    int d = (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y) + (p.z-q.z)*(p.z-q.z);
    return d;
}

int bfs(int source){
    vector<int> di(1001,inf);
    deque <int> Q;
    Q.push_back(source);
    di[source]=0;    
    while( !Q.empty() ){
        int q = Q.front();
          Q.pop_front();
          for(int i = 0; i < adj[q].size() ; i++ ){
            int vec = adj[q][i];
            if( di[ vec ] > di[q] + 1 ){
                di[ vec ] = di[q] + 1;
                Q.push_back(vec);
            }
          }
    }
    int mayor = 0;
    for(int i = 0 ; i < n ; i++ ){
        mayor = max( mayor , di[v[i].id] );
    }
    return mayor;
}

void resuelve(){
    for(int i = 0; i < n ; i++ ){
        maxi[v[i].id] = bfs(v[i].id);
    }
    int menor = 2000000000;
    int r, s;
    for(int i = 0; i < n ; i++){
        if( maxi[v[i].id] < menor ){
            menor = maxi[v[i].id];
            r = v[i].id;
            s = -1;
            for(int j = i+1; j < n ; j++ ){
                    if( maxi[v[j].id] == menor && m[v[i].id][v[j].id] == 1){
                        s = v[j].id;
                        if( s < r){
                            swap(s,r);  
                        }                         
                    }
            }
        }
    }
    if( s != -1 ) printf("%d %d\n",r,s);
    else printf("%d\n",r);
}

void doit(){
    v.clear();
    memset( m , 0 , sizeof(m) );
    for(int i = 0 ; i < 1001 ; i++) adj[i].clear();
    scanf("%d%d%d%d",&a,&b,&c,&d);
    v.push_back( nodo(  b , c , d , a  ) );
    for(int i = 1; i < n ; i++){
        int menor = 2000000000;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        nodo p = nodo( b , c , d , a ) ;
        for(int j = 0; j < v.size() ; j++ ){
            k = dis(v[j] , p );
            if( k < menor ){
                menor = k;   
                pos = j;
            }
        }
        v.push_back( p );
        m[p.id][v[pos].id] = m[v[pos].id][p.id] = 1;
        adj[ p.id ].push_back( v[pos].id );
        adj[ v[pos].id ].push_back( p.id );
    }
    resuelve();      
}

int main(){
    while( scanf("%d",&n) ){
        if(n == 0) break;
        doit();    
    }          
}