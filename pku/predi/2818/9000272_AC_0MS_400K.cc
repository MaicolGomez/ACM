#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define inf 100000
int a , b , c , d , e;

void doit(){
    int x = inf , y = inf , w = inf , z = inf;
    for(int i = 0 ; i <= min(a,4) ; i++){
        for(int j = 0 ; j <= min(b,10) ; j++){
            for(int k = 0 ; k <= min(c,20) ; k++){
                for(int r = 0 ; r <= min(d,100) ; r++){
                    if(25*i+10*j+5*k+r==e){
                        if( i+j+k+r<x+y+z+w ){
                            x = i , y = j , w = k , z = r;
                        }
                    }
                }
            }
        }
    }
    if( x + y + z + w < 4*inf ) printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n",x,y,w,z);
    else puts("Cannot dispense the desired amount.");
}

int main(){
    while( scanf("%d%d%d%d%d",&a,&b,&c,&d,&e) == 5 ){
        if(a==0&&b==0&&c==0&&d==0&&e==0)break;
        doit();
    }
}
