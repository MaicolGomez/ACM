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
#define MOD 10009
#define N 1005

int A[11];

int main(){
    string s , t;
    cin >> s >> t;
    for(int i = 0 ; i < s.size() ; i++)
        A[ s[i] - '0' ]++;
    
    string ans = "";
    for(int i = 1 ; i < 9; i++)
        if( A[i] ){
            ans += i + '0' , A[i]--;
            break;    
        }
    
    for(int i = 0 ; i < 10 ; i++)
        while( A[i] ){
            ans += i + '0';
            A[i]--;
        }
    //cout << ans << endl;
    if( ans == t ) cout << "OK" << endl;
    else cout << "WRONG_ANSWER" << endl;
    
    return 0;
}
