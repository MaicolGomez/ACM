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
#define N 1005
int pa[N];

int FIND(int x){
    if( x == pa[x] ) return x;
    return pa[ x ] = FIND( pa[x] );
}

void UNION(int x,int y){
    x = FIND(x) , y = FIND(y);
    pa[x] = y;
}

pair< int , pii > A[300005];

int main(){
    int tc;
    sc(tc);
    while(tc--){
        int p , n , m , a , b , c;
        scanf("%d%d%d",&p,&n,&m);
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&a,&b,&c);
            A[i] = mp( c , mp(a,b) );
        }
        sort( A , A + m );
        unsigned int ans = 0;
        for(int i = 0 ; i <= n ; i++) pa[i] = i;
        for(int i = 0 ; i < m ; i++){
            int x = A[i].se.fi , y = A[i].se.se;
            if( FIND(x) != FIND(y) ){
                ans += A[i].fi;
                UNION( x , y );
            }
        }
        cout << ans * p << endl;
    }
    return 0;
}
