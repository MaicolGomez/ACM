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
#define MOD 10009
#define N 55

int m[N][N] , r , c;
int dx[8] = { -1 , -1 , -1 , 0 , 0 , 1 , 1 , 1 };
int dy[8] = { 1 , 0 , -1 , 1 , -1 , 1 , 0 , -1 };

int f(int x,int y){
    int g = m[x][y];
    for(int i = 0 ; i < 8 ; i++){
        int u = x + dx[i] , v = y + dy[i];
        if( u >= 0 && u < r && v >= 0 && v < c )
            if( m[u][v] == g ) return g;
    }
    return -1;
}

int main(){
    while( scanf("%d%d",&r,&c) == 2 ){
        for(int i = 0 ; i < r ; i++)
            for(int j = 0 ; j < c ; j++)
                sc(m[i][j]);
        
        int ans = 0;
        for(int i = 0 ; i < r ; i++)
            for(int j = 0 ; j < c ; j++)
                ans = max( ans , f(i,j) );
        printf("%d\n",ans);
    }
    return 0;
}
