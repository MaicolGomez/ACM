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
#define N 1400


int main(){
    string s;
    int k;
    while( cin >> k  >> s ){
        if( k == -1 ) break;
        int ns = s.size();
        if( k >= ns ){
            cout << "\n";
            continue;
        }
        if( k == 0 ){
            cout << s << "\n";
            continue;
        }
        int x = 0;
        for(int i = 0 ; i < ns ; i++) x += s[i]!='a';
        
        if( k >= x ){
            cout << string( ns - k , 'a' ) << "\n";
            continue;
        }
        string ans = string( k , 'a' ) + s;
        int pos = 0;
        for(int i = k ; i >= 1 ; i--){
            while( s[pos] == 'a' ) pos++;
            string x = string( i + pos , 'a' ) + s.substr( pos + 1 );
            ans = min( ans , x );
            pos++;
        }
        cout << ans << '\n';
    }
    return 0;
}
