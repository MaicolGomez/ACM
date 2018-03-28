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

struct nodo{
 int x , y , z;
 int id;   
    nodo(int X , int Y, int Z , int ID){
        x = X;
        y = Y;
        z = Z;
        id = ID;    
    }
};

int m[1001][1001];
int d[1001];
int maxi[1001];
int n;
vector <nodo> v;

int dis(nodo p , nodo q){
    int d = (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y) + (p.z-q.z)*(p.z-q.z);
    return d;
}

int bfs(int source){
    deque <int> Q;
    Q.push_back(source);
    d[source]=0;    
    while( !Q.empty() ){
        int q=Q.front();
          Q.pop_front();
          for(int i = 0; i < n ; i++ ){
            if( m[q][v[i].id] == 1 && d[v[i].id] == -1 ){
                d[v[i].id] = d[q] + 1;
                Q.push_back(v[i].id);
            }        
          }
    }
    int mayor = 0;
    for(int i = 0 ; i < n ; i++ ){
        if( d[v[i].id] > mayor ) mayor = d[v[i].id];    
    }
    return mayor;
}

int aux;
void resuelve(){
    memset( d , -1 , sizeof(d) );
    for(int i = 0; i < n ; i++ ){
        maxi[v[i].id] = bfs(v[i].id);
        for(int j = 0 ; j < n ; j++){
            d[v[j].id] = -1;    
        }
    }
    int menor = 2000000000;
    int r, s;
    for(int i = 0; i < n ; i++){
        if( maxi[v[i].id] < menor ){
            menor = maxi[v[i].id];
            r = v[i].id;
            s = -1;
            for(int j = i+1; j < n ; j++ ){
                    if( j < 1001 && maxi[v[j].id] == menor && m[v[i].id][v[j].id] == 1){
                        s = v[j].id;
                        if( s < r){
                            aux = r;
                            r = s;
                            s = aux;    
                        }                         
                    }       
            }   
        }
    }
    if( s != -1 ) printf("%d %d\n",r,s);//cout<<r<<" "<<s<<endl;
    else printf("%d\n",r);//cout<<r<<endl;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            m[ v[i].id ] [v[j].id ] = 0;
            m[ v[j].id ] [v[i].id ] = 0;
        }    
    }
}

void doit(){
    int a , b , c , d;
    int pos;
    v.clear();
    //cin >> a >> b >> c >> d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    v.push_back( nodo(  b , c , d , a  ) );
    for(int i = 1; i < n ; i++){
        int menor = 2000000000;
        cin >> a >> b >> c >> d;
        nodo p = nodo( b , c , d , a ) ;
        for(int i = 0; i < v.size() ; i++ ){
            int k = dis(v[i] , p );
            if( k < menor ){
                menor = k;   
                pos = i;
                }
        }
        v.push_back( p );
        m[ p.id ][ v[pos].id ] = 1 ;
        m[ v[pos].id  ][ p.id ] = 1 ;
    }
    resuelve();      
}

int main(){
    while( scanf("%d",&n) ){
        if(n == 0) break;
        doit();    
    }          
}
