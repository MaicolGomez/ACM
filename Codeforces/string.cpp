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
#define N 1000005

string s;
int n , S[N];

int f(int lo,int k){
    int r = lo;
    if( S[lo] - S[lo-1] >= k ) return n - lo;
    if( S[n-1] - S[lo-1] < k ) return 0;
    int hi = n - 1;
    while( lo + 1 < hi ){
        int mid = (hi+lo)/2;
        if( S[mid] - ((r>=1)?S[r-1]:0) < k ) lo = mid;
        else hi = mid;
        //cout << lo << " -- " << hi << endl;
    }
    //cout << s << " " << r << " " << hi << endl;
    return n - hi;
}

int main(){
    int k;
    while( cin >> k >> s ){
        n = s.size();
        ll ans = 0;
        S[0] = s[0] == '1';
        for(int i = 1 ; i < n ; i++)
            S[i] = S[i-1] + (s[i]=='1');
        for(int i = 0 ; i < n ; i++){
            int l = f( i , k ) , l1 = f( i , k + 1 );
            //cout << i << " " << l << endl;
            ans += l-l1;
        }
        cout << ans << endl;
    }
    return 0;
}
