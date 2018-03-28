#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

int tam1;

struct word{
   string a;
   int tam;       
    word(string A , int TAM ){
        a = A;
        tam = TAM;    
    } 
};

bool operator<(word p, word q){
    return p.a < q.a ;   
}


void doit(){
    int n;
    scanf("%d",&n);
    vector <word> v;
    char s[15];
    gets(s);
    for(int i = 0 ; i < n ; i++){
        gets(s);
        tam1 = (int)strlen( s );
        for(int j = tam1 ; j < 10 ; j++ ){
            s[j] = '0';
        }
        string x = string(s);
        v.push_back( word( x , tam1 ) );
    }
    sort( v.begin() , v.end() );
    bool enc = false;
    for(int i = 0 ; i < v.size() - 1 ; i++ ){        
        for(int j = 0; j < v[i].tam ; j++)  {
            if( v[i].a[j] != v[i+1].a[j] ) break;
            if( j == v[i].tam - 1  ){
                enc = true;  break;  
            }     
        } 
        if( enc ) break;      
    }
/*
    for(int i = 0 ; i < v.size() - 1 ; i++){
        string x = v[i+1].a.substr( 0 , v[i].tam );
        if( x == v[i].a ){ enc=1; break; }
    }
 */    
    puts(!enc?"YES":"NO");
}

int main(){
    int c;
    scanf("%d",&c);
    char x[2];
    gets( x );
    for(int i = 0 ; i < c ; i++){
        doit();    
    }      
}