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
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf (1<<30)
#define eps 1e-8
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mk(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define fi first
#define se second
#define N 55
#define mp(a,b) make_pair(a,b)

double f[N][N];

int main(){
    for(int i = 1 ; i <= 50 ; i++){
        f[i][1] = 1;
        for(int j = 1 ; j < i ; j++) f[i][j] = f[i-1][j-1] + j * f[i-1][j];
        f[i][i] = 1;
    }
    int n;
    while( sc(n) && n ){
        double ans = 0;
        for(int i = 1 ; i <= n ; i++) ans += f[n][i];
        printf("%d %.0lf\n",n,ans);
    }
}