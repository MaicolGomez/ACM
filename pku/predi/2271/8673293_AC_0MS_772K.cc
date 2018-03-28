#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<sstream>
using namespace std;
vector<string>v;

int pos = 0;
void doit(){
    char last = '*';
    for(int i = 0 ; i < v.size() ; i++){
        if( v[i] == "<br>" ){
            puts("");
            pos = 0;
            continue;
        }
        if( v[i] == "<hr>" ){
            if( pos > 0 ) puts("");
            pos = 0;
            printf( "--------------------------------------------------------------------------------\n" ); 
            continue;
        }
        if( pos == 0 ){
            cout<<v[i];
            pos += v[i].length();
            continue;
        }
        if( pos + 1 + v[i].length() > 80 ){
            puts("");
            pos = v[i].length();
            cout<<v[i];
            continue;
        }
        cout<<" "<<v[i];
        pos += 1+v[i].length();
    }
}

int main(){
    string s;
    while( getline(cin , s) ){
        string x;
        istringstream in(s);
        while( in >> x ){
            v.push_back(x);
        }
    }
    doit();
    if(pos != 0) puts("");
}
