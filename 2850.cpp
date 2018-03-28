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
#define MOD 100000000
#define ios ios::sync_with_stdio(0)
#define N 12

int R , C , m[N][N] , t[1<<N][N][N];


int f(int mask,int r,int c){
    if( c == C ) c = 0 , r++;
    if( r == R ) return 0;
    int &ret = t[mask][r][c];
    if( ret != -1 ) return ret;
    ret = 0;
    ret = f( (mask&(1<<c) > 0)?(mask^(1<<c)):(mask) , r , c + 1 );
    if( ret >= MOD ) ret -= MOD;
    if( m[r][c] )
        if( !(mask&(1<<c)) ) ret = 1 + f( mask^(1<<c) , r , c + 1 );
    if( ret >= MOD ) ret -= MOD;
    return ret;
}

int main(){
    while( ~scanf("%d%d",&R,&C) ){
        me(m,0);
        for(int i = 0 ; i < R ; i++)
            for(int j = 0 ; j < C ; j++)
                sc(m[i][j]);
        me(t,-1);
        printf("%d\n",f(0,0,0));
    }
    return 0;
}
