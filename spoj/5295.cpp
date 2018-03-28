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
#define N 1005

int t[N][N][2] , n , k;

int f(int x,int y,int last){
    if( x == n )
        return y == k;
    int &ret = t[x][y][last];
    if( ret != -1 ) return ret;
    ret = 0;
    if( y > k ) ret = 0;
    else{
        ret += f( x + 1 , y + last * 1 , 1 );
        ret += f( x + 1 , y , 0 );
    }
    return ret;
}

int main(){
    int tc , tt;
    sc(tc);
    for(int i = 0 ; i < tc ; i++){
        sc(tt); sc(n) , sc(k);
        me(t,-1);
        printf("%d %d\n",tt,f(0,0,0));
        
    }
    return 0;
}
