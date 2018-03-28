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
#define N 2005

int t[N][N] , n , A[N];

int f(int a,int b){
    if( a == b ) return n * A[a];
    int &ret = t[a][b];
    if( ret != -1 ) return ret;
    ret = max( (n-(b-a))*A[a] + f( a + 1 , b ) , (n - (b-a)) * A[b] + f( a , b - 1 ) );
    return ret;
}

int main(){
    sc(n);
    for(int i = 0 ; i < n ; i++)
        sc(A[i]) , me(t[i],-1);
    
    printf("%d\n",f(0,n-1));    
    
    return 0;
}
