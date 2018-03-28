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
#define N 1002

int d[N];

int main(){
    int n;
    while( sc(n) == 1 ){
        int r;
        for(int i = 0 ; i < n ; i++)
            d[i] = inf , sc(r);
        
        int m , a , b , c;
        sc(m);
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d",&a,&b,&c); a--,b--;
            d[b] = min( d[b] , c );
        }
        
        int S = 0 , ct = 0;
        for(int i = 0 ; i < n ; i++)
            if( d[i] == inf ) ct++;
            else S += d[i];
        
        if( ct > 1 ) S = -1;
        printf("%d\n",S);
        
    }
    return 0;
}
