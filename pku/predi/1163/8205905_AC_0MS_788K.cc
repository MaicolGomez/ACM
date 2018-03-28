#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int n , a , tabla[100*51+1];
vector <int> v;
int f(int lugar , int piso ){
    if( piso == n + 1 ) return 0;
    int &ret = tabla[lugar];
    if( ret != -1 ) return ret;
    tabla[lugar] = v[lugar] + max( f( piso + lugar , piso + 1 ) , f( piso + lugar + 1 , piso + 1) );
    return tabla[lugar];
}

int main(){
    scanf("%d",&n);
    for(int i = 0 ; i < 100*51 + 1 ; i++) tabla[i] = -1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++ ){
            scanf("%d",&a);
            v.push_back( a );
        }
    }
    printf("%d\n", f( 0 , 1 ) );
}
