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
    int m0 , m1 , m2 , flag;
    tree(){}
};

tree T[3*N];

void init(int node,int x,int y){
    T[node].flag = 0;
    if( x == y ){
        T[node].m0 = 1;
        T[node].m1 = T[node].m2 = T[node].flag = 0;
        return;
    }
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    init( v1 , x , mid );
    init( v2 , mid + 1 , y );
    T[node].m0 = (y-x+1);//T[v1].m0 + T[v2].m0;
    //T[node].m1 = T[v1].m1 + T[v2].m1;
    //T[node].m2 = T[v1].m2 + T[v2].m2;
}

inline void push(int node,int &x,int &y){
    if( T[node].flag ){
        int g = T[node].flag;
        if( g > 3 ) g %= 3;
        if( g == 1 ){
            int p = T[node].m0 , q = T[node].m1 , s = T[node].m2;
            T[node].m0 = s;
            T[node].m1 = p;
            T[node].m2 = q;
        }
        else if( g == 2 ){
            int p = T[node].m0 , q = T[node].m1 , s = T[node].m2;
            T[node].m0 = q;
            T[node].m1 = s;
            T[node].m2 = p;
        }
        if( x != y ) T[L(node)].flag += g , T[R(node)].flag += g;
    }
    T[node].flag = 0;
}

void update(int node,int x,int y,int a,int b){
    push(node,x,y);
    if( y < a || b < x ) return;
    if( a <= x && y <= b ){
        T[node].flag++;
        push(node,x,y);
        return;
    }
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    update( v1 , x , mid , a , b );
    update( v2 , mid + 1 , y , a , b );
    T[node].m0 = T[v1].m0 + T[v2].m0;
    T[node].m1 = T[v1].m1 + T[v2].m1;
    T[node].m2 = T[v1].m2 + T[v2].m2;
}

int query(int node,int x,int y,int a,int b){
    push(node,x,y);
    if( y < a || b < x ) return 0;
    if( a <= x && y <= b )
        return T[node].m0;
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    int A = query( v1 , x , mid , a , b );
    int B = query( v2 , mid + 1 , y , a , b );
    return A + B;
}

int main(){
    int n , q , op , x , y;
    scanf("%d%d",&n,&q);
    init( 0 , 0 , n - 1 );
    while( q-- ){
        scanf("%d%d%d",&op,&x,&y);
        if( op ) printf("%d\n", query( 0 , 0 , n - 1 , x , y  ) );
        else update( 0 , 0 , n - 1 , x , y );
    }
    return 0;
}
