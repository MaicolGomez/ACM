#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int meses[13] = { 0 , 31 ,  28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};

int main(){
    int a , m , d , dias = 0;
    cin >> a >> m >> d;
    for(int i = 1800 ; i < a ; i++){
        dias += 365;
        if( i % 400 == 0 ){ dias++; continue; }
        if( i % 100 == 0 ) continue;
        if( i % 4 == 0 ) dias++;
    }
    for(int i = 1 ; i < m ; i++){
        dias += meses[i];
        if( i == 2){
            if( i % 400 == 0 ){ dias++; continue; }
            if( i % 100 == 0 ) continue;
            if( i % 4 == 0 ) dias++;
        }
    }
    dias += d-1;
    dias %= 7;
    if( dias == 0 ) puts("wednesday");
    if( dias == 1 ) puts("thursday");
    if( dias == 2 ) puts("friday");
    if( dias == 3 ) puts("saturday");
    if( dias == 4 ) puts("sunday");
    if( dias == 5 ) puts("monday");
    if( dias == 6 ) puts("tuesday");
}
