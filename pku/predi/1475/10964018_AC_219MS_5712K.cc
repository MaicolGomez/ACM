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
#define fi first
#define se second
#define MOD 10009
#define N 21

struct nodo{
    int x , y , u , v , d;
    char e;
    nodo(){}
    nodo(int X,int Y,int U,int V,int D){
        x = X , y = Y , u = U , v = V , d = D;
    }
};

bool operator<( nodo A,nodo B ){
    return A.d > B.d;
}
bool operator==(nodo A,nodo B){
    return A.x == B.x && A.y == B.y && A.u == B.u && A.v == B.v;
}

int d[N][N][N][N] , R , C , t1 , t2;
int dx[4] = { -1 , 0 , 1 , 0 };
int dy[4] = { 0 , -1 , 0 , 1 };
nodo fa[N][N][N][N];
string A = "NWSE";
string B = "nwse";
char s[N][N];

string dijkstra( nodo ss ){
    for(int i = 0 ; i < R ; i++)
        for(int j = 0 ; j < C ; j++)
            for(int k = 0 ; k < R ; k++)
                for(int r = 0 ; r < C ; r++)
                    d[i][j][k][r] = inf;
    
    d[ss.x][ss.y][ss.u][ss.v] = 0;
    priority_queue<nodo> Q;
    Q.push( ss );
    nodo sol = ss;
    bool ans = 0;
    while( !Q.empty() ){
        nodo q = Q.top(); Q.pop();
        int x = q.x , y = q.y , u = q.u , v = q.v;
        int nd = q.d + 1;
        for(int i = 0 ; i < 4 ; i++){
            int a = x + dx[i] , b = y + dy[i];
            if( a >= 0 && a < R && b >= 0 && b < C && s[a][b] != '#' ){
                if( a != u || b != v ){
                    if( nd < d[a][b][u][v]  ){
                        d[a][b][u][v] = nd;
                        Q.push( nodo( a , b , u , v , nd ) );
                        nodo k = q;
                        k.e = B[i];
                        fa[a][b][u][v] = k;
                    }
                }
                else if( a == u && b == v ){
                    int p = x + 2 * dx[i] , t = y + 2 * dy[i];
                    if( p >= 0 && p < R && t >= 0 && t < C && s[p][t] != '#' ){
                        int dd = nd + 500;
                        if( dd < d[a][b][p][t] ){
                            d[a][b][p][t] = dd;
                            Q.push( nodo( a , b , p , t , dd ) );
                            nodo k = q;
                            k.e = A[i];
                            fa[a][b][p][t] = k;
                            if( p == t1 && t == t2 ){ sol = k; ans = 1; goto gg; }
                        }
                    }
                }
            }
        }
    }
    gg:
    if( ans == 0 ) return "Impossible.";
    string res = "";
    while( 1 ){
        res += sol.e;
        if( sol == ss ) break;
        sol = fa[sol.x][sol.y][sol.u][sol.v];
    }
    reverse( all(res) );
    return res;
}

int main(){
    int test = 0;
    while( scanf("%d%d",&R,&C) == 2 , R , C ){
        int x1 = -1 , x2 = -1 , y1 = -1 , y2 = -1;
        for(int i = 0 ; i < R ; i++){
            scanf("%s",s[i]);
            for(int j = 0 ; j < C ; j++){
                if( s[i][j] == 'T' ) t1 = i , t2 = j;
                else if( s[i][j] == 'S' ) x1 = i , y1 = j;
                else if( s[i][j] == 'B' ) x2 = i , y2 = j;
            }
        }
        printf("Maze #%d\n",++test);
        string r = dijkstra( nodo( x1 , y1 , x2 , y2 , 0) );
        printf("%s\n",r.c_str());
        printf("\n");
    }
    return 0;
}