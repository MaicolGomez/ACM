#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int a[10];

int arregla(int ct){
    for(int i = 1; i < 10 ; i++)if( i%3!=0 ){
        int p = ct - i;
        if( p >= 0 && p % 3 == 0 && a[i] > 0 ){
            a[i]--;
            return p;
        }
        for(int j = 1 ; j < 10 ; j++)if( j%3!=0 ){
            int r = ct - i - j;
            if( r >= 0 && r % 3 == 0 && a[i] > 0 && a[j] > 0 ){
                if( i == j ) if( a[i] < 2 ) continue;
                a[i]--;
                a[j]--;
                return r;
            }
        }
    }
    return ct;
}

string parsea(string s){
    int ct = 0;
    for(int i = 0 ; i < s.length() ; i++){
        if( s[i] == '0' )ct++;
    }
    if( ct == s.length() ) return "0";
    return s;
}

int main(){
    string s;
    cin >> s;
    int ct = 0;
    for(int i = 0 ;  i < s.length() ; i++){
        int b = s[i]-'0';
        ct += b;
        a[ b ]++;
    }
    if( ct % 3 != 0 ) ct = arregla( ct );
    cout<<ct<<endl;
    if( ct % 3 != 0 ){ puts("impossible"); return 0; }
    if( a[0] == 0 && a[5] == 0 ){ puts("impossible"); return 0 ; }
    
    string res = "";
    if( a[0] > 0 ){
        for(int i = 9 ; i >= 0 ; i--){
            while(a[i] > 0 ){
                res += i+'0';
                a[i]--;
            }
        }
        res = parsea(res);
        cout<<res<<endl; return 0;
    }
    else{
        a[5]--;
        for(int i = 9 ; i >= 0 ; i--){
            while(a[i] > 0 ){
                res += i+'0';
                a[i]--;
            }
        }
        res += "5";
        res = parsea(res);
        cout<<res<<endl;
    }
}
