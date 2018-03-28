#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<string>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-8

int  p , q , n , m;

void f(string s){
    p = 0 , q = 0;
    int x = 1 , b = 0;
    if( s[0] == '-' or s[0] == '+' ) b = 1;
    if( s[0] == '-' ) x = -1;
    int k = 0;
    bool var = 0 , in = 0;
    for(int i = b ; i < s.size() ; i++){
        if( s[i] >= '0' and s[i] <= '9' ){
            k = k * 10 + (s[i] - '0');
            in = 1;
        }
        else if( s[i] == 'x' ){
            if( !in ) k = 1;
            p += x * k;
            k = 0;
            var = 1;
            in = 0;
        }
        else{
            in = 0;
            if( var ) k = 0;
            var = 0;
            q += x * k;
            k = 0;
            x = 1;
            if( s[i] == '-' ) x = -1;
        }
    }
    q += x * k;
}

void doit(){
    string s,a="",b="";
    cin >> s;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i]!='=')a+=s[i];
        else{
            for(int j = i + 1 ; j < s.length() ; j++) b+=s[j];
            break;
        }
    }
    f(a);
    m = p , n = q;
    f(b);
    //cout << m << " " << n << " -- " << p << " " << q << "\n"; 
    if( m == p && q == n ) puts("IDENTITY");
    else{
        if( m-p!=0 ){
            int r = int ( floor( double(q-n)/(m-p) ) );
            printf("%d\n", r );
        }
        else puts("IMPOSSIBLE");
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++) doit();
}

