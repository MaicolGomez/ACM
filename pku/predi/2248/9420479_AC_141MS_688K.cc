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

int n,size;
int res[105] , a[105];
int dis[202];
void dfs(int tam){
    if(tam + dis[a[tam]] >= size)return ;
    if(tam>=size) return;
    if( a[tam] == n ){
        if( tam >= size ) return;
        size = tam;
        for(int i = 0 ; i <= tam ; i++) res[i] = a[i]; return;
    }
    for(int i = 0 ; i <= tam ; i++){
        for(int j = 0 ; j <= i ; j++){
            int r = a[i] + a[j];
            if( r > a[tam] && r <= n ){
                a[tam+1] = r , dfs(tam+1);
            }
        }
    }
}

void doit(){
    size = inf;
    a[0] = 1;
    for(int i = n - 1; i > 0; i --)dis[i] = dis[i + i] + 1;
    dfs( 0 );
    for(int i = 0 ; i <= size ; i++){
        if(i) printf(" ");
        printf("%d",res[i]);
    }
    printf("\n");
}

int main(){
    while( scanf("%d",&n) == 1 && n ){
        doit();
    }
}