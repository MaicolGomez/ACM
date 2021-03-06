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

ll d[50] , t[35];
pii A[100];
int r , solve;

void f(ll n){
    if( solve ) return;
    if( n == 0 ){
        printf("%d",r);
        for(int i = 0 ; i < r ; i++)
            printf(" [%d,%d]",A[i].fi,A[i].se);
        solve = 1;
        return;
    }
    ll dif = (1LL<<50);
    pii g;
    for(int i = 0 ; i < 31 ; i++){
        for(int j = 0 ; j < 30 ; j++)
            if( d[i] * t[j] <= n and n - d[i] * t[j] < dif ) dif = n - d[i] * t[j] , g = mp( i , j );
            else break;
    }
    A[r++] = g;
    f( dif );
}

int main(){
    d[0] = 1;
    t[0] = 1;
    for(int i = 1 ; i < 32 ; i++)
        t[i] = t[i-1] * 3 , d[i] = d[i-1] * 2;
    int tc , test = 1;
    sc(tc);
    while(tc--){
        ll n;
        scl(n);
        if( n == 1 ){
            puts("1 1 [0,0]");
            test++;
            continue;
        }
        r = 0 , solve = 0;
        printf("%d ",test++);
        f( n );
        printf("\n");
    }
    return 0;
}
