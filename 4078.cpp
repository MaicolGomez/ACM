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
#define ios ios::sync_with_stdio(0)
#define N 100

int n , t[N+4][3][2];
vector<pii> P;

int f(int x,int y,int up){
    if( x == 100 ) return y == 0;
    int &ret = t[x][y][up];
    if( ret != -1 ) return ret;
    ret = 0;
    bool ok = 1;
    for(int i = 0 ; i < n ; i++)
        if( P[i].fi == x and P[i].se == y ) ok = 0;
    
    if( !ok ) ret = 0;
    else{
        if( up == 0 and y > 0 and f( x + 1 , y - 1 , 0 ) ) ret = 1;
        if( up == 1 and y < 2 and f( x + 1 , y + 1 , 1 ) ) ret = 1;
        if( y == 0 and f( x + 1 , 0 , 0 ) ) ret = 1;
        if( y == 0 and f( x + 1 , 1 , 1 ) ) ret = 1;
        if( y == 2 and f( x + 1 , 1 , 0 ) ) ret = 1;
    }
    return ret;
}

int main(){
    while( sc(n) == 1 ){
        P.resize( n );
        for(int i = 0 ; i < n ; i++)
            scanf("%d%d",&P[i].fi,&P[i].se);
        
        me(t,-1);
        if( f( 0 , 0 , 0 ) ) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
