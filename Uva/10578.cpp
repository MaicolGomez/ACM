#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<cstring>
using namespace std;

string s;
int m[7];
int t[5][5][5][5][5][5][32];

int f( int a ,int b , int c, int d, int e , int g , int suma ){
    if(suma>=31) return suma!=31;
    int &ret = t[a][b][c][d][e][g][suma];
    if( ret != -1 ) return ret;
    ret = 0;
    if( a>=1 ) ret = ret||!f( a-1 , b , c , d , e , g , suma+1 );
    if( b>=1 ) ret = ret||!f( a , b-1 , c , d , e , g , suma+2 );
    if( c>=1 ) ret = ret||!f( a , b , c-1 , d , e , g , suma+3 );
    if( d>=1 ) ret = ret||!f( a , b , c , d-1 , e , g , suma+4 );
    if( e>=1 ) ret = ret||!f( a , b , c , d , e-1 , g , suma+5 );
    if( g>=1 ) ret = ret||!f( a , b , c , d , e , g-1 , suma+6 );
    return ret;
}

void doit(){
    memset(t , -1 , sizeof(t) );
    int suma = 0;
    for(int i = 1 ; i <= 6 ; i++) m[i] = 4;
    for(int i = 0 ; i < s.length() ; i++) m[ s[i]-'0' ]-- , suma+=s[i]-'0';
    if( s != "" ) cout<<s<<" ";
    if(suma==31){
        if(s.length()%2==0) cout<<"B"<<endl;
        else cout<<"A"<<endl;
        return;
    }
    int ok = f( m[1] , m[2] , m[3] , m[4] , m[5] , m[6] , suma  );
    if( s.length()%2==1){
        if(!ok) cout<<"A"<<endl;
        else cout<<"B"<<endl;
    }
    else{
        if(!ok) cout<<"B"<<endl;
        else cout<<"A"<<endl;
    }
}

int main(){
    while( getline(cin,s) ){
        doit();
    }
}
