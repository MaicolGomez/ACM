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
#define N 100005

int a[N] , T[4*N];

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

int b[N];

int query(int node,int x,int y,int a,int b){
    if( b < x or y < a ) return inf;
    if( a <= x and y <= b )
        return T[node];
    int mid = M(x,y);
    int p = query( L(node) , x , mid , a , b );
    int q = query( R(node) , mid + 1 , y , a , b );
    return min( p , q );
}

void update(int node,int x,int y,int z,int val){
    if( z < x or y < z ) return;
    if( x == y and x == z ){
        T[node] = val;
        return;
    }
    int mid = M(x,y);
    update( L(node) , x , mid , z , val );
    update( R(node) , mid + 1 , y , z , val );
    T[node] = min( T[L(node)] , T[R(node)] );
}

int main(){
    int n , q;
    scanf("%d%d",&n,&q);
    for(int i = 0 ; i < n ; i++)
        sc(a[i]);
    
    init( 0 , 0 , n - 1 );
    char s[50];
    int p[50];
    while( q-- ){
        scanf("%s",s);
        if( s[0] == 's' ){
            int l = strlen(s);
            int r = 0 , x = 0;
            for(int i = 0 ; i < l ; i++){
                if( s[i] >= '0' and s[i] <= '9' ){
                    x = x * 10 + (s[i] - '0');
                }
                else if( x ) p[r++] = x - 1 , x = 0;
            }
            for(int i = 0 ; i < r ; i++)
                b[p[i]] = a[p[i]];
            
            for(int i = 0 ; i < r ; i++)
                a[p[i]] = b[ p[(i+1)%r] ];
            
            for(int i = 0 ; i < r ; i++)
                update( 0 , 0 , n - 1 , p[i] , a[p[i]] );
        }
        else{
            int l = strlen(s);
            int r = 0 , x = 0;
            for(int i = 0 ; i < l ; i++){
                if( s[i] >= '0' and s[i] <= '9' ){
                    x = x * 10 + (s[i] - '0');
                }
                else if( x ) p[r++] = x - 1 , x = 0;
            }
            printf("%d\n",query( 0 , 0 , n - 1 , p[0] , p[1] ));
        }
    }
    
    return 0;
}
