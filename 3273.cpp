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
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 1005

int t[N][N];

int f(int n,int k){
    if( n == 0 )
        return (k == 0);
    
    int &ret = t[n][k];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = 0 ; i <= k and k >= i * n ; i++)
        ret = ( ret + f( n - 1 , k - n * i ) )%MOD;
    
    return ret;
}

int main(){
    int tc;
    sc(tc);
    me(t,-1);
    while( tc-- ){
        int n , k;
        scanf("%d%d",&k,&n);
        k -= n;
        if( k < 0 )
            printf("%d\n",0);
        else printf("%d\n",f( n , k ));
    }
    return 0;
}
