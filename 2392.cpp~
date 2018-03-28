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
#define N 10

pii A[N];
bool ans;
int n;

void solve(int mask,int l1 = -1 , int l2 = -1 , int l3 = -1,int x = 0 ,int y = 0 , int z = 0){
    if(ans) return;
    if( mask == 0 ){
        if( x == y and x == z and x == 2 ){
            //cout << l1 << " -- " << l2 << " -- " << l3 << "\n";
            ans = 1;
        }
        return;
    }
    if( l1 == -1 ){
        for(int i = 0 ; i < n ; i++)if( mask&(1<<i) ){
            solve( mask^(1<<i) , A[i].fi , A[i].se , l3 , 1 , 0 , 0 );
            solve( mask^(1<<i) , A[i].se , A[i].fi , l3 , 1 , 0 , 0 );
        }
    }
    if( l3 == -1 ){
        for(int i = 0 ; i < n ; i++)if( mask&(1<<i) ){
            if( A[i].fi == l1 ) solve( mask^(1<<i) , l1 , l2 , A[i].se , x , y , z + 1 );
            if( A[i].se == l1 ) solve( mask^(1<<i) , l1 , l2 , A[i].fi , x , y , z + 1 );
            if( A[i].fi == l2 ) solve( mask^(1<<i) , l1 , l2 , A[i].se , x , y + 1 , z );
            if( A[i].se == l2 ) solve( mask^(1<<i) , l1 , l2 , A[i].fi , x , y + 1 , z );
        }
    }
    
    for(int i = 0 ; i < n ; i++)if( mask&(1<<i) ){
        if( A[i].fi == l1 and A[i].se == l2 ) solve( mask^(1<<i) , l1 , l2 , l3 , x + 1 , y , z );
        if( A[i].fi == l2 and A[i].se == l1 ) solve( mask^(1<<i) , l1 , l2 , l3 , x + 1 , y , z );
        if( A[i].fi == l1 and A[i].se == l3 ) solve( mask^(1<<i) , l1 , l2 , l3 , x , y , z + 1 );
        if( A[i].fi == l3 and A[i].se == l1 ) solve( mask^(1<<i) , l1 , l2 , l3 , x , y , z + 1 );
        if( A[i].fi == l2 and A[i].se == l3 ) solve( mask^(1<<i) , l1 , l2 , l3 , x , y + 1 , z );
        if( A[i].fi == l3 and A[i].se == l2 ) solve( mask^(1<<i) , l1 , l2 , l3 , x , y + 1 , z );
    }
    
    
}

int main(){
    n = 6;
    ans = 0;
    for(int i = 0 ; i < n ; i++)
        scanf("%d%d",&A[i].fi,&A[i].se);
    
    solve( 63 );
    if( ans ) printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");
    return 0;
}
