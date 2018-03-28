#include<iostream>
#include<cstdio>
#include<algorithm>
#include<sstream>
using namespace std;
int s;
int pos = 0;

char mat[200][200];
bool posi[200];
void imprime( int r ){
    bool a = 0 , b = 0 , c = 0 , d = 0 , e = 0 , f  = 0 , g = 0;
    if( r == 0 ){ a = 1 , b = 1 , c = 1 , d = 1 , e = 1 , f = 1; }
    if( r == 1 ){ b = 1 , c = 1 ; }
    if( r == 2 ){ a = 1 , b = 1 , d = 1 , e = 1 , g = 1; }
    if( r == 3 ){ a = 1 , b = 1 , c = 1 , d = 1 , g = 1; }
    if( r == 4 ){ b = 1 , c = 1 , f = 1 , g = 1; }
    if( r == 5 ){ a = 1 , c = 1 , d = 1 , f = 1 , g = 1; }
    if( r == 6 ){ a = 1 , c = 1 , d = 1 , e = 1 , f = 1 , g = 1; }
    if( r == 7 ){ a = 1 , b = 1 , c = 1; }
    if( r == 8 ){ a = 1 , b = 1 , c = 1 , d = 1 , e = 1 , f = 1 , g = 1; }
    if( r == 9 ){ a = 1 , b = 1 , c = 1 , d = 1 , f = 1 , g = 1; }
    posi[pos + s + 2] = 0;
    if( a ){
        for(int i = 1 ; i <= s ; i++ ){
            mat[0][pos + i] = '-';
        }
    }
    if( b ){
        for(int i = 1 ; i <= s ; i++ ){
            mat[i][pos+s+1] = '|';
        }
    }
    if( c ){
        for(int i = 1 ; i <= s ; i++ ){
            mat[i + s + 1][pos+s+1] = '|';
        }
    }
    if( d ){
        for(int i = 1 ; i <= s ; i++ ){
            mat[2*s+2][pos + i] = '-';
        }
    }
    if( e ){
        for(int i = 1 ; i <= s ; i++ ){
            mat[i+ s + 1][pos] = '|';
        }
    }
    if( f ){
        for(int i = 1 ; i <= s ; i++ ){
            mat[i][pos] = '|';
        }
    }
    if( g ){
        for(int i = 1 ; i <= s ; i++ ){
            mat[s + 1][pos + i] = '-';
        }
    }
}

int main(){
    string s1;
    while( cin >> s >> s1 ){
        if( s == 0 ) break;
        pos = 0;
        int cont = 0;
        for(int i = 0 ; i < 200 ; i++) posi[i] = 1;
        for(int i = 0 ; i < 200 ; i++) for(int j = 0 ; j < 200 ; j++) mat[i][j] = ' ';
        while( cont < s1.length() ){
            imprime( int(s1[cont] - '0') );
            cont++;
            pos += (s+3);
        }
        for(int i = 0 ; i < 2*s+3; i++){
            for(int j = 0 ; j < pos - 1; j++){
                cout<<mat[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
