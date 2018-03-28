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
#define N 1000005

char s[N];
int t[N][2];

int main(){
    int L;
    while( sc(L) == 1 ){
        scanf("%s",s);
        t[0][0] = 1 - (s[0] == 'A');
        t[0][1] = 1 - (s[0] == 'B');
        for(int x = 1 ; x < L ; x++)
            for(int c = 0 ; c < 2 ; c++){
                if( !c ){
                    if( s[x] == 'A' ) t[x][c] = t[x-1][c];
                    else t[x][c] = min( 1 + t[x-1][!c]  , 1 + t[x-1][c] );
                }
                else{
                    if( s[x] == 'B' ) t[x][c] = t[x-1][c];
                    else t[x][c] = min( 1 + t[x-1][!c] , 1 + t[x-1][c] );
                }
            }
        
        printf("%d\n",t[L-1][0]);
    }
    return 0;
}
