#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int f(int n){
    int num = 1;
    for(int i = 2 ; i*i <= n ; i++){
        if( n % i == 0 ){
            num = max( num , i);
            while( n % i == 0 ) n /= i;
        }
    }
    if( n > 1 ) num = max( num , n );
    return num;
}

int main(){
    int t , a;
    scanf("%d",&t);
    vector<int> v;
    for(int i = 0 ; i < t ; i++){ scanf("%d",&a); v.push_back(a); }
    int maxi = -1, sol;
    for(int i = 0 ; i < v.size() ; i++){
        int r = f( v[i] );
        if( r > maxi ){
            maxi = r;
            sol = v[i];
        }
    }
    printf("%d\n",sol);
}
