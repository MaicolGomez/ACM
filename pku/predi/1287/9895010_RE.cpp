#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<string>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf (1<<30)
#define me( arr , val ) memset( arr , val , sizeof(arr) );
#define eps 1e-8
#define ll long long
#define vi vector<int> 
#define all(v) v.begin() , v.end()
#define N 200

struct nodo{
    int u , v , w;
    nodo(){}
    nodo(int U, int V, int W ){
        u = U, v = V,w = W;
    }
};

bool operator <(nodo A,nodo B){
    return A.w < B.w;
} 

int n , m , p[100] , rank[100];
nodo L[1000];

void makeset(){
    for(int i = 1 ; i <= n ; i++) p[i] = i , rank[i] = 0;
}

int FIND(int x){
    if( p[x] != x )
        p[x] = FIND( p[x] );
    return p[x];
}

void UNION(int x, int y){
    int a = FIND(x);
    int b = FIND(y);
    p[a] = b;
}

void lee(){
    int x , y , w;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y >> w;
        L[i].u = x , L[i].v = y , L[i].w = w;
    }
}

void solve(){
    makeset();
    sort( L , L + m );
    int res = 0;
    for(int i = 0 ; i < m ; i++){
        if( FIND( L[i].u ) != FIND( L[i].v ) ){
            UNION( L[i].u , L[i].v );
            res += L[i].w;
        }
    }
    printf("%d\n",res);
}

int main(){
    while( cin >> n && n ){
        cin >> m;
        lee();
        solve();
    }
}