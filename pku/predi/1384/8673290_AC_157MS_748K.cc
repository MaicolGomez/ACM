#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int inf = 200000000;
int p[501] , w[501], v[10001];

void doit(){
    int c , n , a;
    scanf("%d%d",&a,&c);
    c -= a;
    for(int i = 1 ; i <= c ; i++) v[i] = inf;
    v[0] = 0;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d",&p[i],&w[i]);
    }
    for(int i = 1 ; i <= c ; i++){
        for(int j = 0 ; j < n ;j++){
            if( i - w[j] >= 0 ){
                if( v[i - w[j]] + p[j] < v[i]  ) v[i] = v[i - w[j]] + p[j];
            }
        }
    }
    if( v[c] == inf ) puts("This is impossible.");
    else printf("The minimum amount of money in the piggy-bank is %d.\n",v[c]);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++) doit();
}
