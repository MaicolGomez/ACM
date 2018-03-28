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

string a , b;

string solve(int x,int y,int p,int q){
    string ans = "";
    ans += a[x];
    if( x == y ) return ans;
    if( x > y ) return "";
    string s = "";
    int len = 0;
    for(int i = p ; i <= q ; i++,len++)
        if( a[x] == b[i] ) break;
    
    //cout << x << " -- " << y << " --> " << p << " -- " << q << " : " << len << endl;
    s += solve( x + 1 , x + len , p , p + len - 1 );
    s += solve( x + len + 1 , y , p + len + 1 , q );
    s += a[x];
    return s;
}

int main(){
    while( cin >> a >> b ){
        cout << solve( 0 , a.size() - 1 , 0 , b.size() - 1 ) << endl;
    }
    return 0;
}
