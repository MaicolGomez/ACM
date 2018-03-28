#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

string s , s1;
int col,fil;
char t[20][20];

vector<int> f(){
    vector<int> v;
    for(char i = 'A' ; i <= 'Z' ; i++){
        for(int j = 0 ; j < s.length() ; j++){
            if( i == s[j] ) v.push_back(j);
        }
    }
    return v;
}

void doit(){
    cin >> s1;
    col = int(s.length());
    fil = s1.length()/col;
    vector<int> v = f();
    //for(int i = 0 ; i < v.size() ; i++) cout<<v[i]<<endl;
    int pos = 0;
    for(int i = 0 ; i < s1.length() ; i+=fil){
        string res = "";
        for(int j = i ; j < i+fil ; j++) res += s1[j];
        for(int j = 0 ; j < fil ; j++){
            t[j][v[pos]] = res[j];
        }
        pos++;
    }
    string sol = "";
    for(int i = 0 ; i < fil ; i++) for(int j = 0 ; j < col ; j++) printf("%c",t[i][j]);
    printf("\n");
}

int main(){
    while(cin >> s){
        while( s == "THEEND" ) return 0;
        doit();
    }
}
