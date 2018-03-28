#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<map>
using namespace std;

char t[6][6];
int dx[] = {-1 , 0 , 0 , 1};
int dy[] = {0 , 1 , -1 , 0};
vector<string> v;

void f(string s , int x , int  y ){
    s += t[x][y];
    if( s.length() == 6 ){
        v.push_back(s);
        return;
    }
    if( s.length() > 6 ) return;
    for(int i = 0 ; i < 4 ; i++){
        int u = x + dx[i];
        int v = y + dy[i];
        if( u >= 0 && u < 5 && v >=0 && v < 5 ){
            f( s , u , v );
        }
    }
}

int main(){
    char p;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin >> p;
            t[i][j] = p;
            //cout<<t[i][j];
        }
        //cout<<endl;
    }
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            string res = "";
            f( res , i , j );
        }
    }
    sort( v.begin() , v.end() );
    v.resize( unique( v.begin() , v.end() ) - v.begin() );
    //for(int i = 0 ; i < v.size() ; i++) cout<<v[i]<<" ";
    cout<<v.size()<<endl;
}
