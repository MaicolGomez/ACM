#include <cstdlib>
#include <cstdio>
#define MAX 64
using namespace std;
/*因为在64位以内，所以质数个数最多为64个*/
int p,factor[MAX],num[MAX];
/*土土地分解质因数*/
void factorize(unsigned long long a){
    p=0;
    int i;
    for(i=2;i*i<=a;i++){
        if(a%i==0){
            factor[p]=i; num[p]=1;
            a/=i;
            while(a%i==0){
                num[p]++;
                a/=i;
            }
            p++;
        }
    }
    if(a!=1){
        factor[p]=a;
        num[p++]=1;
    }
}
/*递推方式求catalan*/
unsigned long long catalan(int n){
    unsigned long long tmp=1;
    int i=1;
    if(n==0) return 1;
    tmp=1;
    while((i++)!=n){
        tmp=tmp*(4*i-2)/(i+1);
    }
    return tmp;
}
/*可重复排列的公式：n!/(p1!*p2!*....pk!),其中p1+p2+....+pk=n
 用分解为质因子的方法避免大整数*/
unsigned long long repeat_sort(int n){
    unsigned long long ret=1;
    int tn[64],tmp,i,j,k;
//计算n!
    for(i=0;i<64;i++) tn[i]=0;
    for(i=2;i<=n;i++){
        tmp=i;
        for(j=2;j<64;j++){
            if(tmp==1) break;
            while(tmp%j==0){
                tn[j]++;
                tmp/=j;
            }
        }
    }
//除去分母p1!*p2!*.....*pk!
    for(i=0;i<p;i++){
        for(j=2;j<=num[i];j++){
            tmp=j;
            for(k=2;k<64;k++){
                if(tmp==1) break;
                while(tmp%k==0){
                    tn[k]--;
                    tmp/=k;
                }
            }
        }
    }
//可重复排列的结果
    for(i=0;i<64;i++){
        while(tn[i]>0){
            ret*=i;
            tn[i]--;
        }
    }
    return ret;
}
#include<iostream>

int main(int argc, char** argv) {
    unsigned long long N,ans;
    int n,i;
    while(scanf("%llu",&N)!=EOF){
           factorize(N);
           n=0;
           for(i=0;i<p;i++) n+=num[i];
           ans=catalan(n-1)*repeat_sort(n);
           printf("%llu\n",ans);
    }
    return 0;
}
