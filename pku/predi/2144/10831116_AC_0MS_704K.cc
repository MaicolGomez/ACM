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
#define inf 2000000000
#define eps 1e-6
#define ll long long
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
#define N 16005

unsigned int v[9];

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int k;
        for(int i = 0 ; i < 9 ; i++)
            scanf("%x",&v[i]);
        unsigned ans = 0;
        for(int i = 0 ; i < 32 ; i++){
            unsigned sum = 0;
            for(int j = 0 ; j < 8 ; j++)
                sum += v[j]^ans;
            if( (sum&(1<<i)) != ((v[8]^ans)&(1<<i)) )
                ans |= 1<<i;
        }
        printf("%x\n",ans);
    }
    return 0;
}