#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<deque>
#include<queue>
#include<map>
#include<climits>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf (1<<30)
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define N 100005

struct tree{
    int mini , ct , flag;
    tree(){}
    tree(int a,int b){
        mini = a;
        ct = b;
    }
};

tree T[8*N];
int n , in[2*N] , out[2*N] , C , A[N];
vi adj[N] , Q[N];

void f(int u,int pa){
    in[u] = C++;
    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];
        if( v != pa ) f( v , u );
    }
    out[u] = C++;
}

void init(int node,int x,int y){
    T[node].flag = 0;
    if( x == y ){
        T[node].mini = 0;
        T[node].ct = 1;
        return;
    }
    int v1 = L(node) , v2 = R(node) , mid = M(x,y);
    init( v1 , x , mid );
    init( v2 , mid + 1 , y );
    if( T[v1].mini < T[v2].mini ) T[node].mini = T[v1].mini , T[node].ct = T[v1].ct;
    else if( T[v2].mini < T[v1].mini ) T[node].mini = T[v2].mini , T[node].ct = T[v2].ct;
    else T[node].mini = T[v1].mini + T[v2].mini , T[node].ct = T[v1].ct + T[v2].ct;
}

void push(int node,int x,int y){
    if( T[node].flag ){
        T[node].mini += T[node].flag;
        if( x != y ) T[L(node)].flag += T[node].flag , T[R(node)].flag += T[node].flag;
    }
    T[node].flag = 0;
}

void update(int node,int x,int y,int a,int b,int val){
    push( node , x , y );
    if( y < a || b < x ) return;
    if( a <= x && y <= b ){
        T[node].flag += val;
        push( node , x , y );
        return;
    }
    int v1 = L(node) , v2 = R(node) , mid = M(x,y);
    update( v1 , x , mid , a , b , val );
    update( v2 , mid + 1 , y , a , b , val );
    if( T[v1].mini < T[v2].mini ) T[node].mini = T[v1].mini , T[node].ct = T[v1].ct;
    else if( T[v2].mini < T[v1].mini ) T[node].mini = T[v2].mini , T[node].ct = T[v2].ct;
    else T[node].mini = T[v1].mini , T[node].ct = T[v1].ct + T[v2].ct;
}

tree query(int node,int x,int y,int a,int b){
    push( node , x , y );
    if( y < a || b < x ) return tree(inf,inf);
    if( a <= x && y <= b )
        return T[node];
    int v1 = L(node) , v2 = R(node) , mid = M(x,y);
    tree p = query( v1 , x , mid , a , b );
    tree q = query( v2 , mid + 1 , y , a , b );
    if( p.mini < q.mini ) return p;
    else if( q.mini < p.mini ) return q;
    else return tree( p.mini , p.ct + q.ct );
}

void dfs(int u,int pa){
    if( Q[u].size() ) update( 0 , 0 , C - 1 , in[u] , out[u] , Q[u].size() );
    for(int i = 0 ; i < Q[u].size() ; i++){
        int v = Q[u][i];
        update( 0 , 0 , C - 1 , in[v] , out[v] , 1 );
    }
    tree P = query( 0 , 0 , C - 1 , 0 , C - 1 );
    if( P.mini == 0 ) A[u] = max( n - P.ct/2 - 1 , 0 );
    else A[u] = n-1;
    //if( u == 7 ) cout << P.mini << " " << P.ct << endl;
    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];
        if( v != pa ) dfs( v , u );
    }
    if( Q[u].size() ) update( 0 , 0 , C - 1 , in[u] , out[u] , -Q[u].size() );
    for(int i = 0 ; i < Q[u].size() ; i++){
        int v = Q[u][i];
        update( 0 , 0 , C - 1 , in[v] , out[v] , -1 );
    }
}

int main(){
    int m , x , y;
    while( scanf("%d%d",&n,&m) == 2 ){
        for(int i = 0 ; i <= n ; i++)
            adj[i].clear() , Q[i].clear();
        for(int i = 0 ; i < n - 1 ; i++){
            sc(x),sc(y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for(int i = 0 ; i < m ; i++){
            sc(x),sc(y);
            Q[x].pb(y);
            Q[y].pb(x);
        }
        C = 0;
        f( 1 , -1 );
        init( 0 , 0 , C - 1 );
        dfs( 1 , -1 );
        for(int i = 1 ; i <= n ; i++)
            printf("%d ",A[i]);
        printf("\n");
    }
    return 0;
}
