#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n;
int tabla[10][10];
bool filas[9][10];
bool colu[9][10];
bool cua[9][10];

bool enc = 0;
void f( int fila , int col ){
    if(enc ) return;
    if( fila + col == 17 ){ enc = 1; 
        for(int i = 0 ; i < 9 ; i ++ ){
            for(int j = 0 ; j < 9 ; j++ ){
                printf("%d",tabla[i][j]);
            }    
        }
        puts("");   
        return;
    }
    if( fila == 9 ){ col++; fila = 0; }
    if( tabla[fila][col] != 0 ){
        f( fila + 1, col );
    }
    else{
        for(int i = 1 ; i <= 9 ; i++  ){
            if( !filas[fila][i] && !colu[col][i] && !cua[ 3*(fila/3) + col/3 ][i] ){
                filas[fila][i] = 1;
                colu[col][i] = 1;
                cua[ 3*(fila/3) + col/3 ][i] = 1;
                tabla[fila][col] = i;
                f( fila + 1, col);
                filas[fila][i] = 0;
                colu[col][i] = 0;
                cua[ 3*(fila/3) + col/3 ][i] = 0;
                tabla[fila][col] = i;
            }
        }
        tabla[fila][col] = 0;
    }
}

bool doit(){
    enc = 0;
    string s;
        cin >> s;
        if( s == "end") return false;
        for(int i = 0 ; i < 9 ; i++) for(int j = 0 ; j < 10 ; j++){ filas[i][j] = 0; colu[i][j] = 0; cua[i][j] = 0; }
        for(int j = 0 ; j < 81 ; j++ ){
           if( s[j] != '.' ){
                tabla[j/9][j%9] = s[j] - '0';
                filas[ j/9 ][ s[j] - '0' ] = 1;
                colu[ j%9 ][ s[j] - '0' ] = 1;
                cua[ 3*((j/9)/3) + (j%9)/3 ][ s[j] - '0' ] = 1;
            }
           else tabla[j/9][j%9] = 0;
        }
    f( 0 , 0 );
    return true;
}

int main(){
    while( doit() ){    
    }
}
