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
#define N 11

bool m[N][N];
char a[N][N];
int dx[8] = { 1 , -1 , 0 , 0 , 1 , -1 , -1 , 1 };
int dy[8] = { 0 , 0 , 1 , -1 , -1 , 1 , -1 , 1 };
int dCx[8] = { -2 , -1 , 1 , 2 , 2 , 1 , -1 , -2 };
int dCy[8] = { -1 , -2 , -2 , -1 , 1 , 2 , 2 , 1 };

void f(int row,string s){
    int c = 1;
    for(int i = 0 ; i < s.size() ; i++){
        if( s[i] >= '1' and s[i] <= '9' )
            c += (s[i] - '0');
        else{
            if( s[i] != 'p' and s[i] != 'P' ) a[row][c] = tolower( s[i] );
            else a[row][c] = s[i];
            c++;
        }
    }
}

int main(){
    map<char , int> step;
    step['k'] = 1;
    step['q'] = 20;
    step['r'] = 20;
    step['n'] = 1;
    step['b'] = 20;
    step['P'] = 1;
    step['p'] = 1;
    string t;
    while( cin >> t ){
        me( m , 0 );
        for(int i = 0 ; i < 9 ; i++)
            for(int j = 0 ; j < 9 ; j++)
                a[i][j] = '#';
                
        for(int i = 0 ; i < t.size() ; i++)
            if( t[i] == '/' ) t[i] = ' ';
        stringstream in(t);
        string x;
        int r = 1;
        while( in >> x ){
            f( r , x );
            r++;
        }
        /*for(int i = 1 ; i < 9 ; i++){
            for(int j = 1 ; j < 9 ; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }*/
        for(int i = 1 ; i <= 8 ; i++)
            for(int j = 1 ; j <= 8 ;j++)if( a[i][j] != '#' ){
                m[i][j] = 1;
                int x = step[ a[i][j] ];
                if( a[i][j] == 'k' ){
                    for(int k = 0 ; k < 8 ; k++)
                        m[i + dx[k]][j + dy[k]] = 1;
                }
                if( a[i][j] == 'q' ){
                    //cout << i << " " << j << endl;
                    for(int k = 0 ; k < 8 ; k++)
                        for(int s = 1 ; s <= x ; s++){
                            int u = i + s * dx[k] , v = j + s * dy[k];
                            //cout << u << " - " << v << endl;
                            if( u >= 1 and u < 9 and v >= 1 and v < 9 ){
                                if( a[u][v] != '#' ) break;
                                //cout << a[i][j] << " " << u << " --- " << v << endl;
                                m[u][v] = 1;
                            }
                        }
                }
                if( a[i][j] == 'n' )
                    for(int k = 0 ; k < 8 ; k++){
                        int u = i + dCx[k] , v = j + dCy[k];
                            if( u >= 1 and u < 9 and v >= 1 and v < 9 )
                                m[u][v] = 1;
                    }
                if( a[i][j] == 'r' ){
                    for(int k = 0 ; k < 4 ; k++)
                        for(int s = 1 ; s <= x ; s++){
                            int u = i + s * dx[k] , v = j + s * dy[k];
                            if( u >= 1 and u < 9 and v >= 1 and v < 9 ){
                                if( a[u][v] != '#' ) break;
                                m[u][v] = 1;
                            }
                        }
                }
                if( a[i][j] == 'b' ){
                    for(int k = 4 ; k < 8 ; k++)
                        for(int s = 1 ; s <= x ; s++){
                            int u = i + s * dx[k] , v = j + s * dy[k];
                            if( u >= 1 and u < 9 and v >= 1 and v < 9 ){
                                if( a[u][v] != '#' ) break;
                                m[u][v] = 1;
                            }
                        }
                }
                if( a[i][j] == 'p' ) m[i+1][j+1] = m[i+1][j-1] = 1;
                if( a[i][j] == 'P' ) m[i-1][j+1] = m[i-1][j-1] = 1;
            }
        int ans = 0;
        for(int i = 1 ; i <= 8 ; i++)
            for(int j = 1 ; j <= 8 ; j++)
                ans += (m[i][j] == 0);
        printf("%d\n",ans);
    }
    return 0;
}
