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
#define N 100050

int T[4*N] , a[N];

void init(int node,int x,int y){
    if( x == y ){
        T[node] = a[x];
        return;
    }
    int mid = M(x,y);
    init( L(node) , x , mid );
    init( R(node) , mid + 1 , y );
    T[node] = min( T[L(node)] , T[R(node)] );
}

int query(int node,int x,int y,int a,int b){
    if( b < x or y < a ) return INT_MAX;
    if( a <= x and y <= b )
        return T[node];
    int mid = M(x,y);
    int p = query( L(node) , x , mid , a , b );
    int q = query( R(node) , mid + 1 , y , a , b);
    //cout << a << " " << b << " --> " << p << " " << q << endl;
    return min( p , q );
}

int main(){
    int tc , test = 1;
    sc(tc);
    while(tc--){
        int n , q;
        sc(n) , sc(q);
        for(int i = 0 ; i < n ; i++)
            sc(a[i]);
        
        init( 0 , 0 , n - 1 );
        int x , y;
        printf("Scenario #%d:\n",test++);
        while( q-- ){
            scanf("%d%d",&x,&y); x--,y--;
            
            printf("%d\n",query( 0 , 0 , n - 1 , x , y ));
        }
    }
    return 0;
}
