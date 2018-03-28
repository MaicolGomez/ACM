#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<queue>
using namespace std;
#define inf (1<<29)
#define ll long long
#define eps 1e-8
#define vi vector<int>
#define all(v) v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define L(x) ((x<<1)+ 1)
#define M(x,y) ((x+y)>>1)
#define Q(x) (x) * (x)
#define N 101

char s[N][N];
char word[N][N];
int m[N][N] , F[N*N];
int L[N] , C , r , c;
bool vis[N][N];
int dx[8] = { -1 , 1 , 0 , 0 , -1 , 1 , 1 , -1 };
int dy[8] = { 0 , 0 , 1 , -1 , -1 , -1 , 1 , 1 };
pair< pii , pii > A[N];

int FIND(int x){
    return (F[x] == x)?x:(F[x] = FIND( F[x] ));
}

void UNION(int x,int y){
    F[ FIND(x) ] = FIND(y);
}

int main(){
    int n;
    while( scanf("%d%d%d",&r,&c,&n) == 3 and (r||c) ){
        for(int i = 0 ; i < r ; i++){
            scanf("%s",s[i]);
            for(int j = 0 ; j < c ; j++)
                if( s[i][j] > 'Z'  ) s[i][j] -= 32;
        }
        for(int i = 0 ; i < n ; i++){
            scanf("%s",word[i]);
            L[i] = strlen(word[i]);
            for(int j = 0 ; j < L[i] ; j++)
                if( word[i][j] > 'Z' ) word[i][j] -= 32;
        }
        vector<bool> used( n , 0 );
        me(m,0);
        C = 0;
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                for(int k = 0 ; k < 8 ; k++){

                    for(int cur = 0 ; cur < n ; cur++)if( !used[cur] ){ //cuatro direcciones
                        
                        int x = i , y = j , len = 0;
                        while( 0 <= x and x < r and 0 <= y and y < c and len < L[cur] ){
                            if( word[cur][len] != s[x][y] ) break;
                            x += dx[k] , y += dy[k];
                            len++;
                        }
                        if( len == L[cur] ){
                            int u = i , v = j , tam = 0;
                            while( tam < L[cur] ){
                                m[u][v]++;
                                u += dx[k] , v += dy[k];
                                tam++;
                            }
                            A[C++] = mp( mp( i , j ) , mp( k , cur ) );
                        }
                    }
                }
            }
        }
        
        bool ok = 1;
        for(int i = 0 ; i < C ; i++){
            
            int x = A[i].fi.fi , y = A[i].fi.se , k = A[i].se.fi , id = A[i].se.se , len = 0;
            while( len < L[id] ){
                m[x][y]--;
                x += dx[k] , y += dy[k];
                len++;
            }
            
            for(int j = 0 ; j < r * c ; j++) F[j] = j;
            
            for(int j = 0 ; j < C ; j++)if( i != j ){
                x = A[j].fi.fi , y = A[j].fi.se , k = A[j].se.fi , id = A[j].se.se , len = 1;
                while( len < L[id] ){
                    int nx = x + dx[k] , ny = y + dy[k];
                    if( FIND( x * c + y ) != FIND( nx * c + ny ) ){
                        UNION( x * c + y , nx * c + ny );
                    }
                    len++;
                    x = nx , y = ny;
                }
            }
            
            int comp = 0;
            for(int a = 0 ; a < r ; a++)
                for(int b = 0 ; b < c ; b++)if( m[a][b] )
                    if( F[a*c + b] == a * c + b ) comp++;
                
            
            if( comp > 1 ){
                ok = 0;
                break;
            }
            
            x = A[i].fi.fi , y = A[i].fi.se , k = A[i].se.fi , id = A[i].se.se , len = 0;
            while( len < L[id] ){
                m[x][y]++;
                x += dx[k] , y += dy[k];
                len++;
            }
        }
        
        string ans = "Yes";
        if( !ok ) ans = "No";
        printf("%s\n",ans.c_str());
    }
}
