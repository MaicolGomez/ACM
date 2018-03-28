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
#define N 100000

map< int , vi > A;
map< int , vi > :: iterator it;

int main(){
    int n , tc;
    sc(tc);
    while(tc--){
        sc(n);
        A.clear();

        int x , y;
        for(int i = 0 ; i < n ; i++){
            sc(x),sc(y);
            A[x].pb(y);
        }
        vector< vector<int> > B;
        for( it = A.begin() ; it != A.end() ; it++){
            B.pb( it->second );
            sort( all(B[ B.size() - 1 ]) );
        }
        
        vi a , b;
        for(int i = 0 ; i < B.size() ; i++)
            for(int j = 0 ; j < B[i].size() ; j++){
                if(j) b.pb( B[i][j] );
                else a.pb( B[i][j] );
            }
        
        sort(all(a));
        sort(all(b));
        x = 0;
        ll ans = 0;
        for(int i = 0 ; i < a.size() ; i++)
            ans += 1LL * a[i] * ++x;
            
        for(int i = 0 ; i < b.size() ; i++)
            ans += 1LL * b[i] * x;
        
        printf("%lld\n",ans);
    }
    return 0;
}
