#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
#define maxi 1000000000000000000LL
using namespace std;
vector<long long> v;
void precal(){
    for(long long i = 1 ; i <= maxi ; i*=2){
        for(long long j = 1 ; j*i <= maxi ; j*=3){
            for(long long k = 1; j*i*k <= maxi ; k*=5){
                for(long long r = 1 ; r*j*i*k <= maxi ; r*=7){
                    v.push_back(i*j*r*k);
                }
            }
        }
    }
    sort( v.begin() , v.end() );
    v.resize( unique( v.begin() , v.end() ) - v.begin() );
}

void doit(){
    int n;
    scanf("%d",&n);
    cout<<v[n-1]<<endl;
}

int main(){
    precal();
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++) doit();
}
