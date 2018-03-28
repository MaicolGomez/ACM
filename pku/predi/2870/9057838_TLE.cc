#include<iostream>
#include<cstdio>
using namespace std;
int R , C , total;
int need[10][10];
int pintados[10][10];
int cont[10][10];
char lamp[10][10];
int mini = 100;
int dx[4] = {-1 , 0 , 0 , 1};
int dy[4] = {0 , 1 , -1 , 0};

bool valida(int fila , int col ){
    if( need[fila][col] != -100 ) return 0;
    for(int i = col ; i <= C ; i++ ){ if( need[fila][i] >= -1 )break; else if(lamp[fila][i] == 'L') return 0; }
    for(int i = col ; i >= 1 ; i-- ){ if( need[fila][i] >= -1 )break; else if(lamp[fila][i] == 'L') return 0; }
    for(int i = fila ; i >= 1 ; i-- ){ if( need[i][col] >= -1 )break; else if(lamp[i][col] == 'L') return 0; }
    for(int i = fila ; i <= R ; i++ ){ if( need[i][col] >= -1 )break; else if(lamp[i][col] == 'L') return 0; }
    for(int i = 0 ; i < 4 ; i++){
        if( need[fila+dx[i]][col+dy[i]] != -100 && need[fila+dx[i]][col+dy[i]] != -1 && need[fila+dx[i]][col+dy[i]] <= cont[fila+dx[i]][col+dy[i]] ) return 0;
    }
    return 1;
}

bool vali(){
    int p;
    for(int i = 1 ; i <=R ; i++ ){
        for(int j = 1 ; j <= C ; j++){
            p = need[i][j];
            if(  p != -1 && p != -100 ) if( need[i][j] != cont[i][j] ) return 0;
        }
    }
    return 1;
}

void f( int fila , int col , int jerar , int pintadas , int usadas ){
    if(pintadas == total) if( vali() ){ mini = min( usadas , mini ); return; }
    if( col == C + 1 ){ fila = fila + 1 ; col = 1; }
    if( fila == R + 1 ) return;
    if( valida( fila , col ) && usadas < mini ){
        lamp[fila][col] = 'L';
        jerar++;
        usadas++;
        int k = pintadas;
        pintados[fila][col] = jerar;
        pintadas++;
        for(int i = fila+1 ; i <= R ; i++){
            if( need[i][col] != -100 ) break;
            if( pintados[i][col] == 0 ){ pintados[i][col] = jerar; pintadas++; }
        }
        for(int i = fila-1 ; i >= 1 ; i--){
            if( need[i][col] != -100 ) break;
            if( pintados[i][col] == 0 ){ pintados[i][col] = jerar; pintadas++; }
        }
        for(int i = col+1 ; i <= C ; i++){
            if( need[fila][i] != -100 ) break;
            if( pintados[fila][i] == 0 ){ pintados[fila][i] = jerar; pintadas++; }
        }
        for(int i = col-1 ; i >= 1 ; i--){
            if( need[fila][i] != -100 ) break;
            if( pintados[fila][i] == 0 ){ pintados[fila][i] = jerar; pintadas++; }
        }
        for(int i = 0 ; i < 4 ; i++){
            if( need[fila+dx[i]][col+dy[i]] > 0 ) cont[fila+dx[i]][col+dy[i]]++;
        }
        f( fila  , col + 1 , jerar , pintadas , usadas );
        usadas--;
        lamp[fila][col] = 'N';
        for(int i = 0 ; i < 4 ; i++){
            if( need[fila+dx[i]][col+dy[i]] >= 0 ) cont[fila+dx[i]][col+dy[i]]--;
        }
        for(int i = 1 ; i <= R ; i++) for(int j = 1 ; j <= C ; j++ ) if( pintados[i][j] == jerar ) pintados[i][j] = 0;
        jerar--;
        pintadas = k;
    }
    f( fila , col + 1 , jerar , pintadas , usadas );           
}

bool doit(){
    scanf("%d%d",&R,&C);
    if( R == 0 &&  C == 0 ) return 0;
    mini = 100;
    for(int i = 0 ; i <= R+1; i++) for(int j = 0; j <= C+1 ; j++){ need[i][j] = -100; pintados[i][j] = 0; cont[i][j] = 0; }
    for(int i = 1 ; i <= R ; i++ ) for(int j = 1 ; j <= C ; j++) lamp[i][j] = 'N';
    int a , b , c , t; 
    scanf("%d",&t);
    total = R*C - t;
    for(int i = 0; i < t ; i++){
        scanf("%d%d%d",&a,&b,&c);
        pintados[a][b] = -4;
        need[a][b] = c;
    }
    f( 1 , 1 , 0 , 0 , 0 );
    if(mini==100) cout<<"No solution"<<endl;
    else cout<<mini<<endl;
    return 1;
}

int main(){
    while(doit()){   
    }
}