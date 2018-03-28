#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<string>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-8

int n,v[205],T[205][205],s[205][205];
double F;

void precalc(){
    for(int i = 0 ; i < n; i++) memset( s[i] , 0 , sizeof(int)*(n) );
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            for(int k=i;;k++){
                if(k>=n)k%=n;
                s[i][j]+=v[k];
                if(k==j)break;
            }
        
            
}

int f(int ini,int fin){
    if(ini==fin)return 0;
    int &ret=T[ini][fin];
    if(ret!=-1)return ret;
    ret=inf;
    for(int a=ini;;++a){
        if(a>=n)a%=n;
        if(a==fin)break;
        int b=(a+1);
        if( b>=n )b%=n;
        ret=min(ret,max( s[ini][a] ,s[b][fin] )+f(ini,a)+f(b,fin));
    }
    return ret;
}

void doit(){
    for(int i=0;i<n;++i){
        scanf("%d",&v[i]);
    }
    precalc();
    int menor=inf;
    for(int i = 0 ; i < n; i++) memset( T[i] , -1 , sizeof(int)*(n) );
    if(n==1){
        printf("0.00\n"); return;
    }
    for(int i=0;i<n;++i){
        menor=min(menor,f(  (i+1) % n , i  ) );
    }
    printf("%.2lf\n",F*menor);
}

int main(){
    while(scanf("%d%lf",&n,&F)){
          if(n==0&&F==0.0)break;
          doit();
    }
}