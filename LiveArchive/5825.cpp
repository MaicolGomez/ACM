#include<bits/stdc++.h>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf INT_MAX
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
#define N 2000000

int a[N + 5];
int A[N + 5];
int RMQ[25][N + 5];
//int T[4 * N];


void init(int n){
    /*if( a == b ){
        T[node] = A[a];
        return;
    }
    int mid = M(a,b);
    init( L(node) , a , mid );
    init( R(node) , mid + 1 , b);
    T[node] = min( T[L(node)] , T[R(node)] );
    return;*/
    for(int i = 0 ; i < n ; i++) RMQ[0][i] = A[i];
    for(int j = 1 ; (1<<j) <= n ; j++)
        for(int i = 0 ; i + (1<<j) - 1 < n ; i++)
            RMQ[j][i] = min( RMQ[j-1][i] , RMQ[j-1][i + (1<<(j-1)) ] );
    
}

int query(int i,int j){
    /*if( b < x or y < a ) return inf;
    if( x <= a and b <= y ) return T[node];
    int mid = M(a,b);
    return min( query( L(node) , a , mid , x , y ) , query( R(node) , mid + 1 , b , x , y ) );*/
    int k = 1;
    for(k = 1 ; 1<<k <= (j - i + 1) ; k++);
    k--; 
    return min( RMQ[k][i] , RMQ[k][j - (1<<k) + 1] );
}

int main(){
    int n;
    while( ~sc(n) and n ){
        for(int i = 0 ; i < n ; i++){
            sc(a[i]);
            a[i + n] = a[i];
        }
        A[0] = a[0];
        for(int i = 1 ; i < 2 * n ; i++)
            A[i] = A[i - 1] + a[i];
        
        init( 2 * n - 1 );
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            if( query( i , i + n - 1 ) >= (i?A[i-1]:0) ) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
