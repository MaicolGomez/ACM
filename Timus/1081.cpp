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
#define N 55
int n , k , F[N];

int main(){
    F[1] = 2;
    F[2] = 3;
    for(int i = 3 ; i <= 44 ; i++)
        F[i] = F[i-1] + F[i-2];
    
    while( cin >> n >> k ){
        if( k <= F[n] ){
            string ans = "";
            while( n > 1 ){
                if( k <= F[n-1] )
                    ans += "0";
                else{
                    k -= F[n-1];
                    ans += "1";
                }
                n--;
            }
            if( k == 1 ) ans += "0";
            else ans += "1";
            cout << ans << endl;
        }
        else puts("-1");
    }
    return 0;
}
