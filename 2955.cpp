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
#define N 1005

int X[N] , Y[N];

int main(){
    pii P[5];
    for(int i = 0 ; i < 3 ; i++){
        scanf("%d%d",&P[i].fi,&P[i].se);
        X[P[i].fi]++;
        Y[P[i].se]++;
    }
    int x = -1 , y = -1;
    for(int i = 0 ; i < 3 ; i++){
        if( X[P[i].fi] == 1 ) x = P[i].fi;
        if( Y[P[i].se] == 1 ) y = P[i].se;
    }
    printf("%d %d\n",x,y);
    return 0;
}
