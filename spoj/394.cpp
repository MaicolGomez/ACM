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
#define N 5005

char s[N];
int L;
ll t[N];

ll f(int x){
    if( x >= L )
        return 1;
    if( s[x] == '0' ) return 0;
    ll &ret = t[x];
    if( ret != -1 ) return ret;
    ret = f(x+1);
    int g = (s[x]-'0')*10 + (s[x+1]-'0');
    if( x + 1 < L && g <= 26 ) ret += f(x+2);
            
    return ret;
    
}

int main(){
    
    while( scanf("%s",s) ){
        if( s[0] == '0' ) break;
        L = strlen(s);
        me( t , -1 );
        
        printf("%lld\n", f(0) );
        
    }
    
    return 0;
}
