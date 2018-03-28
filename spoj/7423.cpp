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
#define N 1000000

char s[N+5];
int b[N+5];

void kmp(){
    int j = -1;
    b[0] = j;
    int l = strlen(s);
    for(int i = 0 ; i < l ; i++){
        while( j >= 0 && s[j] != s[i] ) j = b[j];
        b[i+1] = ++j;
    }
}

int main(){
    int n;
    while( 1 ){
        scanf("%d",&n);
        if( n == -1 ) break;
        scanf("%s",s);
        int l = strlen(s);
        if( l == 1 ) printf("%d\n",n);
        else if( l > n ) printf("%d\n",0);
        else{
            kmp();
            int ans = (n - b[l])/( l - b[l] );
            printf("%d\n",ans);
        }
    }
    return 0;
}
