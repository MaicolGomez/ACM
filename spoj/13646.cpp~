#include<bits/stdc++.h>
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
#define N 32

int n , T , a[N][N];

struct nodo{
    int x , y , mm , tm;
    nodo(int X,int Y,int MM,int TM){
        x = X , y = Y , mm = MM , tm = TM;
    }
};

bool operator <(nodo p1,nodo p2){
    if (p1.mm<p2.mm)
        return 0;
    else if (p1.mm>p2.mm)
        return 1;
    else if (p1.tm>p2.tm)
        return 0;
    else return 1;
}


int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , 1 , -1 };
bool vis[N][N];
int A[N][N] , B[N][N];

void dijkstra(){
    priority_queue<nodo> Q;
    Q.push( nodo( 0 , 0 , a[0][0] , T - a[0][0] ) );
    me(vis,0);
    while( !Q.empty() ){
        nodo q = Q.top(); Q.pop();
        if( q.x == n - 1 and q.y == n - 1 ){
            printf("YES : %d %d\n", q.mm , q.tm );
            return;
        }
        if( q.tm < 0 ) continue;
        if( vis[q.x][q.y] ){
            if( q.mm > A[q.x][q.y] ) continue;
            if( q.mm == A[q.x][q.y] and q.tm >= B[q.x][q.y] ) continue;
        }
        vis[q.x][q.y] = 1;
        A[q.x][q.y] = q.mm;
        B[q.x][q.y] = q.tm;
        for(int i = 0 ; i < 4 ; i++){
            int nx = q.x + dx[i] , ny = q.y + dy[i];
            if( nx >= 0 and nx < n and ny >= 0 and ny < n )
                Q.push( nodo( nx , ny , max( q.mm , a[q.x][q.y] - a[nx][ny] ) , q.tm - abs( a[q.x][q.y] - a[nx][ny] ) ) );
        }
    }
    printf("NO\n");
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        scanf("%d%d",&n,&T);
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                sc(a[i][j]);
        
        dijkstra();
    }
    return 0;
}
