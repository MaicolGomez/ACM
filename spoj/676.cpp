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

int a[N] , n , pos[N] , R[N][N] , t[N][N]; //Cuantos mayores a j estan desde 1 hasta i
int Q[N][N]; // Cuantos menores a j estan desde 1 hasta i

void precal(){
    me(R[0],0);
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            R[i][j] = R[i-1][j] + ( a[i] > j );
    
    me(Q[0],0);
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            Q[i][j] = Q[i-1][j] + ( a[i] < j );
}

int f(int l,int r){
    if( r == n + 1 ) r = 0;
    if( l == 0 && r == 0 )
        return 0;
    int &ret = t[l][r];
    if( ret != -1 ) return ret;    
    if( r == 0 ){
        int used = n - l;
        int k = pos[l] - R[pos[l]][l];
        ret = (used+1) * k + f( l - 1 , r );
    }
    else if( l == 0 ){
        int used = r - 1;
        int k = pos[r] - Q[pos[r]][r];
        ret = (used+1) * k + f( l , r + 1 );
    }
    else{
        int used = r - l - 1;
        int k = pos[l] - R[pos[l]][l] + R[pos[l]][r-1];
        ret = (used+1) * k + f( l - 1 , r );
        k = pos[r] - Q[pos[r]][r] + Q[pos[r]][l+1];
        ret = min( ret ,  (used+1) * k + f( l , r + 1 ) );
    }
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        sc(n);
        for(int i = 1 ; i <= n ;i++)
            sc(a[i]) , pos[a[i]] = i;
        
        precal();
        me(t,-1);
        int ans = inf;
        for(int i = 1 ; i <= n ; i++)
            ans = min( ans , i + f( a[i]-1 , a[i]+1 ) );
            
        printf("%d\n",ans);
    }
    return 0;
}
