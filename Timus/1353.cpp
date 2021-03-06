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
#define N 11

int t[N][90];

int f(int n,int S){
    if( n == 0 )
        return S == 0;
    int &ret = t[n][S];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = 0 ; i < 10 ; i++)
        if( S - i >= 0 ) ret += f( n - 1 , S - i );
    return ret;
}

int main(){
    int S;
    sc(S);
    me(t,-1);
    int ans = 0;
    for(int l = 1 ; l <= 9 ; l++)
        for(int i = 1 ; i <= 9 ; i++)
            if( S - i >= 0 ) ans += f( l - 1 , S - i );
        
    
    
    printf("%d\n",ans+(S==1));
    return 0;
}
