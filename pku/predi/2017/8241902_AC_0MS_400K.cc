#include<cstdio>
using namespace std;

int main(){
    int n;
    while( scanf("%d",&n) && n != -1 ){
        int suma = 0 , a , b , p = 0;
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d",&a,&b);           
            suma += a*(b-p);
            p = b;
        }
        printf("%d miles\n",suma);
    }
}
