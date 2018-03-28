#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int n , a;
vector <int> v[102];
int f(int piso , int lugar , int suma ){
    if( piso == n + 1) return suma;
    return max( f( piso + 1 , lugar , suma + v[piso][lugar] ) , f( piso + 1 , lugar+1 , suma + v[piso][lugar] ) );
}

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++){
        v[i].clear();
        v[i].push_back(0);
        for(int j = 1 ; j <= i ; j++ ){
            scanf("%d",&a);
            v[i].push_back( a );
        }
    }
    printf("%d\n", max( f( 2 , 1 , v[1][1] ) , f( 2 , 2 , v[1][1] ) ) );
}
