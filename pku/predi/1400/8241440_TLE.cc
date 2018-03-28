#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string s;

string f(int a ,int b ,char ope ){
    int ct = 0;
    for(int i = b ; i >= a ; i-- ){
        if( s[i] == '(' ) ct++;
        if( s[i] == ')' ) ct--;
        if( ct == 0 && s[i] == '+' ){
            if( ope == ' ' || ope == '+' || ope =='p' ) return f( a , i - 1 , '+' ) + "+" + f( i + 1 , b , '+' );
            return "(" + f( a , i - 1 , '+' ) + "+" + f( i + 1 , b  , '+' ) + ")" ;
        }
        if( ct == 0 && s[i] == '-' ){
            if( ope == ' ' || ope == '+' || ope == 'p' ) return f( a , i - 1 , 'p' ) + "-" + f( i + 1 , b , '-' );
            return "(" + f( a , i - 1 , '-' ) + "-" + f( i + 1 , b , 'p' ) + ")" ;
        }
    }
    ct = 0;
    for(int i = b ; i >= a ; i-- ){
        if( s[i] == '(' ) ct++;
        if( s[i] == ')' ) ct--;
        if( ct == 0 && s[i] == '*' ){
            if( ope == ' ' || ope == '*' || ope == '+' || ope == '-' ) return f( a , i - 1 , '*' ) + "*" + f( i + 1 , b , '*' );
            return "(" + f( a , i - 1 , '*' ) + "*" + f( i + 1 , b  , '*' ) + ")" ;
        }
        if( ct == 0 && s[i] == '/' ){
            if( ope == ' ' || ope == '+' || ope == '-' || ope == '*' || ope == 'p' ) return f( a , i - 1 , 'p' ) + "/" + f( i + 1 , b , '/' );
            return "(" + f( a , i - 1 , 'p' ) + "/" + f( i + 1 , b , '/' ) + ")" ;
        }
    }
    if( s[a] == '(' ) return f( a + 1 , b - 1 , ope );
    string r = "";
    for(int i = a ; i <= b ; i++) r += s[i];
    return r;
}

void doit(){
    cin >> s;
    cout<<f( 0 , s.length() -1 , ' ' )<<endl; 
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n  ; i++){
        doit();    
    }
}
