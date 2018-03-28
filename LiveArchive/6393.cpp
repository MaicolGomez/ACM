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
#define N 61

int h(char *s,int a){
    if( s[a] == '0' ) return 55;
    return (s[a] - 'A') * 2  + (s[a+1] == '+');
}

bool c[N][N];


int main(){
    int n;
    while( sc(n) == 1){
        char s[10];
        for(int i = 0 ; i < n ; i++){
            scanf("%s",s);
            for(int j = 0 ; j < 4 ; j++)
                for(int k = 0 ; k < 4 ; k++)if( j != k )
                    c[ h( s , 2 * j ) ][ h( s , 2 * k ) ^ 1 ] = 1;
        }
        bool vis[60];
        bool cycle = 0;
        for(int i = 0 ; i < 52 ; i++){
            me(vis,0);
            queue<int> Q;
            Q.push( i );
            while( !Q.empty() ){
                int q = Q.front(); Q.pop();
                vis[q] = 1;
                for(int j = 0 ; j < 52 ; j++) if( c[q][j] and !vis[j] )
                    Q.push( j );
            }
            for(int j = 0 ; j < 52 ; j++)
                if( c[j][i] and vis[j] ) cycle = 1;
        }
        if( !cycle ) printf("bounded\n");
        else printf("unbounded\n");
    }
    return 0;
}
