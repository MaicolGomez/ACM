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
#define ios ios::sync_with_stdio(0);
#define N 1001

int MOD , t[N][N][2] , len , R;
char s[N];

int f(int x,int mod,int ok){
    if( x == len ) return ((ok and mod == R)?0:-inf);
    int &ret = t[x][mod][ok];
    if( ret != -1 ) return ret;
    ret = f( x + 1 , mod , ok );
    if( !ok and s[x] > '0' ) ret = max( ret , 1 + f( x + 1 , (mod * 10 + (s[x] - '0'))%MOD , 1 ) );
    if( ok ) ret = max( ret , 1 + f( x + 1 , (mod * 10 + (s[x] - '0'))%MOD , 1 ) );
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        scanf("%s%d%d",s,&R,&MOD);
        me(t,-1);
        len = strlen( s );
        int L = f( 0 , 0 , 0 );
        if( L <= 0 ) printf("Not found\n");
        else{
            int pos = 0 , mod = 0;
            while( L ){
                bool end = 0;
                for(char i = '9' ; i >= '0' and !end ; i--)
                    for(int j = pos ; j < len and !end ; j++){
                        if( s[j] == i and f( j + 1 , (mod * 10 + (i - '0')) % MOD , 1 ) == L - 1 ){
                            pos = j + 1;
                            mod = (mod * 10 + (i - '0')) % MOD;
                            end = 1;
                            printf("%c",i);
                        }
                    }
                L--;
            }
            printf("\n");
        }
    }
    return 0;
}
