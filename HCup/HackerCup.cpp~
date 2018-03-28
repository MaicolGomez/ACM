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

int main(){
    int n;
    string s;
    cin >> n; getline( cin , s );
    
    for(int t = 1 ; t <= n ; t++){
        getline( cin , s );
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++)if( s[i] != ' ' )
            ans += (s[i] > 'Z')?(s[i] - 'a'):(s[i] - 'A') + 1;
        
        printf("Case #1: %d\n",ans);
    }
    return 0;
}
