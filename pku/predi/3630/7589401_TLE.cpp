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

struct word{
   string a;
   string b;       
    word(string A , string B ){
        a = A;
        b = B;    
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
        v.push_back(word( s , s ) );    
    } 
    
    for(int i = 0 ; i < v.size()  ; i++ ){
        for(int j = v[i].a.length() ; j < 10 ; j++ ){
         v[i].a += '0';   
        }
    }
      
    sort( v.begin() , v.end() );
    
    //for(int i = 0; i < v.size() ; i++ ) cout<<v[i].b<<endl;
    
    bool enc = false;
    for(int i = 0 ; i < v.size() - 1 ; i++ ){
        string a="";
        for(int j = 0; j < v[i].b.length() ; j++ ){
           a += v[i+1].b[j];     
        }
        if( a == v[i].b){
            enc  = true; break;    
        }       
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
