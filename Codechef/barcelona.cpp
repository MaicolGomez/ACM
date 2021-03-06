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
#define MOD 1000000007
#define N 1005

int t[N][12];
int k , n;

int f(int x,int p){
    if( x == n - 1 ) return (p!=0);
    int &ret = t[x][p];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = 0 ; i <= k ; i++)if( i != p ){
        ret += f(x + 1 , i);
        if( ret >= MOD ) ret -= MOD;
    }
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while(tc--){
        sc(n),sc(k);
        me(t,-1);
        printf("%d\n",f(0,0)%MOD);
        
    }
    return 0;
}
