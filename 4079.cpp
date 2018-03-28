#include<bits/stdc++.h>

int main(){
    int n;
    while( scanf("%d",&n) == 1 ){
        if(n&1) printf("G\n");
        else printf("H\n");
    }
    return 0;
}
