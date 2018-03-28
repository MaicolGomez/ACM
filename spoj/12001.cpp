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
#define N 1000005

int t[N];

int f(int n){
    if( n == 0 or __builtin_popcount( n ) == 1 ) return 0;
    int &ret = t[n];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = 0 ; i < 20 ; i++){
        int j = i + 1;
        if( n&(1<<i) ){
            ret |= !f( n^(1<<i) );
            if( n&(1<<j) ) ret |= !f( n^(1<<i)^(1<<j) );
        }
    }
    return ret;
}

int main(){
    int tc;
    sc(tc);
    me(t,-1);
    /*t[0] = 0;
    for(int n = 1 ; n <= 1000000 ; n++){
        if( __builtin_popcount( n ) == 1 ) t[n] = 0;
        else{
            t[n] = 0;
            for(int i = 0 ; i < 20 ; i++){
                int j = i + 1;
                if( n&(1<<i) ){
                    t[n] |= !t[ n^(1<<i) ];
                    if( n&(1<<j) ) t[n] |= !t[ n^(1<<i)^(1<<j) ];
                }
            }
        }
    }
    */
    while( tc-- ){
        int n;
        sc(n);
        if( f( n ) ) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
