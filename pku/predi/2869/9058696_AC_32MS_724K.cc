#include<iostream>
#include<sstream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n , a;
bool valida( vector <int> v){
    sort( v.begin() , v.end() );
    for(int i = 0 ; i < n ; i++){
        if( v[i] != i + 1) return false;    
    }
    return true;
}

int main(){
    while( scanf("%d",&n) ){
        if( n == 0 ) break;
        vector <int> v , res;
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&a);
            v.push_back(a);
        }     
        if( valida( v ) ){
            for(int i = 0 ; i < n - 1 ; i++){
                for(int j = 0 ; j < n - 1 ; j++){
                    if( v[j] > v[j+1] ){
                        swap( v[j] , v[j+1] );
                        res.push_back(j+1);    
                    }
                }
            }        
            int tam = res.size();
            //cout<<tam<<"  >>>";
            printf("%d",tam);
            for(int i = 0 ; i < res.size() ; i++){
                printf(" %d",res[i]);    
            }
            puts("");
        }
        else puts("No solution");
    }
}