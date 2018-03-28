#include<cstdio>
using namespace std;

int g(int x,int d){
    int ret=0;
    while(x>0){
        if(x%10==d){
            ++ret;
        }
        x/=10;
    }
    return ret;
}

int f(int x,int d){
    if(x<10){
        if(d==0)return 0;
        return d<=x;
    }
    int ret=x/10-(d==0)+f(x/10-1,d)*10;
    for(int i=(x/10)*10;i<=x;++i){
        ret+=g(i,d);
    }
    return ret;
}

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)==2&&a>0){
        printf("%d",f(b,0)-f(a-1,0));
        for(int i=1;i<=9;++i){
            printf(" %d",f(b,i)-f(a-1,i));
        }
        puts("");
    }
}
