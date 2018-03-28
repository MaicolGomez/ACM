#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
string s;

string suma( string a , string b ){
    string res = a;
    for(int i = 0 ; i < b.length() ; i++){
        bool ok = 1;
        for(int j = 0 ; j < a.length() ; j++){
            if( b[i] == a[j] ){ ok = 0 ; break; }
        }
        if( ok ) res += b[i];
    }
    return res;
}
string resta(string a , string b){
    string res = "";
    for(int i = 0 ; i < a.length() ; i++){
        bool ok = 1;
        for(int j = 0 ; j < b.length() ; j++){
            if( a[i] == b[j] ){ ok = 0 ; break; }
        }
        if( ok ) res += a[i];
    }
    return res;
}
string pro(string a , string b){
    string res = "";
    string m = a+b;
    for(int i = 0 ; i < a.length() ; i++){
        bool ok = 1;
        for(int j = 0 ; j < b.length() ; j++){
            if( a[i] == b[j] ){ res += a[i]; break; }
        }
    }
    return res;
}

string f( int x , int y ){
    int ct = 0;
    for(int i = y ; i >= x ; i--){
        if( s[i] == '(' ) ct++;
        if( s[i] == ')' ) ct--;
        if( ct == 0 && ( s[i] == '+' ||  s[i] == '-' ) ){
            if( s[i] == '+' ) return suma( f(x , i-1)  , f(i+1 , y) );
            return resta( f(x , i-1)  , f(i+1 , y) );
        }
    }
    ct = 0;
     for(int i = y ; i >= x ; i--){
        if( s[i] == '(' ) ct++;
        if( s[i] == ')' ) ct--;
        if( ct == 0 && s[i] == '*' ){
            return pro( f(x , i-1)  , f(i+1 , y) );
        }
    }
    if( s[x] == '{' || s[x] == '(' ) return f(x+1 , y-1 );
    string res = "";
    for(int i = x ; i <= y ; i++){
        res += s[i];
    }
    return res;
}

int main(){
    while(cin >> s){
        string p = "";
        for(int i = 0 ; i < s.length() ; i++) if( s[i] != '{' && s[i] != '}' ) p+= s[i];
        s = p;
        string res = f(0 , s.length() - 1);
        sort( res.begin() , res.end() );
        string sol = "{" + res + "}";
        cout<<sol<<endl;
    }
}
