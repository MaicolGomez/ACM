#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

bool f( int x , int total ){
    for(int i = 1 ; i <= x ; i++){
        if( (total - 1) % x != 0 ) return 0;
        total--;
        total = (total*(x-1))/x;
    }
    return 1;
}

void doit(int n){
    bool ok = 0;
    int sol;
    for(int i = 2 ; i <= n/2 ; i++){
        ok = f( i , n );
        sol = i;
        if( ok ) break;
    }
    if( ok ) printf("%d coconuts, %d people and 1 monkey\n",n,sol);
    else printf("%d coconuts, no solution\n",n);
}

int main(){
    int n;
    while( scanf("%d",&n) == 1 ){
        if( n == -1 ) break;
        doit( n );
    }
}
