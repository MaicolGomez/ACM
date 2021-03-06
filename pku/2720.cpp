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
#define MOD 10
#define ios ios::sync_with_stdio(0);
#define N 20000501


int main(){
    int n , m;
    while( scanf("%d%d",&n,&m) == 2 ){
        int ans = 1 , a = 0 , b = 0;
        for(int i = n ; i > n - m ; i--){
            int r = i;
            while( r%2 == 0 ) a++ , r /= 2;
            while( r%5 == 0 ) b++ , r/= 5;
            ans = (ans * r)%MOD;
        }
        int c = min(a,b);
        a -= c , b -= c;
        for(int i = 0 ; i < a ; i++)
            ans = (ans * 2)%MOD;
        for(int i = 0 ; i < b ; i++)
            ans = (ans * 5)%MOD;
        
        printf("%d\n",ans);
    }
    return 0;
}
