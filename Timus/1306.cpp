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
#define N 25001


int main(){
    int n , r = 0;
    unsigned int x , a , b;
    scanf("%d",&n);
    priority_queue<unsigned int> Q;
    bool odd = 0;
    if( n&1 ) odd = 1;
    for(int i = 0 ; i <= n/2 ; i++){
        scanf("%u",&x);
        Q.push( x );
    }
    n -= n/2 + 1;
    for(int i = 0 ; i < n ; i++){
        scanf("%u",&x);
        Q.push( x );
        Q.pop(); 
    }
    if( odd ) printf("%u\n",Q.top());
    else{
        a = Q.top();
        Q.pop();
        printf("%.1lf\n", 0.5 * ( a + Q.top() ));
    }
    
    return 0;
}
