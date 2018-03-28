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
    int mini = 20;
    int p = 11 , q = 11;
    for(int i = 1; i < 10 ; i++)if( i%3!=0 ){
        int r = ct - i;
        if( ct >= 0 && r % 3 == 0  && a[i] > 0 ){
            a[i]--;
            if( a[5] > 0 || a[0] > 0 ) return r;
            a[i]++;
        }
        for(int j = 1 ; j < 10 ; j++)if( j%3!=0 ){
            r = ct - i - j;
            if( r >= 0 && r % 3 == 0 && i+j<=mini && a[i] > 0 && a[j] > 0){
                if( i == j && a[i] < 2 ) continue;
                if( i + j == mini){
                    if( max( i , j ) < max(p , q) ){ p = i , q = j; }
                }
                if(i+j<mini){
                    //puts("entra");
                    p = i , q = j;
                    mini = i+j;
                }
            }
        }
    }
    if( p < 11){
        a[p]--; a[q]--;
        return ct - p - q;
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
