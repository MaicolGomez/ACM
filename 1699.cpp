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

int main(){
    int tc , test = 1;
    sc(tc);
    while( tc-- ){
        printf("Scenario #%d:\n",test++);
        int a , b , l = 0 , r = 0;
        scanf("%d%d",&a,&b);
        while( a != 1 and b != 1 ){
            if( a / b < 1 ){
                r += b/a;
                b %= a;
            }
            else{
                l += a/b;
                a %= b;
            }
        }
        if( a == 1 ) r += b - 1;
        else l += a - 1;
        
        printf("%d %d\n\n",l,r);
    }
    return 0;
}
