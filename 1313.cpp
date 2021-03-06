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
#define N 100005
using namespace std;

int n , x[1000] , y[1000];

int main(){
    int tc;
    sc(tc);
    while(tc--){
        sc(n);
        
        map< pair<int,int> , int> M;
        map< pair<int,int> , int>::iterator it;
        for(int i = 0 ; i < n ; i++)
            scanf("%d %d",&x[i],&y[i]);
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ;j < i; j++)
                M[make_pair(x[i]+x[j],y[i]+y[j])]++;
        
       int ans = 0;
       int h;
        for(it=M.begin();it!=M.end();++it){
            h = it->second;
            ans += h*(h-1)/2;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
