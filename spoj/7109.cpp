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
#define N 100001

int main(){
    ll m , n;
    while( scanf("%lld%lld",&m,&n) == 2 and n != -1 ){
        ll dif = (ll)(1e15) , d = 20;
        int choose = -1;
        for(int i = 0 ; i < 21 ; i++){
            if( abs( i * n - d * m ) <= dif ){
                dif = abs( i * n - d * m );
                choose = i;
            }
        }
        ll mod = 100*m%n;
        int ans = 100 * m / n + ( 2 * mod >= n );
        string s = "";
        for(int i = 0 ; i < choose ; i++)
            s += "*";
        for(int i = s.size() ; i < 20 ; i++)
            s += "-";
        
        if( ans < 10 ){
            s[ 10 ] = '%';
            s[ 9 ] = ans + '0';
        }
        else if( ans < 100 ){
            s[ 11 ] = '%';
            s[ 10 ] = ans%10 + '0';
            s[ 9 ] = ans/10 + '0';
        }
        else{
            s[ 11 ] = '%';
            s[ 10 ] = '0';
            s[ 9 ] = '0';
            s[ 8 ] = '1';
        }
        cout << s << '\n';
    }
    return 0;
}
