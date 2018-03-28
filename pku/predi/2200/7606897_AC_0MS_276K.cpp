#include<iostream>
#include<cmath>
#include<cctype>
#include<deque>
#include<cstdio>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int elnum(string s){
    if(s[0] == 'A' || s[0] == 'J' || s[0] == 'Q' || s[0] == 'K' ){
        if( s[0] == 'A' ) return 1;
        if( s[0] == 'J' ) return 11;
        if( s[0] == 'Q' ) return 12;
        if( s[0] == 'K' ) return 13;
    }
    if( s[0] == '1'  ) return 10;
    else{
        return s[0] - '0';    
    }
}

bool compara(string s ,string  s1){
      if( elnum(s) != elnum(s1) )  return elnum( s ) > elnum( s1 ) ;
      else{
            return s[ s.length() - 1 ] > s1[ s1.length() - 1 ] ;       
      }        
}

bool magia(vector <string> v){  
    int res = elnum(v[0]); 
    char letra = v[0][v[0].length()-1];
    if( letra != v[1][v[1].length()-1] ) return false;
    int pro = elnum(v[1]);
    int pos,a,b;
    int menor = 20;
    for(int i = 2 ; i <= 4 ; i++ ){
        a = elnum(v[i]);
        if(menor != a ) if ( a < menor ){ menor = a; pos = i ;}
        if(menor == a ){
            if( v[i][ v[i].length() - 1 ] < v[pos][ v[pos].length() - 1 ] ){
                pos = i;    
            }    
        }
    }
    pro +=(pos);
    pro--;    
    if(pos == 2){
        if( compara( v[3] , v[4]) )  pro +=3;
    }
    if(pos == 3){
        if( compara( v[2] , v[4]) )  pro +=3;         
    }
    if(pos == 4){
        if( compara( v[2] , v[3]) )  pro +=3;         
    } 
    //cout<<res<<" "<<pro<<" "<<endl;
    //for(int i = 0 ; i < v.size() ; i++) cout<<v[i]<<" ";
    //cout<<endl;   
    if(pro > 13 )pro = pro % 13;  
    if(pro == res) return true;
    else return false;        
}
int test=0;
void doit(){
    test++;
    vector <string> v;
    string s;
    for(int i = 0 ; i < 5 ; i++){
        cin>>s;
        v.push_back(s); 
    }
    sort( v.begin() , v.end() );
    vector <string> v1;
    do{     
        if(magia(v)){
            s="";
            for(int i = 0 ; i < v.size() ; i++){
                s+=v[i];
                if( i < 4) s+=" ";  
            }    
            v1.push_back(s); 
        } 
    }while( next_permutation( v.begin() , v.end() ) );
    sort( v1.begin() , v1.end() );
    int pos=0;
    for(int i = 0 ; i < v1.size() ; i++  ){
            if( !compara( v1[i] , v1[pos] ) ){
                pos = i;
            }          
    }
    cout<<"Problem "<<test<<": ";
    cout<<v1[pos]<<endl;
}

int main(){
    int k;
    cin>>k;
    for(int i = 0 ; i < k ; i++){
       doit();        
    } 
}
