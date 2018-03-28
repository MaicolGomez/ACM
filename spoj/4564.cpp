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

string s;
int t[30][30][26*10] , A[30];

int f(int x,int last,int S){
    if( x == s.size() ){
        if( last == x - 1 ) return 1;
        return ( A[x-1]-A[last] >= S)?1:0;
    }
    int &ret = t[x][last][S];
    if( ret != -1 ) return ret;
    ret = f( x + 1 , last , S );
    if( A[x] - A[last] >= S ) ret += f( x + 1 , x , A[x]-A[last] );
    return ret;
}

int main(){
    int test = 1;
    while( cin >> s ){
        if( s == "bye" ) break;
        s = "0" + s;
        A[0] = 0;
        for(int i = 1 ; i < s.size() ; i++)
            A[i] = A[i-1] + (s[i]-'0');
        me(t,-1);
        cout << test++ << ". " << f( 1 , 0 , 0 ) / 2 << '\n';
    }
    
    return 0;
}
