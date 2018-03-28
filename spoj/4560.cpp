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
#define N 10005

int a[2][N] , l1 , l2 , t[N][2];
map<int,int> m , m1;

int f(int x,int last){
    if( last == 0 && x == l1 ) return 0;
    if( last == 1 && x == l2 ) return 0;
    int &ret = t[x][last];
    if( ret != -1 ) return ret;
    ret = a[last][x] + f( x + 1 , last );
    if( last == 0 && m1.find( a[last][x] ) != m1.end() )
        ret = max( ret , a[last][x] + f( m1[ a[last][x] ] + 1 , 1 ) );
    if( last == 1 && m.find( a[last][x] ) != m.end() ) 
        ret = max( ret , a[last][x] + f( m[ a[last][x] ] + 1 , 0 ) );
    return ret;
}

int main(){
    while( sc(l1) == 1 && l1 ){
        m.clear(); m1.clear();
        for(int i = 0 ; i < l1 ; i++)
            sc(a[0][i]) , m[ a[0][i] ] = i;;
        sc(l2);
        for(int i = 0 ; i < l2 ; i++)
            sc(a[1][i]) , m1[ a[1][i] ] = i;
        
        me(t,-1);
        printf("%d\n", max( f(0,0) , f(0,1) ));
    }
    return 0;
}
