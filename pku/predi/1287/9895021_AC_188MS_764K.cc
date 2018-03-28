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

int n , m , p[100];

struct nodo{
    int u , v , w;
    nodo(){}
    nodo(int U, int V, int W ){
        u = U, v = V ,w = W;
    }
    bool operator<(nodo A)const{
        return w < A.w;
    }
};

void makeset(){
    for(int i = 0 ; i <= n ; i++) p[i] = i ;
}

int FIND(int x){
    if( p[x] != x )
        p[x] = FIND( p[x] );
    return p[x];
}

void UNION(int x, int y){
    x = FIND(x);
    y = FIND(y);
    p[x] = y;
}

vector<nodo> v;
void lee(){
    v.clear();
    int x , y , w;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y >> w;
        x-- , y--;
        v.push_back( nodo(x , y , w) );
    }
    sort( all(v) );
}

void solve(){
    makeset();
    int res = 0;
    for(int i = 0 ; i < v.size() ; i++){
        if( FIND( v[i].u ) != FIND( v[i].v ) ){
            UNION( v[i].u , v[i].v );
            res += v[i].w;
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