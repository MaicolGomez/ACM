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
        if( i == 5 ) continue;
        if( a[i] > 0 ){
            if( (ct - i) % 3 == 0 ){
                if( ct-i < 0 ) continue;
                a[i]--;
                return ct-i; 
            }
        }
        if( a[i] > 1 ){
            if( (ct - 2*i) % 3 == 0 ){
                if( ct-2*i < 0 ) continue;
                a[i] -= 2;
                return ct-2*i; 
            }
        }
    }
    if( ct % 3 != 0 ){
        if( a[5] > 0 ){
            if( (ct - 5) % 3 == 0 && ct - 5 >= 0  ){ a[5]--; return ct-5; }
        }
        if( a[5] > 1 ){
            if( (ct - 10) % 3 == 0 && ct - 10 >= 0 ){ a[5]-=2; return ct-10; }
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
    if( ct % 3 != 0 ){ puts("impossible"); return 0; }
    if( a[0] == 0 && a[5] == 0 ){ puts("impossible"); return 0 ; }
    
    string res = "";
    if( a[0] >= 0 ){
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
