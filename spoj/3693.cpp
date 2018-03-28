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
#define fi first
#define se second
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define MOD 10009
#define N 100005

struct tree{
    int m1 , m2;
    tree(){}
    tree( int M1 ,int M2 ){
        m1 = M1 , m2 = M2;
    }
};

tree T[4*N];
int a[N];

void init(int node,int x,int y){
    if( x == y ){
        T[node].m1 = a[x];
        T[node].m2 = -1;
        return;
    }
    int v1 = L(node) , v2 = R(node) , mid = (x+y)/2;
    init( v1 , x , mid );
    init( v2 , mid + 1 , y );
    if( T[v1].m1 > T[v2].m1 )
        T[node].m1 = T[v1].m1 , T[node].m2 = max( T[v1].m2 , T[v2].m1 );
    else 
        T[node].m1 = T[v2].m1 , T[node].m2 = max( T[v1].m1 , T[v2].m2 );
}

void update( int node , int x ,int y , int z , int nval ){
    if( y < z || z < x ) return;
    if( x == y ){
        T[node].m1 = nval;
        T[node].m2 = -1;
        return;
    }
    int v1 = L(node) , v2 = R(node) , mid = (x+y)/2;
    update( v1 , x , mid , z , nval );
    update( v2 , mid + 1 , y , z , nval );
    if( T[v1].m1 > T[v2].m1 )
        T[node].m1 = T[v1].m1 , T[node].m2 = max( T[v1].m2 , T[v2].m1 );
    else 
        T[node].m1 = T[v2].m1 , T[node].m2 = max( T[v1].m1 , T[v2].m2 );
}

tree query(int node,int x,int y,int a,int b){
    if( y < a || b < x ) return tree(-1,-1);
    if( a <= x && y <= b )
        return T[node];
    int v1 = L(node) , v2 = R(node) , mid = (x+y)/2;
    tree A = query( v1 , x , mid , a , b );
    tree B = query( v2 , mid + 1 , y , a , b );
    if( A.m1 > B.m1 )
        return tree( A.m1 , max( A.m2 , B.m1 ) );
    return tree( B.m1 , max( A.m1 , B.m2 ) );
}


int main(){
    int n , aa , b;
    sc(n);
    for(int i = 0 ; i < n ; i++)
        sc(a[i]);
    
    init( 0 , 0 , n - 1 );
    int q;
    sc(q);
    char s[2];
    while(q--){
        scanf("%s",s);
        sc(aa),sc(b);
        if( s[0] == 'U' ) update( 0 , 0 , n - 1 , aa - 1 , b );
        else{
            tree ans = query( 0 , 0 , n - 1 , aa - 1 , b - 1 );
            printf("%d\n",ans.m1+ans.m2);
        }    
    }
    return 0;
}
