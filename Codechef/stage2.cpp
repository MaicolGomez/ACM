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
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 505

int R[2][N][N] , C[2][N][N] , t[N];
char s[N][N];

bool prime(int x){
    for(int i = 2 ; i * i <= x ; i++)
        if( x % i == 0 ) return 0;
    return 1;
}

int main(){
    for(int i = 2 ; i <= 500 ; i++){
        t[i] = t[i-1];
        if( prime(i) ) t[i]++;
    }
    int tc , r , c;
    sc(tc);
    while( tc-- ){
        sc(r),sc(c);
        me(R,0);
        me(C,0);
        for(int i = 1 ; i < r + 1 ; i++){
            scanf("%s",s[i]+1);
            for(int j = 1 ; j <= c ; j++)
                if( s[i][j] != '#' ) R[0][i][j] = R[0][i][j-1] + 1;
            for(int j = c ; j >= 1 ; j--)
                if( s[i][j] != '#' ) R[1][i][j] = R[1][i][j+1] + 1;
        }
        for(int i = 1 ; i < c + 1 ; i++){
            for(int j = 1 ; j < r + 1 ; j++)
                if( s[j][i] != '#' ) C[0][j][i] = C[0][j-1][i] + 1;
            for(int j = r ; j >= 1 ; j--)
                if( s[j][i] != '#' ) C[1][j][i] = C[1][j+1][i] + 1;
        }
        int ans = 0;
        for(int i = 1 ; i < r + 1 ; i++){
            for(int j = 1 ; j < c + 1 ; j++)if( s[i][j] != '#' ){
                int r = R[0][i][j-1];
                r = min( r , R[1][i][j+1] );
                r = min( r , C[0][i-1][j] );
                r = min( r , C[1][i+1][j] );
                ans += t[r];
            }
            //cout << endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}
