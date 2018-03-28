#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int a , b , c , n , m , r;
    while( scanf("%d%d%d",&n,&m,&r) == 3 ){
        c = n;
        a = (r-2*m+n)/2;
        b = m - n - a;
        int x = a*9+b*3+c , y = a*16+b*4+c , z = a*25+b*5+c;
        printf("%d %d %d\n",x,y,z);
    }
}
