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
#define fi first
#define se second
#define MOD 10009
#define N 15000

int fa[N+5];
int d[N+5];

int FIND(int x){
    if( fa[x] == x ) return x;
    int Px = FIND( fa[x] );
    d[ x ] ^= d[ fa[x] ];
    return fa[x] = Px;
}

void UNION(int x,int y,int c){
    int Px = FIND(x);
    fa[ Px ] = FIND(y);
    d[ Px ] = d[x] ^ d[y] ^ c;
}

int main(){
    int n;
    while( sc(n) == 1 ){
        if( n == -1 ) break;
        int q , x , y;
        sc(q);
        char s[10];
        map<int,int> M;
        int C = 0 , timer = 0;
        bool ok = 1;
        while( q-- ){
            scanf("%d %d %s",&x,&y,s);
            if(!ok) continue;
            if( x <= 0 || x > n || y <= 0 || y > n || x > y ){
                ok = 0;
                continue;
            }
            x--;
            if( M.find(x) == M.end() ){
                M[x] = C;
                fa[C] = C;
                d[C] = 0;
                C++;
            }
            if( M.find(y) == M.end() ){
                M[y] = C;
                fa[C] = C;
                d[C] = 0;
                C++;
            }
            x = M[x] , y = M[y];
            int di = (s[0]=='o')?1:0;
            if( FIND(x) == FIND(y) ){
                int distance = (d[x] ^ d[y]);
                if( (distance ^ di) == 1 )
                    ok = 0;
            }
            else UNION( x , y , di );
            if(ok) timer++;
        }
        printf("%d\n",timer);

    }
    return 0;
}

