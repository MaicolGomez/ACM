#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
#define inf (1<<30)

int t[2000005], prox[2000005] , sol[2000005];
bool used[ 2000005 ];
void precal(){
    for(int i = 3 ; i <= 600000 ; i++){
        vector<int> v;
        int n = t[i-1];
        for(long long j = 2 ; j*j <= n ; j++){
            if(n%j==0){
                v.push_back(j);
                while(n%j==0){ n/=j; }
            }
        }
        if(n > 1) v.push_back(n);
        int mini = inf,pos,prime = 0;
        for(int j = 0 ; j < v.size() ; j++){
            pos = prox[ v[j] ];
            while( used[pos] ){
                pos+=v[j];
                if(pos > mini)break;
            }
            if( pos < mini ){  
                prime = v[j];
                mini = pos;
            }
        }
        prox[ prime ] = mini;
        used[mini] = 1;
        t[i] = mini;
        sol[mini] = i;
    }
}

int main(){
    t[1] = 1;
    t[2] = 2;
    sol[1] = 1;
    sol[2] = 2;
    used[1] = 1;
    used[2] = 1;
    prox[2] = 4;
    for(int i = 3 ; i <= 1000000 ; i+=2) prox[i] = i;
    precal();
    int n;
    while( scanf("%d",&n) == 1 && n ){
        printf("The number %d appears in location %d.\n",n,sol[n] );
    }
}
