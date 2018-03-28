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
#define N 1000005

int C , n;
int T[4*N];

void init(int node,int x,int y){
    if( x == y ){
        T[node] = C;
        return;
    }
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    init( v1 , x , mid );
    init( v2 , mid + 1 , y );
    T[node] = max( T[v1] , T[v2] );
}

void update(int node ,int x,int y,int z,int val,int &ans){
    if( y < z || z < x ) return;
    if( x == y ){
        if( T[node] == C ) ans++;
        T[node] -= val;
        return;
    }
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    update( v1 , x , mid , z , val , ans );
    update( v2 , mid + 1 , y , z , val , ans );
    T[node] = max( T[v1] , T[v2] );
}

void query( int node , int x ,int y , int a , int b , int need , int &ans ){
    if( x == y ){
        update( 0 , 0 , n - 1 , x , need , ans );
        return;
    }
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    if( T[v1] >= need ) query( v1 , x , mid , a , b , need , ans );
    else query( v2 , mid + 1 , y , a , b , need , ans );
}

int main(){
    int tc , x , q;
    sc(tc);
    while( tc-- ){
        sc(C);
        sc(q);
        n = q;
        init( 0 , 0 , n - 1 );
        char s[10];
        int ans = 0 , S = 0;
        while( q ){
            scanf("%s",s);
            bool space = 0;
            if( s[0] == 'b' ){
                int k;
                scanf("%d %d",&x,&k);
                for(int i = 0 ; i < x ; i++)
                    query( 0 , 0 , n - 1 , 0 , n - 1 , k , ans );
                S += x * k;
                q -= x; 
            }
            else{
                int k = 0;
                for(int i = 0 ; i < strlen(s) ; i++)
                    k = k * 10 + (s[i]-'0');
                query( 0 , 0 , n - 1 , 0 , n - 1 , k , ans );
                S += k;
                q--;
            }
        }
        printf("%d %d\n",ans , ans * C - S );
    }
    return 0;
}
