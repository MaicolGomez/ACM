#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

int m[10][10];

void doit(){
    int r , c , a;
    string s;
    cin >> r >> c;
    for(int i = 0 ; i < r ; i++){
        cin >> s;
        for(int j = 0 ; j < s.length() ; j++){
            m[i][j] = s[j] - '0';
        }
    }
    for(int i = 0 ; i < r - 1 ; i++){
        for(int j = 0 ; j < c - 1 ; j++){
            cout<<(m[i][j]+m[i][j+1]+m[i+1][j]+m[i+1][j+1])/4;
        }
        cout<<endl;
    }
    cin >> s;
    //cout<<s<<endl;
}

int main(){
    string s;
    while(cin >> s){
        if( s == "ENDOFINPUT" )break;
        doit();
    }
}
