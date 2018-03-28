#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[27] = { 2 , 5 , 4 , 4 , 1 , 6 , 5 , 5 , 1 , 7 , 6 , 3 , 5 , 2 , 3 , 5 , 7 , 2 , 1 , 2 , 4 , 6 , 6 , 7 , 5 , 7 };
bool es[27];
int conta[27];
int conta2[27];
int main(){
    for(int i = 0 ; i < 27 ; i++ ){ es[i] = 0; conta[i] = 0; conta2[i] = 0; }
    string s , s1;
    cin >> s;
    for(int i = 0 ; i < s.length() ; i++){ es[ s[i] - 'a' ] = 1; conta2[ s[i] - 'a' ]++; }
    int suma = 0 , cont = 0;
    while( cin >> s1 ){
        cont = 0;
        bool ok = 0;
        if( s1 == "." ) break;
        for(int i = 0 ; i < s1.length() ; i++){
            if( es[ s1[i] - 'a' ] == 0 || conta[ s1[i] - 'a' ] > conta2[ s1[i] - 'a' ]  ){ ok = 1; break; }  
            if( es[ s1[i] - 'a' ] && conta[ s1[i] - 'a' ] <= conta2[ s1[i] - 'a' ] ){ conta[ s1[i] - 'a' ]++; cont += a[ s1[i] - 'a' ];  } 
        }
        if(ok) continue;
        if( cont > suma ) suma = cont;
    }
    printf("%d\n",suma);
}
