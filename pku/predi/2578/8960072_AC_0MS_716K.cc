#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

#define inf 169

int main(){
    int n;
    while( scanf("%d",&n) == 1 ){
        if( n<inf ){
            printf("CRASH %d\n",n);
            return 0;
        }
    }
    puts("NO CRASH");
}
