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
#define N 100001

int main(){
    int n , test = 1;
    while( sc(n) == 1 and n ){
        vector<bool> used( 26 , 0 );
        used[0] = 1;
        char a[5] , b[5] , c[5];
        for(int i = 0 ; i < n ; i++){
            scanf("%s %s %s",a,c,b);
            if( used[b[0] - 'a'] ) used[a[0] - 'a'] = 1;
            else used[a[0] - 'a'] = 0;
        }
        int ans = 0;
        printf("Program #%d\n",test++);
        for(int i = 0 ; i < 26 ; i++){
            if( used[i] ){
                ans++;
                printf("%c ", i + 'a');
            }
        }
        if( ans == 0 ) printf("none");
        printf("\n\n");
    }
    return 0;
}
