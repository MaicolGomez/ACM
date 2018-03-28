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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define N 1005

int f(int n){
    if(n == 0) return 0;
    vector<int>dev(10,0);
        for(int i=1;i<=n;i*=10)
        {
            int a=(n/i)/10;
            for(int j=0;j<10;j++)dev[j]+=a*i;
            dev[0]-=i;
            for(int j=0;j<(n/i)%10;j++)dev[j]+=i;
            dev[(n/i)%10]+= (n%i)+1;
        }
    return dev[0];
}

int main(){
    int n , tc , a , b;
    sc(tc);
    while(tc--){
        sc(a),sc(b);
        printf("%d\n",f(b)-f(a-1));
    }
   return 0;
}
