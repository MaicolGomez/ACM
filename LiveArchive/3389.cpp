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
#define N 501

int t[N];
int a[4] = { 25 , 10 , 5 , 1 };

int f(int n){
    if( n == 0 ) return 0;
    int &ret = t[n];
    if( ret != -1 ) return ret;
    ret = inf;
    for(int i = 0 ; i < 4 ; i++)
        if( n - a[i] >= 0 ) ret = min( ret , 1 + f( n - a[i] ) );
    
    return ret;
}

int c[4];

void rec(int n){
    if( n == 0 ) return;
    int ret = f(n);
    for(int i = 0 ; i < 4 ; i++)if( n - a[i] >= 0 and ret == 1 + f( n - a[i] ) ){
        c[i]++;
        rec( n - a[i] );
        return;
    }
}

int main(){
    int tc , test = 1;
    sc(tc);
    me(t,-1);
    while( tc-- ){
        int n;
        sc(n);
        f( n );
        me(c,0);
        rec( n );
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",test++,c[0],c[1],c[2],c[3]);
    }
    return 0;
}
