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
#define N 100005

bool can[N];
int a[5];

int main(){
    int n , k;
    sc(n);
    sc(k);
    for(int i = 0 ; i < k ; i++)
        sc(a[i]);

    for(int i = 1 ; i < k ; i++)
        a[i] += a[i-1];
        
    can[0] = 1;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 0 ; j < k ; j++)if( i - a[j] >= 0 )
            can[i] |= can[ i - a[j] ];
    
    if(can[n] ) printf("YES\n");
    else printf("NO\n");
    return 0;
}
