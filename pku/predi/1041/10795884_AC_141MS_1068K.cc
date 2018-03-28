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
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf 2000000000
#define eps 1e-6
#define ll long long
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
#define fi first
#define se second
#define MOD 10009
#define N 2000

bool vis[N];
int con[46][N] , gra[46] , pila[N] , S , top;

void dfs(int u){
    for(int i = 1 ; i <= S ; i++)if( con[u][i] && !vis[ i ] ){
        vis[i] = 1;
        dfs( con[u][i] );
        pila[top++] = i;
    }
}

int main(){
    int x , y , z;
    while( scanf("%d%d",&x,&y) == 2 && (x||y) ){
        sc(z);
        me( con , 0 ); me( gra , 0 ); me( vis , 0 ); me( pila , 0 );
        
        con[x][z] = y , con[y][z] = x;
        gra[x]++ , gra[y]++;
        S = z;
        while( sc(x) , sc(y) ){
            if(x == 0 && y == 0) break;
            gra[x]++ , gra[y]++;
            sc(z);
            con[x][z] = y , con[y][z] = x;
            S = max( S , z );
        }
        bool AC = 1;
        for(int i = 1 ; i < 46 ; i++)
            if( gra[i] & 1 ) AC = 0;

        if( AC ){
            top = 0;
            dfs(1);
            for(int i = top-1 ; i >= 0 ; i--){
                if( i != top-1 ) printf(" ");
                printf("%d",pila[i]);
            }
            printf("\n");
        }
        else
            printf("Round trip does not exist.\n");
    }
}