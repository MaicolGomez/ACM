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

int get(int n,int x){
    if(n == 0) return 0;
    return n / x + get( n / x , x );
}

int t[4][4] = 
            {
                6 , 2 , 4 , 8,
                1 , 3 , 9 , 7,
                1 , 7 , 9 , 3,
                1 , 9 , 1 , 9
            };

int g(int n,int x){
    if( n == 0 )
        return 0;
    return n/10 + (n%10 >= x) + g( n/5 , x );
}            

int f(int n,int x){
    if( n == 0 ) return 0;
    return f(n/2 , x) + g(n , x);
}

int main(){
    int n , m;
    while( scanf("%d%d",&n,&m) == 2 ){
        
        int k2 = get( n , 2 ) - get( n - m , 2 );
        int k5 = get( n , 5 ) - get( n - m , 5 );
        int k3 = f( n , 3 ) - f( n - m , 3 );
        int k7 = f( n , 7 ) - f( n - m , 7 );
        int k9 = f( n , 9 ) - f( n - m , 9 );
        
        if( k5 > k2 )
            printf("5\n");
        else{
            int ans = 1;
            if( k2 > k5 ) ans *= t[0][(k2-k5)%4];
            ans *= t[1][k3%4];
            ans *= t[2][k7%4];
            ans *= t[3][k9%4];
            ans %= MOD;
            printf("%d\n",ans);
        }
    }
    return 0;
}
