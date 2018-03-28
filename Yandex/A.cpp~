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
#define ios ios::sync_with_stdio(0);
#define N 100001

int main(){
    int n , L;
    while( cin >> n >> L ){
        int c1 = 0 , c2 = 0 , t , d;
        for(int i = 0 ; i < n ; i++){
            cin >> t >> d;
            if( t == 1 ){
                if( d == -1 ) c1++;
                else if( d <= L ) c1 += 2;
                else c1 += 3;
            }
            else{
                if( d == -1 ) c2++;
                else if( d <= L ) c2 += 2;
                else c2 += 3;
            }
        }
        cout << c1 << ":" << c2 << '\n';
    }
    return 0;
}
