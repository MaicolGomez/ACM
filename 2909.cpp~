#include<bits/stdc++.h>
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
#define N 100001

int f(int r,int c){
    if( r <= 6 or c <= 6 ) return 0;
    int x = (r - 6) / 2 , y = ( c - 6 ) / 2;
    return x * y;
}

int main(){
    int r , c , t;
    while( scanf("%d%d%d",&r,&c,&t) == 3 and r ){
        if( t ) printf("%d\n", f( r , c ) + f( r - 1 , c - 1 ) );
        else printf("%d\n", f( r , c - 1 ) + (r - 7) / 2 + f( r - 1 , c - 2 ) );
    }
    return 0;
}
