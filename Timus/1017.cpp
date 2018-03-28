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
#define N 505

ll t[N];
/*
ll f(int last,int have){
    if( have == 0 )
        return 1;
    ll &ret = t[last][have];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = last + 1 ; i <= have ; i++)
        ret += f( i , have - i );
    return ret;
}
*/
int main(){
    t[0] = 1;
    for(int i = 1 ; i <= 500 ; i++)
        for(int j = 500 ; j >= i ; j--)
            t[j] += t[j-i];
    
    int n;
    while( sc(n) == 1 ){
        printf("%lld\n",t[n]-1);
    }
    return 0;
}
