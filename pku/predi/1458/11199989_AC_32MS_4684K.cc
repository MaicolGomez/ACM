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

string a , b;
int t[N][N];

int f(int x,int y){
    if( x == a.size() || y == b.size() )
        return 0;
    
    int &ret = t[x][y];
    if( ret != -1 ) return ret;
    ret = 0;
    ret = max( f(x+1,y) , f(x,y+1) );
    if( a[x] == b[y] )
        ret = max( ret , 1 + f( x + 1 , y + 1 ) );
    return ret;
}

int main(){
    while( cin >> a >> b ){
        me(t,-1);
        cout << f(0,0) << endl;
    }
    return 0;
}