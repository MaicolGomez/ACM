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

int main(){
    int n , k;
    while( scanf("%d%d",&n,&k) == 2 ){
        if( n == -1 ) break;
        int x = 1;
        while( x * (x - 1) / 2 < k ) x++;
        
        for(int i = 1 ; i <= n - x ; i++)
            printf("%d ",i);
        
        int j = n - x * (x - 1) /2 + k ;
        printf("%d",j);
        for(int i = n ; i > n - x ; i--)
            if( i != j )printf(" %d",i);
        
        printf("\n");
        
    }
    return 0;
}
