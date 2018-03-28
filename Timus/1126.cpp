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
#define inf (1<<29)
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
#define ios ios::sync_with_stdio(0);
#define N 25001

int T[4*N+5];

void update(int node,int x,int y,int z,int val){
    if( z < x or y < z ) return;
    if( x == y ){
        T[node] = val;
        return;
    }
    int mid = M(x,y);
    update( L(node) , x , mid , z , val );
    update( R(node) , mid + 1 , y , z ,val );
    T[node] = max( T[L(node)] , T[R(node)] );
}

int query(int node,int x,int y,int a,int b){
    if( y < a or b < x ) return 0;
    if( a <= x and y <= b ) return T[node];
    int mid = M(x,y);
    return max( query( L(node) , x , mid , a , b ) , query( R(node) , mid + 1 , y , a , b ) );
}

int main(){
    int x , m;
    int n = 0;
    sc(m);
    for(int i = 0 ; i < m ; i++){
        sc(x);
        update( 0 , 0 , N - 1 , n++ , x );
    }
    printf("%d\n",query( 0 , 0 , N - 1 , n - m , n - 1 ));
    while( sc( x ) == 1 and x != -1 ){
        update( 0 , 0 , N - 1 , n++ , x );
        printf("%d\n",query( 0 , 0 , N - 1 , n - m , n - 1 ));
    }
    return 0;
}
