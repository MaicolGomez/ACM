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
#define fi first
#define se second
#define MOD 10009
#define N 1000005

struct tree{
    int x , flag;
    tree(){}
    tree(int X,int F){
        x = X;
        flag = F;
    }
};

tree T[4*N];

void init(int node, int x,int y){
    if( x == y ){
        T[node].x = 0;
        T[node].flag = 0;
        return;
    }
    T[node].flag = 0;
    int mid = (x+y)>>1;
    init( L(node) , x , mid );
    init( R(node) , mid + 1 , y );
    T[node].x = T[L(node)].x + T[R(node)].x;
}

void push(int node,int x,int y){
    if( T[node].flag ){
        if( x == y ) T[node].x = T[node].x^1;
        else{
            T[node].x = (y-x+1) - T[node].x;
            T[L(node)].flag ^= 1 , T[R(node)].flag ^= 1;
        }
    }
    T[node].flag = 0;
}

void update(int node,int x,int y,int a,int b){
    push( node , x , y );
    if( y < a || b < x ) return;
    if( a <= x && y <= b ){
        T[node].flag = 1;
        push( node , x , y );
        return;
    }
    int mid = (x+y)>>1;
    update( L(node) , x , mid , a , b );
    update( R(node) , mid + 1 , y , a , b );
    T[node].x = T[L(node)].x + T[R(node)].x;
}

int query(int node,int x,int y,int a,int b){
    //cout << x << " " << y << " " << a << " " << b << endl;
    push(node,x,y);
    if( y < a || b < x ) return 0;
    if( a <= x && y <= b )
        return T[node].x;
    int mid = (x+y)>>1;
    return query( L(node) , x , mid , a , b ) + query( R(node) , mid + 1 , y , a , b );
}

int main(){
    int n , q , a , b , p;
    sc(n),sc(q);
    init( 0 , 0 , n - 1 );
    while(q--){
        scanf("%d %d %d",&p,&a,&b);
        /*for(int i = 0 ; i < n ; i++) cout << query( 0 , 0 , n - 1 , i , i ) << " ";
        cout << endl;*/
        if( p == 0 ) update( 0 , 0 , n - 1 , a - 1 , b - 1 );
        else printf("%d\n",query( 0 , 0 , n - 1 , a - 1 , b - 1 ));
    }
    return 0;
}

                                               
