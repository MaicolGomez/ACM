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
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 101

int n , a[N] , S , L;
bool solve;

void f(int pos,int mask,int l , int r){
    if( solve ) return;
    if( r == 3 ){
        solve = 1;
        return;
    }
    
    for(int i = pos ; i < n ; i++)if( mask&(1<<i) )
        if( l + a[i] <= L ){
            if( l + a[i] == L ) f( 0 , mask^(1<<i) , 0 , r + 1 );
            else f( i + 1 , mask^(1<<i) , l+a[i] , r );
        } 
    
}

int main(){
    int tc;
    sc(tc);
    while(tc--){
        sc(n);
        S = 0;
        for(int i = 0 ; i < n ; i++)
            sc(a[i]) , S += a[i];
        
        
        if( S%4 != 0 ) printf("no\n");
        else{
            solve = 0;
            L = S/4;
            sort( a , a + n );  
            if( a[n-1] <= L ) f( 0 , (1<<n) - 1 , 0 , 0 );
            if( solve ) printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}
