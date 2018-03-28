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
#define ALF 28

string s , d[15];
int t[N][ALF] , n;

int f(int x,int last){
    if( x == s.size() ) return 0;
    int &ret = t[x][last];
    if( ret != -1 ) return ret;
    ret = inf;
    ret = 1 + f( x + 1 , last );
    bool ok = 1;
    for(int i = 0 ; i < n && ok ; i++)
        if( ('a' + last == d[i][0] && s[x] == d[i][1] ) || ('a' + last == d[i][1] && s[x] == d[i][0] ) ) ok = 0;
    
    if( ok ) ret = min( ret , f( x + 1 , s[x] - 'a' ) );
    return ret;
}

int main(){
    while( cin >> s ){
        cin >> n;
        for(int i = 0 ; i < n ; i++)
            cin >> d[i];
        me(t,-1);
        int ans = f( 0 , 26 );
        cout << ans << endl;
    }
    
    return 0;
}
