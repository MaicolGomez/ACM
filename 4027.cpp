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
#define MOD 10007
#define ios ios::sync_with_stdio(0)
#define N 1005

int t[N][N];
char s[N];
/*
int f(int x,int y,int u){
    if( y < x ) return u;
    //int &ret = t[x][y][u];
    if( ret != -1 ) return ret;
    ret = 0;
    ret += f( x , y - 1 , u );
    if( ret >= MOD ) ret -= MOD;
    ret += f( x + 1 , y , u );
    if( ret >= MOD ) ret -= MOD;
    ret -= f( x + 1 , y - 1 , u );
    if( ret < 0 ) ret += MOD;
    if( s[x] == s[y] ) ret += f( x + 1 , y - 1 , 1 );
    if( ret >= MOD ) ret -= MOD;
    return ret;
}*/

int main(){
    int tc;
    sc(tc);
    for(int x = 1 ; x <= tc ; x++){
        printf("Case %d: ",x);
        scanf("%s",s);
        int n = strlen(s);
        me(t,0);
        for(int i = n - 1 ; i >= 0 ; i--){
            t[i][i] = 1;
            for(int j = i + 1 ; j < n ; j++){       
                if( s[i] == s[j] ) t[i][j] = (t[i+1][j-1] + 1)%MOD;
                t[i][j] = ( t[i+1][j] + t[i][j-1] - t[i+1][j-1] + t[i][j] + MOD )%MOD;
            }
        }
        printf("%d\n" , t[0][n-1] );
    }
    return 0;
}
