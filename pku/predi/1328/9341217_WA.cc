#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-8
int n,d;
double x1[1001],x2[1001];

int calc(){
    int res = 0;
    for(int i = 0 ; i < n ; i++){
        int j,a=0;
        for(j = 0 ; j < n ; j++){
            if(i==j)continue;
            if( x1[j] <= x1[i] && x2[i] <= x2[j] ) a++;
        }
        if(a==0) res++;
    }
    return res;
}
int test=0;
void doit(){
    double u,v,dx;
    int res = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> u >> v;
        if(v>d){ res=-1;continue;}
        dx = sqrt(d*d-v*v);
        x1[i] = u - dx , x2[i] = u + dx;
    }
    if(res!=1) res = calc();
    printf("Case %d: %d\n",++test,res);
}

int main(){
    while(scanf("%d%d",&n,&d)==2){
        if(!(n||d)) return 0;
        doit();
    }
}