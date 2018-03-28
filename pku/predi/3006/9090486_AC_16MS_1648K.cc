#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<map>
using namespace std;
#define ll (long long)
#define inf (1<<30)
#define MAX 1000000
bool prime[1000001];

void criba(){
    memset(prime,1,sizeof(prime));
    prime[1]=0;
    for(int i=2;i*i<=MAX;i++)
        if(prime[i])
            for(int j=i*i;j<=MAX;j+=i) prime[j]=0;
}

int a,d,n;

void doit(){
    int num = a;
    int cont = 0;
    if(n==0&&prime[num]){ printf("%d\n",num);return;}
    while(1){
        if(prime[num])cont++;
        if(cont==n){ printf("%d\n",num);break;}
        num+=d;
    }
}

int main(){
    criba();
    while(scanf("%d%d%d",&a,&d,&n)==3){
        if(!a&&!d&&!n) break;
        doit();
    }
}
