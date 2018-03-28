#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;

int main(){
    bool primo[40000];
    memset(primo , 1, sizeof(primo) );
    for(int i = 2 ; i * i <= 40000 ; i++ )
        for(int j = 2 * i ; j <= 40000 ; j += i)
            primo[j] = 0;
            
    primo[1] = 0;       
    int n;
    while(scanf("%d",&n)){
        if(!n) break;
        int cont = 0;
        int res = 3;
        bool us[40000];
        memset( us , 0 , sizeof(us) );
        while( res <= n ){
            if( primo[res] && primo[n-res] && !us[res] && !us[n-res] ){
                //cout<<res<<" "<<n-res<<endl;
                us[res] = 1; us[n-res] = 1;
                cont++;    
            }
            res += 2;
        }
        printf("%d\n",cont);
    }   
}
