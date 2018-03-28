#include<cstdio>
using namespace std;
int test = 0;

int main(){
    int p, e, i, d;
    while( scanf("%d%d%d%d",&p,&e,&i,&d) ){
        if( p == -1 && e == -1 && i == -1 && d == -1 ) break;
        test++;
        if( p == e && e == i ){ printf("Case %d: the next triple peak occurs in %d days.\n",test,21252 - d); continue; }
        for(int j = d + 1 ; j < 100000 ; j++ ){
            if( (j - p) % 23 == 0 && (j - e) % 28 == 0 && (j-i) % 33 == 0 ){
                printf("Case %d: the next triple peak occurs in %d days.\n",test,j - d );
                break;   
            }    
        }
    }    
}
