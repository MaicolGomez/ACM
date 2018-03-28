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
#define N 100000

int d[N + 5];

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int P , K;
        scanf("%d%d",&P,&K);
        me(d,-1);
        d[P] = 0;
        queue<int> Q;
        Q.push( P );
        while( !Q.empty() ){
            int q = Q.front(); Q.pop();
            if( q * 2 < N and d[ q * 2 ] == -1 ){
                d[ q * 2 ] = d[ q ] + 1;
                Q.push( q * 2 );
            }
            if( q % 2 == 0 and d[q / 2] == -1 ){
                d[ q / 2 ] = d[ q ] + 1;
                Q.push( q / 2 );
            }
            if( q + 1 < N and d[ q + 1 ] == -1 ){
                d[ q + 1 ] = d[ q ] + 1;
                Q.push( q + 1 );
            }
        }
        printf("%d\n",d[K]);
    }
    return 0;
}
