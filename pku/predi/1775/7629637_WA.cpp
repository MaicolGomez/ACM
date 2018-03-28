#include<iostream>
#include<cmath>
#include<cctype>
#include<deque>
#include<cstdio>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int fact[100];

void llena(){
    fact[1]=1; 
    for(int i = 2 ; i <= 10 ; i++)
        fact[i]=fact[i-1]*i;    
}

bool a[10];

int main(){
    llena();
    while( cin >> n){
        if( n < 0 ) break;
        int apro=n;
        memset(a , 0 , 10 );
        bool es = false;
        while( true ){
            apro=n;
            if(n == 0){
                es = true;
                break;    
            }
            if(n < 0) break;
            for(int i = 1; i <= 10 ; i++ ){
                if( fact[i] > apro && a[i-1] == false){
                    apro = fact[i-1];
                    a[i-1] = true;
                    break;    
                }     
            }
            n = n-apro;    
        }
        if(es) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;                   
    }  
}
