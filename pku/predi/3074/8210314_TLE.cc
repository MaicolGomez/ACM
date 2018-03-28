#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n;
int tabla[10][10];

bool valida( int fila , int col , int numero ){
    for(int i = 0 ; i < 9 ; i++)if( tabla[i][col] == numero ) return 0; 
    for(int i = 0 ; i < 9 ; i++)if( tabla[fila][i] == numero ) return 0;  
    int x = fila/3;
    int y = col/3;
    for(int i = x * 3 ; i < x * 3 + 3 ; i++ ){
        for(int j = y * 3 ; j < y * 3 + 3; j++){
            if( tabla[i][j] == numero ) return 0;
        }
    }
    return 1;
}

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
            if( valida( fila , col , i ) ){
                tabla[fila][col] = i;
                f( fila + 1, col);
            }
        }
        tabla[fila][col] = 0;
    }
}

bool doit(){
    enc = 0;
    string s;
    char cad[10];
        cin >> s;
        if( s == "end") return false;
        for(int j = 0 ; j < 81 ; j++ ){
           if( s[j] != '.' ) tabla[j/9][j%9] = s[j] - '0';
           else tabla[j/9][j%9] = 0;
        }
    f( 0 , 0 );
    return true;
}

int main(){
    while( doit() ){    
    }
}
