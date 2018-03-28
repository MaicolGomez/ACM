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
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 100001

int t[N][2] , n;
int a[N];

int f(int x,int h){
    if( x == n - 1 )
        return 0;
    
    int &ret = t[x][h];
    if( ret != -1 ) return ret;
    if( h == 0 ){
        ret = (a[x] >= 0) +  f( x + 1 , h );
        ret = min( ret , (a[x]<=0) + f(x+1 , 1) );
    }
    else
        ret = (a[x]<=0) + f( x + 1 , h );
    return ret;
}

int main(){
    freopen( "input.txt" , "r" , stdin );
    freopen( "output.txt" , "w" , stdout );
    while( sc(n) == 1 ){
        for(int i = 0 ; i < n ; i++)
            sc(a[i]);
        
        me(t,-1);
        
        printf("%d\n",(a[0]>=0) + (a[n-1]<=0) +  f(1,0));
        
    }
    return 0;
}
