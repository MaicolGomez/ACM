#include<iostream>
#include<algorithm>
#include<sstream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;
string s;
char digit(char p){
    if( p == '0' ) return '9';
    if( p == '1' ) return '`';
    else return p - 1;
}

char puntu( char p ){
    if( p == '=') return '-';
    if( p == '-') return '0';
    if( p == ']') return '[';
    if( p == '[') return 'P';
    if( p == '\\')return ']';
    if( p == ';') return 'L';
    if( p == ',') return 'M';
    if( p == '.') return ',';
    if( p == '/') return '.';
    return ';';
}

string letras = "AVXSWDFGUHJKNBIOQEARYCQZTZ";
int main(){
    while(getline(  cin , s ) ){
        string res = "";
        for(int i = 0 ; i < s.length() ; i++){
            if( s[i] == ' ' ){ res += " "; continue; }
            if( isdigit(s[i]) ) { res += digit( s[i] ); continue; }
            if( isalpha(s[i]) ) { res += letras[ s[i] - 65 ]; continue; }
            res += puntu( s[i] );
        }
        cout<<res<<endl;
    }    
}
