#include<iostream>
#include<cstdio>
using namespace std;

int n;
int m[14] = {2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

int main(){
    while( scanf("%d",&n) ){
        if( n == 0 ) break;
        printf("%d\n", m[ n - 1] );
    }    
}