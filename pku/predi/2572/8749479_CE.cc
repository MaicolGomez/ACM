#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<vector>
using namespace std;

int f(string s){
    int a = 0;
    for(int i = 0 ; i < s.length() ; i++){
        a = a*10 + (s[i]-'0');
    }
    return a;
}

int main(){
    string s;
    while( cin >> s ){
        if( s == "0+0=0" ) break;
        for(int i = 0 ; i < s.length() ; i++) if(s[i] == '+' || s[i] == '=' ) s[i] = ' ';
        istringstream in(s);
        string s1 , s2 , s3;
        in >> s1 >> s2 >> s3;
        reverse( s1.begin() , s1.end() );
        reverse( s2.begin() , s2.end() );
        reverse( s3.begin() , s3.end() );
        int a = f(s1) , b = f(s2) , c = f(s3);
        if(a+b==c) puts("True");
        else puts("False");
    }
    puts("True");
}
