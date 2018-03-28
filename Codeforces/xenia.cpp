#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<queue>
using namespace std;
#define inf (1<<29)
#define ll long long
#define vi vector<int>
#define eps 1e-7
#define all(v) v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define L(x) ((x<<1)+ 1)
#define R(x) L(x)+1
#define M(x,y) ((x+y)>>1)
#define N (1<<17) + 5

int a[N] , n;
int T[4*N];

void init(int node,int x,int y,int niv){
    
    if( x == y ){
        T[node] = a[x];
        return;
    }
    int mid = M(x,y);
    init( L(node) , x , mid , niv + 1 );
    init( R(node) , mid + 1 , y , niv + 1 );
    if( n & 1 ){
        if( niv & 1 ) T[node] = T[L(node)]|T[R(node)];
        else T[node] = T[L(node)] ^ T[R(node)];
    }
    else{
        if( niv & 1 ) T[node] = T[L(node)] ^ T[R(node)];
        else T[node] = T[L(node)]|T[R(node)];
    }
}

void update(int node,int x,int y,int pos,int val, int niv){
    if( pos < x or y < pos ) return;
    if( x == y ){
        T[node] = val;
        return;
    }
    int mid = M(x,y);
    update( L(node) , x , mid , pos , val , niv + 1 );
    update( R(node) , mid + 1 , y , pos , val , niv + 1 );
    if( n & 1 ){
        if( niv & 1 ) T[node] = T[L(node)]|T[R(node)];
        else T[node] = T[L(node)] ^ T[R(node)];
    }
    else{
        if( niv & 1 ) T[node] = T[L(node)] ^ T[R(node)];
        else T[node] = T[L(node)] | T[R(node)];
    }
}

int main(){
    int q;
    while( scanf("%d%d",&n,&q) == 2 ){
        for(int i = 0 ; i < 1<<n ; i++)
            sc(a[i]);
        
        init(0 , 0 , (1<<n) - 1 , 1 );        
        int p , b;
        while( q-- ){
            scanf("%d%d",&p,&b);
            update( 0 , 0 , (1<<n) - 1 , p - 1 , b , 1 );
            printf("%d\n",T[0]);
        }
    }
}
