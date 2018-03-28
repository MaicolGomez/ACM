#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;

int n;

void doit(){
    int dia;
    for(dia = 1; ; dia++){
        if( 2*n <= dia*(dia+1) ) break;
    }
    //cout<<dia<<endl;
    int queda = ( dia*(dia+1) )/2 - n;
    int r , p;
    if( dia%2 == 0 ){
        r = 1 + queda;
        p = dia - queda;
    }
    else{
        r = dia - queda;
        p = 1 + queda;
    }
    swap(r,p);
    printf("TERM %d IS %d/%d\n",n,r,p);
}

int main(){
    while( scanf("%d",&n) == 1 ){
        doit();
    }
}
