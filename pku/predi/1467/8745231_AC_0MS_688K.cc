#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string s;
string f(int a , int b){
    int ct = 0;
    for(int i = b ; i >= a ; i--){
        if( s[i] == '(' ) ct--;
        if( s[i] == ')' ) ct++;
        if( (s[i] == '+' || s[i] == '-') && ct == 0 && i != a ) return f( a , i-1 ) + s[i] + f( i+1 , b );
    }
    ct = 0;
    for(int i = b ; i >= a ; i--){
        if( s[i] == ')' ) ct++;
        if( s[i] == '(' ) ct--;
        if( (s[i] == '*' || s[i] == '/') && ct == 0 ){
            if( s[i] == '*' )  return "(" + f( a , i - 1) + "*" + s.substr( i + 1 , b - i ) + "+" + s.substr( a , i - a ) + "*" + f( i + 1 , b) + ")";
            return "(" + f( a , i - 1) + "*" + s.substr( i + 1 , b - i ) + "-" +  s.substr( a , i - a ) + "*" + f( i + 1 , b) + ")/" + s.substr( i + 1 , b - i ) + "^2";
        }
    }
    if(s[a]=='l')return "("+f(a+3,b-1)+")/("+s.substr(a+3,b-a-3)+")";
    if( s[a] == '(' ) return "(" + f(a + 1 , b - 1) + ")";
    if( a == b && s[a] == 'x') return "1";
    return "0";    
}

int main(){
    while( cin >> s  ){
        string res = f( 0 , int( s.length() ) - 1 );
        int ct = 0 , Ct = 0;
        string ret = "";
        for(int i = 0 ; i < res.length() ; i++){
            if( res[i] == '+' || res[i] == '-' ){
                if( res[i] == '-' ) ct++;
                Ct++;     
            }
            else{
                if( Ct > 0){
                    if( ct % 2 == 0 ) ret += "+";
                    else ret += "-";
                }
                ret += res[i];
                ct = 0;
                Ct = 0;
            }
        }
        cout<<ret<<endl;
    }
}
