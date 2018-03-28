#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
    cin>>n;
    vector <word> v; 
    for(int i = 0 ; i < n ; i++){
        string s;
        cin>>s;
        tam1 = s.length();
        for(int j = s.length() ; j < 10 ; j++ ){
         s += '0';   
        }        
        v.push_back( word( s , tam1 ) );    
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
       
    if( enc ) cout<<"NO"<<endl;
    else cout<<"YES"<<endl; 
     
}

int main(){
    int c;
    cin>>c;
    for(int i = 0 ; i < c ; i++){
        doit();    
    }      
}
