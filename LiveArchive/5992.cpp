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
#define N 505

char mat[N][N];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
 
int main(){
    int tc , R , C;
    cin >> tc;
    while( tc-- ){
        cin >> R >> C;
        vector< pii > v[30];
        vector<pii> nvec[30];
        for(int i = 0 ; i < R ; i++)
            for(int j = 0 ; j < C ; j++){
                cin >> mat[i][j];
                if( mat[i][j] >= 'a' && mat[i][j] <= 'z' ) v[ mat[i][j] - 'a' ].pb( mp( i , j ) );
            }
        
        while( 1 ){
            for(int i = 0 ; i < 30 ; i++){
                for(int j = 0 ; j < v[i].size() ; j++){
                    int x = v[i][j].fi , y = v[i][j].se;
                    if( mat[x][y] == '*' ) continue;
                    for(int k = 0 ; k < 4 ; k++){
                        int nx = x + dx[k] , ny = y + dy[k];
                        if( nx >= 0 && nx < R && ny >= 0 && ny < C ){
                            if( mat[nx][ny] == '#' ) continue;
                            char c = toupper(mat[x][y]);
                            if( isupper(mat[nx][ny]) && mat[nx][ny] != c ) mat[nx][ny] = '*';
                            if( mat[nx][ny] != '.' ) continue;
                            mat[nx][ny] = c;
                            nvec[ c - 'A' ].pb( mp(nx,ny) );
                        }
                    }
                }
            }
            for(int i = 0 ; i < 30 ; i++){
                for(int j = 0 ; j < nvec[i].size() ; j++){
                    int x = nvec[i][j].fi , y = nvec[i][j].se;
                    if( mat[x][y] == '*' ) continue;
                    mat[x][y] = tolower(mat[x][y]);
                }
            }
            bool change = 0;
            for(int i = 0 ; i < 30 ; i++){
                v[i] = nvec[i];
                if( v[i].size() != 0 ) change = 1;
                nvec[i].clear();
            }
            if( change == 0 ) break;
            
        }
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++)
                cout << mat[i][j];
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
