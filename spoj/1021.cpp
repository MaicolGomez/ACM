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
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf 2000000000
#define eps 1e-6
#define ll long long
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
#define N 6105 
#define ALPH_SIZE 52
  
using namespace std;
char s[N];
int n , t[2][N];

int f(){
    for(int i = 0 ; i <= n ; i++)
        t[0][i] = 0;
    t[1][0] = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if( s[i] == s[n-j+1] ) t[i&1][j] = 1 + t[!(i&1)][j-1];
            else t[(i&1)][j] = max( t[!(i&1)][j] , t[(i&1)][j-1] );
        }
    }
    return t[n&1][n];
}

int main(){
    int tc;
    sc(tc); gets(s);
    while( tc-- ){
        gets(s+1);
        n = strlen(s+1);
        printf("%d\n",n - f());
    }
}


