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
#define N 1000005

char s[N];
int t1[N] , t2[N]; //t1 get AAA -- t2 get BBB

int main(){
    int n;
    while( scanf("%d",&n) == 1 ){
        scanf("%s",s);
        if( s[0] == 'A' ) t1[0] = 0 , t2[0] = 1;
        else t2[0] = 0 , t1[0] = 1;
        
        for(int i = 1 ; i < n ; i++){
            if( s[i] == 'A' ){
                t1[i] = min( t1[i-1] , t2[i-1] + 1 );
                t2[i] = min( t1[i-1] + 1 , t2[i-1] + 1 );
            }
            else{
                t1[i] = min( t1[i-1] + 1 , t2[i-1] + 1 );
                t2[i] = min( t1[i-1] + 1 , t2[i-1] );
            }
        }
        printf("%d\n",t1[n-1]);
    }
    return 0;
}
