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
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 200005

int p[N] , e[N];
bool used[N];

int main(){
    int n , k;
    while( cin >> n >> k ){
        vi g( n );
        for(int i = 0 ; i < n ; i++){
            cin >> p[i] >> e[i];
            g[ i ] = e[ i ];
        }
        ll ans = (1LL<<50)
        if( k == n + 1 ) cout << 0 << "\n";
        else{
            sort( all(g) );
            for(int i = 1 ; i <= 200000 ; i++){
                int rank = n + 1;
                for(int j = 0 ; j < n ; j++)
                    if( p[j] + 1 < i ) rank--;
                
                if( rank <= k ){
                    ll need = 0;
                    for(int j = 0 ; j < i ; j++)
                        need += g[j];
                    
                    ans = min( ans , need );
                }
                else{
                    int more = rank - k;
                    vector< int > v;
                    for(int j = 0 ; j < n ; j++)
                        if( p[j] == i - 1 or p[j] == i ) v.pb( j );
                    
                    int n1 = v.size();
                    if( n1 >= more and more <= i ){
                        sort( all(v) );
                        int need = 0;
                        me(used,0);
                        for(int j = 0 ; j < more ; j++)
                            used[ v[j]. ] = 1 , need += v[j];
                        
                        vi V;
                        for(int j = 0 ; j < n ; j++)if( !used[j] )
                            V.pb( e[j] );
                            
                        sort( all(V) );
                        for(int j = 0 ; j < i - more ; j++)
                            need += V[j];
                        ans = min( ans , need );
                    }
                    
                }
            }
            if( ans < INT_MAX ) printf("%d\n",ans);
            else printf("-1\n");
        }
    }
    return 0;
}
