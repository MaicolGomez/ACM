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
#define N 205

int pa[N];

int FIND(int x){
    if( x != pa[x] ) return pa[x] = FIND(pa[x]);
    return x;
}

void UNION(int x,int y){ pa[ FIND(x) ] = FIND(y); }

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n , m;
        scanf("%d%d",&n,&m);
        vector< pair< int , pii > > v(m);
        for(int i = 0 ; i < m ; i++)
            scanf("%d%d%d",&v[i].se.fi,&v[i].se.se,&v[i].fi);
        
        sort(all(v));
        for(int i = 0 ; i < 201 ; i++)
            pa[i] = i;
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            int x = v[i].se.fi , y = v[i].se.se;
            if( FIND(x) != FIND(y) ){
                ans += v[i].fi;
                UNION(x , y);
            }
        }
        int cmp = 0;
        for(int i = 1 ; i <= n ; i++)
            if( i == pa[i] ) cmp++;
        if(cmp == 1)printf("%d\n",(ans+9)/10); // need binary search
        else printf("-1\n");
    }
    return 0;
}
