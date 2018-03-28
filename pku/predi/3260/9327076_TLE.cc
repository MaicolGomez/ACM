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

int N,S,a[105],coin[105];
int t1[20005][105] , t[20005];

int f(int suma , int pos){
    if(pos==N){
        if(suma==0)return 0;
        return inf;
        
    }
    int &ret = t1[suma][pos];
    if(ret!=-1) return ret;
    ret = inf;
    for(int i = 0 ; i <= coin[pos] ; i++){
        if(suma>=a[pos]*i)
            ret = min(ret , i + f(suma - a[pos]*i , pos + 1) );
    }
    return ret;
}

int g(int suma){
    if(suma==0) return 0;
    int &ret = t[suma];
    if(ret!=-1) return ret;
    ret = inf;
    for(int i = 0 ; i < N ; i++){
        if( suma-a[i] >= 0 ){
            ret = min( ret , 1 + g( suma - a[i] ) );
        }
    }
    return ret;
}

int main(){
    cin >> N >> S;
    for(int i = 0 ; i < N ; i++) cin >> a[i];
    for(int i = 0 ; i < N ; i++) cin >> coin[i];
    memset(t1 , -1 ,sizeof(t1));
    memset( t , -1 ,sizeof(t) );
    int ret = inf;
    for(int i = S ; i <= S+10000; i++){
        int q = f(i,0);
        int p = g(i-S);
        if(p!=inf&&q!=inf) ret = min( ret , p+q );
    }
    if(ret!=inf)printf("%d\n",ret);
    else printf("-1\n");
}