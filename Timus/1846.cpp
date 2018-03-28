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
#define MM(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 100011

int T[3*N];

int gcd(int x,int y){
    if( y > x ) swap( x , y );
    if( x == 0 and y == 0 ) return 0;
    if( y == 0 ) return x;
    return gcd( y , x%y );
}

void init(int node,int x,int y){
    if( x == y ){
        T[node] = 0;
        return;
    }
    int mid = MM(x,y);
    init( L(node) , x , mid );
    init( R(node) , mid + 1 , y );
    T[node] = gcd( T[L(node)] , T[R(node)] );
}

int F[N];

void update(int node,int x,int y,int z,int val){
    if( z < x or y < z ) return;
    if( x == y and x == z ){
        T[node] = val;
        return;
    }
    int mid = MM(x,y);
    update( L(node) , x , mid , z , val );
    update( R(node) , mid + 1 , y , z , val );
    T[node] = gcd( T[L(node)] , T[R(node)] );
}

int main(){
    int n , x;
    sc(n);
    //init( 0 , 0 , n - 1 );
    char s[10];
    map< int , int > M;
    int ct = 0;
    int nn = n;
    while( n-- ){
        scanf("%s%d",s,&x);
        if( M.find( x ) == M.end() ) M[x] = ct++;
        int ind = M[x];
        if( s[0] == '+' ){
            if( !F[ind] ) update( 0 , 0 , nn - 1 , ind , x );
            F[ind]++;
        }
        else{
            if( F[ind] == 1 ) update( 0 , 0 , nn - 1 , ind , 0 );
            F[ind]--;
        }
        printf("%d\n",T[0]?T[0]:1 );
    }
    return 0;
}
