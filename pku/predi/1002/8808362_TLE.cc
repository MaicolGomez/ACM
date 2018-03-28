#include<vector>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;

map<char , char> m;

string parsea(string s){
    string res = "";
    for(int i = 0 ; i < s.length() ; i++){
        if( s[i] != '-' ){
            if( s[i] >= 'A' && s[i] <= 'Z' ) res += m[ s[i] ];
            else res += s[i];
        }
        if( res.length() == 3 ) res += "-";
    }
    return res;
}

void doit(int n){
    vector<string> v;
    string s, s1;
    char cad[100];
    for(int i = 0 ; i < n ; i++){
        scanf("%s",cad);
        s1 = string(cad);
        s = parsea( s1 );
        v.push_back( s );
    }
    sort( v.begin() , v.end() );
    int ct = 0;
    string p = v[0];
    vector<string>sol;
    vector<int> sol2;
    for(int i = 0 ; i < v.size() ; i++){
        if( p == v[i] ) ct++;
        else{
            if( ct > 1 ){
                sol.push_back( p );
                sol2.push_back( ct );
            }
            p = v[i];
            ct = 1;
        }
    }
    if( ct > 1 ) sol.push_back( p ) , sol2.push_back( ct );
    for(int i = 0 ; i < sol.size() ; i++) cout<<sol[i]<<" "<<sol2[i]<<endl;
}

int main(){
    m['A'] = '2';
    m['B'] = '2';
    m['C'] = '2';
    m['D'] = '3';
    m['E'] = '3';
    m['F'] = '3';
    m['G'] = '4';
    m['H'] = '4';
    m['I'] = '4';
    m['J'] = '5';
    m['K'] = '5';
    m['L'] = '5';
    m['M'] = '6';
    m['N'] = '6';
    m['O'] = '6';
    m['P'] = '7';
    m['R'] = '7';
    m['S'] = '7';
    m['T'] = '8';
    m['U'] = '8';
    m['V'] = '8';
    m['W'] = '9';
    m['X'] = '9';
    m['Y'] = '9';
    int n;
    cin >> n;
    doit( n );
}
