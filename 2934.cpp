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
#define N 100001

pair< pii , int > P[N];

int main(){
    int n , k;
    scanf("%d%d",&n,&k);
    for(int i = 0 ; i < n ; i++)
        scanf("%d%d",&P[i].fi.fi,&P[i].fi.se) , P[i].se = i;
    
    sort( P , P + n );
    reverse( P , P + n );
    int id = k - 1;
    for(int i = 0 ; i < k ; i++)
        if( P[i].fi.se > P[id].fi.se ) id = i;
    printf("%d\n",P[id].se + 1);
    return 0;
}
