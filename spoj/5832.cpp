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
#define N 20005
int A[N] , T[4*N];

void init(int node,int x,int y){
    if( x == y ){
        T[node] = A[x];
        return;
    }
    int mid = (x+y)>>1;
    init(L(node) , x , mid);
    init(R(node) , mid + 1 , y);
    T[node] = T[L(node)]&T[R(node)];
}

int query(int node,int x,int y,int a,int b){
    if( y < a || x > b ) return ~0;
    if( a <= x && y <= b )
        return T[node];
    int mid = (x+y)>>1;
    return query( L(node) , x , mid , a , b ) & query( R(node) , mid + 1 , y , a , b );
}

int main(){
    int tc , n , k;
    sc(tc);
    while(tc--){
        sc(n),sc(k);
        int ans = ~0;
        for(int i = 0 ; i < n ; i++)
            sc(A[i]) , ans &= A[i];
        if( k * 2 >= n ){
            for(int i = 0 ; i < n ; i++){
                if(i) printf(" ");
                printf("%d",ans);
            }
            printf("\n");
        }
        else{
            init(0,0,n-1);
            for(int i = 0 ; i < n ; i++){
                int u = (i - k + n) % n , v = (i+k)%n;
                int ans = ~0;
                if( u < i ) ans &= query( 0 , 0 , n - 1 , u , i );
                else ans &= query( 0 , 0 , n - 1 , 0 , i ) & query( 0 , 0 , n - 1 , u , n - 1 );
                if( i < v ) ans &= query( 0 , 0 , n - 1 , i , v ); 
                else ans &= query( 0 , 0 , n - 1 , i , n - 1 ) & query( 0 , 0 , n - 1 , 0 , v );
                if( i ) printf(" ");
                printf("%d",ans);
            }
            printf("\n");
        }
    }
    return 0;
}
