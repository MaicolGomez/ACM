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
#define N 105

char s[N];
int t[N][N] , pa[N][N];
vector<char> I , F;

bool val(int x,int y){
    return (s[x] == '(' && s[y] == ')') || (s[x] == '[' && s[y] == ']');
}

int f(int a,int b){
    if( a > b ) return 0;
    if( a == b ) return 1;
    int &ret = t[a][b];
    if( ret != -1 ) return ret;
    ret = inf;
    ret = 1 + f( a + 1 , b ); pa[a][b] = 101;
    if( 1 + f( a , b - 1 ) < ret ) ret = 1 + f( a , b - 1 ), pa[a][b] = 102;
    for(int i = a ; i < b ; i++)
        if( f( a , i ) + f( i + 1 , b ) < ret ) ret = f( a , i ) + f( i + 1 , b ), pa[a][b] = i;
    
    if( val( a , b ) && f( a + 1 , b - 1 ) < ret ) ret = f( a + 1 , b - 1 ), pa[a][b] = 103;
    return ret;
}

char op(char x){
    if( x == '(' ) return ')';
    if( x == ')' ) return '(';
    if( x == ']' ) return '[';
    return ']';
}

pair<char,char> good(char x){
    if( x == ')' || x == '(' ) return mp( '(' , ')' );
    return mp( '[' , ']' );
}

int ini , fin;
char ans[205];

void rec(int a,int b,int ini, int fin,int der){
    if( a > b ) return;
    if( a == b ){
        pair<char,char> m = good(s[a]);
        ans[ini] = m.fi;
        ans[fin] = m.se;
        return;
    }
    if( pa[a][b] == 101 ){
        pair<char,char> m = good(s[a]);
        ans[ini] = m.fi;
        ans[ini+1] = m.se;
        rec( a + 1 , b , ini + 2 , fin , der + 1 );
    }
    else if( pa[a][b] == 102 ){
        pair<char,char> m = good(s[b]);
        ans[fin-1] = m.fi;
        ans[fin] = m.se;
        rec( a , b - 1 , ini , fin - 2 , der );
    }
    else if( pa[a][b] == 103 ){
        ans[ini] = s[a] , ans[fin] = s[b];
        rec( a + 1 , b - 1 , ini + 1 , fin - 1 , der );
    }
    else{
        rec( a , pa[a][b] , ini , pa[a][b] + f( a , pa[a][b] ) + der , der);
        rec( pa[a][b] + 1 , b , der + pa[a][b] + f( a , pa[a][b] ) + 1 , fin , der + f(a,pa[a][b]) );
    }
}

int main(){
    while( gets(s) ){
        int n = strlen(s);
        me(t,-1);
        int r = f( 0 , n - 1 );
        ini = 0 , fin = n + r - 1;s
        rec( 0 , n - 1 , ini , fin , 0 );
        if( r == 0 ) cout << s << endl;
        else{
            for(int i = 0 ; i < n + r ; i++)
                cout << ans[i];
            cout << endl;
        }
    }
    return 0;
}
