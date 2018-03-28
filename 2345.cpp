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
#define MOD 10009
#define N 10

int n , C1 , C2 , w[N] , want , t[1<<N] , A[N] , C[1<<N];

bool can(int mask){
    
    bool c[101];
    for(int i = 0 ; i <= C1 ; i++) c[i] = 0;
    
    c[0] = 1;
    int S = 0;
    for(int i = 0 ; i < n ; i++)if( mask&(1<<i) ){
        S += w[i];
        for(int j = C1 - w[i] ; j >= 0 ; j--)
            if( c[j] ) c[ j+w[i] ] = 1;
    }
    for(int i = 0 ; i <= C1 ; i++)
        if( c[i] && S - i <= C2 ) return 1;
    
    return 0;
}

void solve(){
    sc(n), sc(C1) , sc(C2);
    for(int i = 0 ; i < n ; i++)
        sc(w[i]);
    
    int r = 0;
    for(int i = 1 ; i < (1<<n) ; i++)
        if( can(i) ) C[r++] = i;
    
    fill_n( t ,  (1<<n) , inf );
    
    t[0] = 0;
    
    for(int i = 0 ; i < r ; i++){
        for(int j = (1<<n) - 1 ; j >= 0 ; j--){
            if( t[j] == inf ) continue;
            int x = j + C[i];
            if( x != (j|C[i]) ) continue;
            t[x] = min( t[x] , 1 + t[j] );
        }
    }
    
    printf("%d\n\n", t[(1<<n)-1] );
}

int main(){
    int tc;
    sc(tc);
    for(int i = 1 ; i <= tc ; i++){
        printf("Scenario #%d:\n",i);
        solve();
    }    
    return 0;
}
