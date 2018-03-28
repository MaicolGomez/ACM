#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;

char t[81][1001];
bool vis[81][1001];
struct nodo{
    int x , y;
        nodo(int X , int Y){
            x = X;
            y = Y;
        }
};

int dx[4]={-1,0,1, 0};
int dy[4]={ 0,1,0,-1};
int r , c;
    
int f(int p , int q ){
    vis[p][q] = 1;
    int ct = 1;
    deque <nodo> Q;
    Q.push_back( nodo( p , q ) );
    while( !Q.empty() ){
        nodo m = Q.front();
        Q.pop_front();
        for(int i = 0 ; i < 4 ; i++){
            int u = m.x + dx[i];
            int v = m.y + dy[i];
            if( u >= 0 && u < r && v >=0 && v < c && vis[u][v] == 0 && t[u][v] == '*' ){
                //cout<<u<<" "<<v<<endl;
                vis[u][v] = 1;
                ct++;
                Q.push_back( nodo(u,v) );
            }
        }
    }
    //cout<<endl;
    return ct;
}

int main(){
    char p;
    cin >> c >> r;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cin >> p;
            t[i][j] = p;
            //cout<<t[i][j];
        }
        //cout<<endl;
    }
    memset( vis , 0 , sizeof(vis) );
    int res = 0;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            if( t[i][j] == '*' && vis[i][j] == 0  ) res = max( res , f( i , j) );
        }
    }
    cout<<res<<endl;
}
