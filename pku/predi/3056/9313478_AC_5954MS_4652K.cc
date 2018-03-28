#include<cstdio>

#include<algorithm>

#include<cstring>

#include<iostream>

#include<vector>

#include<sstream>
#include<string>

using namespace std;

#define inf (1<<30)
#define  eps 1e-8

int a[1005] , t[1005][1005];

int f(int ini , int fin){
    if(fin < ini) return 0;
    if(ini+1==fin){
        return ( a[ini] == a[fin] );
    }
    int &ret = t[ini][fin];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i = ini + 1 ; i <= fin ; i+=2){
        int x = (a[ini] == a[i]);
        int p =  f( ini + 1 , i - 1 );
        int q =  f( i + 1 , fin);
        ret = max( ret , (x+p+q) );
    }
    return ret;
}

void doit(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    memset( t , -1 , sizeof(t) );
    int r = 0;
    r = f(0 , n - 1 );
    printf("%d\n",r);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++) doit();
}