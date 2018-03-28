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
using namespace std;
#define inf (1<<29)
#define eps 1e-8
#define ll long long
#define vi vector<int>
#define all(v) v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define N 100002
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)


struct tree{
    int best , fx , x , fy , y;
    tree(){}
    tree(int B){
        best = B;
    }
};

tree T[4*N];
int a[N];

void init(int node,int x,int y){
    if( x == y ){
        T[node].best = 1;
        T[node].x = a[x];
        T[node].fx = 1;
        T[node].y = a[x];
        T[node].fy = 1;
        return;
    }
    int mid = (x+y)/2;
    int v1 = L(node) , v2 = R(node);
    init( v1 , x , mid );
    init( v2 , mid + 1 , y );
    if( T[v1].x == T[v2].x ) T[node].x = T[v1].x , T[node].fx = T[v1].fx + T[v2].fx;
    else T[node].x = T[v1].x , T[node].fx = T[v1].fx;
    if( T[v2].y == T[v1].y ) T[node].y = T[v2].y , T[node].fy = T[v1].fy + T[v2].fy;
    else T[node].y = T[v2].y , T[node].fy = T[v2].fy;
    if( T[v1].best > T[v2].best ) T[node].best = T[v1].best;
    else T[node].best = T[v2].best;
    if( T[v1].y == T[v2].x )
        if( T[v1].fy + T[v2].fx > T[node].best ) T[node].best = T[v1].fy + T[v2].fx;
}

tree query(int node,int x ,int y,int a,int b){
    if( y < a || b < x ) return tree(-1);
    if( a <= x && y <= b )
        return T[node];
    int v1 = L(node) , v2 = R(node);
    int mid = (x+y)/2;
    tree A = query( v1 , x , mid , a , b );
    tree B = query( v2 , mid + 1 , y , a , b );
    if( A.best == -1 ) return B;
    else if( B.best == -1 ) return A;
    else{
        tree ans;
        if( A.x == B.x ) ans.x = A.x , ans.fx = A.fx + B.fx;
        else ans.x = A.x , ans.fx = A.fx;
        if( B.y == A.y ) ans.y = B.y , ans.fy = A.fy + B.fy;
        else ans.y = B.y , ans.fy = B.fy;
        
        if( A.best > B.best ) ans.best = A.best;
        else ans.best = B.best;
        if( A.y == B.x )
            if( A.fy + B.fx > ans.best ) ans.best = A.fy + B.fx;
        return ans;
    }
}

int main(){
    int n , q , x , y;
    while( sc(n) && n != 0 ){
        sc(q);
        for(int i = 0; i < n ; i++)
            sc(a[i]);
        init( 0 , 0 , n - 1 );
        while( q-- ){
            scanf("%d%d",&x,&y); x--,y--;
            tree ans = query( 0 , 0 , n - 1 , x , y );
            printf("%d\n",ans.best);
        }
    }
    
}
