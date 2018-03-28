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
#define N 102

int R , C , t[N][N][3];
char s[N][N];
int dx[8] = { 1 , -1 , 0 , 0 };
int dy[8] = { 0 , 0 , 1 , -1 };

int f(int x,int y,int z){
    if( x == R - 1 && y == C - 1 )
        return 0;
    int &ret = t[x][y][z];
    if( ret != -1 ) return ret;
    int ss = 0;
    int l = 0 , r = 4;
    if( z == 1 ) l = 0 , r = 3;
    else if( z == 2 ) l = 2 , r = 5;
    for(int i = l ; i < r ; i++){
        int u = x + dx[i] , v = y + dy[i];
        if( u >= 0 && u < R && v >= 0 && v < C )
            ss += s[u][v] == '1';
    }

    ret = inf;
    if( x + 1 < R ) ret = min( ret , f( x + 1 , y , 2 ) );
    if( y + 1 < C ) ret = min( ret , f( x , y + 1 , 1 ) );
    ret += ss;
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while(tc--){
        sc(R),sc(C);
        for(int i = 0 ; i < R ; i++)
            scanf("%s",s[i]);
        
        me(t,-1);
        printf("%d\n",(s[0][0]=='1') + f(0,0,0));
    }
    return 0;
}
