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
#define N 105

int h[N] , d[N];
int t[N][N][N];


int f(int a,int b,int c){
    if( a == d[0] and b == d[1] and c == d[2] ) return 0;
    if( a > d[0] and b > d[1] and c > d[2] ) return inf;
    int &ret = t[a][b][c];
    if( ret != -1 ) return ret;
    ret = inf;
    if( a > 0 and b < 100 and c < 100 ) ret = min( ret , 1 + f( a - 1 , b + 1 , c + 1 ) );
    if( b > 0 and a < 100 and c < 100 ) ret = min( ret , 1 + f( a + 1 , b - 1 , c + 1 ) );
    if( c > 0 and a < 100 and b < 100 ) ret = min( ret , 1 + f( a + 1 , b + 1 , c - 1 ) );
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n;
        sc(n);
        for(int i = 0 ; i < n ; i++)
            sc(h[i]);
        for(int i = 0 ; i < n ; i++)
            sc(d[i]);
        
        if( n == 1 ){
            if( h[0] == d[0] ) printf("0\n");
            else printf("-1\n");
        }
        else if( n == 2 ){
            if( h[0] == d[0] and h[1] == d[1] ) printf("0\n");
            else if( d[0] > h[0] and h[1] - d[1] == d[0] - h[0] ) printf("%d\n",d[0] - h[0]);
            else if( d[1] > h[1] and h[0] - d[0] == d[1] - h[1] ) printf("%d\n",d[1] - h[1]);
            else printf("%d\n",-1);
        }
        else if( n == 3 ){
            me(t,-1);
            int ans = f( h[0] , h[1] , h[2] );
            if( ans == inf ) ans = -1;
            printf("%d\n",ans);
        }
        else{
            bool ok = 1;
            vi up , down;
            for(int i = 0 ; i < n ; i++){
                if( h[i] - d[i] != 0 ) ok = 0;
                if( d[i] > h[i] ) up.pb( d[i] - h[i] );
                else down.pb( h[i] - d[i] );
            }
            if( ok ) printf("0\n");
            else{
                sort( all(up) );
                sort( all(down) );
                if( down.size() != 1 ) printf("-1\n");
                else{
                    if( up[0] == up[ down.size() - 1 ] and down[0] == up[0] ) printf("%d\n",up[0]);
                    else printf("-1\n");
                }
            }
        }
    }
    return 0;
}
