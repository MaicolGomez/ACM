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
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 100001

int C[N];
set<int> S[10 * N];

int main(){
    int n , f;
    ll a , b , c;
    scanf("%d%d",&n,&f);
    scanf("%lld%lld%lld",&a,&b,&c);
    C[0] = a;
    for(int i = 1 ; i < n ; i++)
        C[i] = ( b * C[i-1] + c ) % f;
    
    for(int i = 0 ; i < n ; i++)
        S[ C[i] ].insert( i );
    
    int q , i , e , l , r;
    sc(q);
    set<int> :: iterator up , lo;
    while( q-- ){
        scanf("%d%d",&i,&e); i--; // house i , team e
        
        S[ C[i] ].erase( i );
        
        if( S[e].size() == 0 ) printf("%d %d\n",n,n);
        else{
            up = S[ e ].upper_bound( i );
            if( up != S[e].end() ) r = *up - i;
            else{
                up = S[e].begin();
                r = n + *up - i;
            }
            lo = S[ e ].upper_bound( i );
            if( lo != S[e].begin() ){
                lo--;
                l = i - *lo;
            }
            else{
                lo = S[e].end();
                lo--;
                l = n - *lo + i;
            }
            printf("%d %d\n",l,r);
        }
               
        C[i] = e;
        S[ e ].insert( i );
    }
    
    return 0;
}
