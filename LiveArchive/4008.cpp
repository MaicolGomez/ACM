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
#define MOD 10
#define ios ios::sync_with_stdio(0);
#define N 1000005

char s[N];
int a[300] , p[N];

void criba(){
    for(int i = 4 ; i < N - 4 ; i += 2) p[i] = 2;
    for(int i = 3 ; i * i < N - 4 ; i += 2)
        if( !p[i] )
            for(int j = i*i ; j < N - 4 ; j+=i) p[j] = i;
}

int f(int a,int b){
    if( b == 0 ) return 1;
    if( b&1 )
        return (a * f( a , b - 1 )) %MOD;
    
    int t = f( a , b/2 );
    return (t*t)%MOD;
}

int e[N];

void solve(){

    me(e,0);
    int n = strlen(s);
    e[n]++;
    for(int i = 0 ; i < 30 ; i++)if( a[i] > 1 )
        e[a[i]]--;
        
    for(int i = n - 1 ; i >= 2 ; i--) e[i] += e[i+1];
    
    for(int i = n ; i >= 2 ; i--)if( p[i] ){
        e[ i / p[i] ] += e[i];
        e[ p[i] ] += e[i];
        e[i] = 0;
    }
    
    int tmp = min( e[2] , e[5] );
    e[2] -= tmp , e[5] -= tmp;
    int ans = 1;
    for(int i = 2 ; i <= n; i++)if( e[i] > 0 ){
        ans = (ans * f( i%MOD , e[i] ) ) % MOD;
    }
    printf("%d\n",ans);
}

int main(){
    criba();
    while( scanf("%s",s) == 1 ){
        int l = strlen(s);
        me(a,0);
        for(int i = 0 ; i < l ; i++)
            a[ s[i] - 'a' ]++;
        
        solve();
    }
    return 0;
}
