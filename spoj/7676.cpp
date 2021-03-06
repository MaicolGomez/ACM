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
#define N 1005

#include<iostream>
#include<vector>
using namespace std;

vll cuenta(long long n){
        vector<long long>dev(10,0);
        if( n <= 0 ) return dev;
        for(long long i=1;i<=n;i*=10){ 
            long long a=(n/i)/10;
            for(long long j=0;j<10;j++)dev[j]+=a*i;
            dev[0]-=i;
            for(long long j=0;j<(n/i)%10;j++)dev[j]+=i; 
            dev[(n/i)%10]+= (n%i)+1; 
        }
        return dev;
}

int main(){
    long long m , n;
    while( cin>>m>>n ){
        if(m < 0 && n < 0) break;
        vll x = cuenta(n) , y = cuenta(m-1);
        ll ans = 0;
        for(int i = 1 ; i < 10 ; i++)
            ans += (x[i] - y[i]) * i;
        
        printf("%lld\n",ans);
    }    
}

