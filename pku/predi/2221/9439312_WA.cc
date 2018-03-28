#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<string>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-8
#define rana 1000
int m[11][11] , ini[11][11] , aux[11][11];

bool prueba(int col){
    memset(m,0,sizeof(m));
    for(int i = 1 ; i <= 8 ; i++) for(int j = 0 ; j < 10 ; j++) m[i][j] = ini[i][j];
    //cout<<"columna :"<<col<<endl;
    memset( aux , 0 , sizeof(aux) );
    int fila = 0;
    for(int t = 0 ; t <= 8 ; t++){
        fila++;
        if( m[fila][col] != 0 ) return 0;
        aux[fila][col] = rana;
        //cout<<t<<" paso: "<< fila << " " << col <<endl;
        for(int i = 1 ; i <= 8 ; i++){
            for(int j = 0 ; j < 10 ; j++){
                if( m[i][j] == 0 ) continue;
                int columna = (i<=4)?( (j - m[i][j] + 10)%10 ):( (j+m[i][j])%10 );
                //cout<<"en Fila: "<< i << " -- " <<m[i][j]<<" "<< j <<" --> "<<columna<<endl;
                if( aux[i][columna] == rana ) return 0; //aux[i][columna] == rana
                aux[i][columna] = m[i][j];
            }
        }
        for(int i = 0 ; i <= 8 ; i++){
            for(int j = 0 ; j < 10 ; j++){
                if(aux[i][j] != rana ) m[i][j] = aux[i][j];
                else m[i][j] = 0;
            }
        }
        memset( aux , 0 , sizeof(aux) );
    }
    return 1;
}

bool solve(){
    for(int i = 0 ; i < 10 ; i++){
        if( prueba( i ) ) return 1;
    }
    return 0;
}

int main(){
    string s;
    while( cin >> s ){
        for(int i = 1 ; i <= 8 ; i++){
            for(int j = 0 ; j < 10 ; j++){
                cin >> ini[i][j];
            }
        }
        if(solve()) puts("LEFTOVER POSSUM");
        else puts("FROGGER");
        cin >> s;
    }
}