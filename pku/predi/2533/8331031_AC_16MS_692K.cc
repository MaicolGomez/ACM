#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

int main(){
    int n;
    int a[1001] , val[1001];
    cin>> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        val[i] = 1;
    }
    int mayor = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if( val[j] + 1 > val[i] ) if( a[j] < a[i] ) val[i] = val[j] + 1;
        }
        mayor = max( mayor , val[i] );
    }
    printf("%d\n",mayor);
}
