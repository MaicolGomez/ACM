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
#define MOD 1000000007
#define N 50005

int A[N];
ll T[4*N];

void init(int node,int x,int y){
    if( x == y ){
        T[node] = A[x];
        return;
    }
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    init( v1 , x , mid );
    init( v2 , mid + 1 , y );
    T[node] = ( T[v1] * T[v2] )%MOD;
}

void update(int node,int x,int y,int a,ll v){
    if( y < a || a < x ) return;
    if( x == y ){
        T[node] = v;
        return;
    }
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    update( v1 , x , mid , a , v );
    update( v2 , mid + 1 , y , a , v );
    T[node] = ( T[v1] * T[v2] )%MOD;
}

ll query(int node,int x,int y,int a,int b){
    if( y < a || b < x ) return 1;
    if( a <= x && y <= b )
        return T[node];
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);    
    return ( query( v1 , x , mid , a , b ) * query( v2 , mid + 1 , y , a , b ) )%MOD;
}

int main(){
    int tc , n , q;
    sc(tc);
    while(tc--){
        sc(n);
        for(int i = 0 ; i < n ; i++)
            sc(A[i]);
        init( 0 , 0 , n - 1 );
        sc(q);
        int op , x , y;
        while( q-- ){
            scanf("%d%d%d",&op,&x,&y);
            if( op ) update( 0 , 0 , n - 1 , x - 1 , y );
            else printf("%lld\n", query( 0 , 0 , n - 1 , x - 1 , y - 1 ) );
        }
    }
    return 0;
}
