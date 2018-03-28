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

string A[N];

int main(){
    A[0] = "http://www.acm.org/";
    string a , b;
    int size = 1 , p = 0;
    while( 1 ){
        cin >> a;
        if( a == "QUIT" ) break;
        if( a == "VISIT" ){
            cin >> b;
            A[++p] = b;
            size = p + 1;
            cout << b << "\n";
        }
        else if( a == "BACK" ){
            if( p == 0 ) cout << "Ignored\n";
            else cout << A[--p] << "\n";
        }
        else if( a == "FORWARD" ){
            if( p + 1 == size ) cout << "Ignored\n";
            else cout << A[++p] << "\n";
        }
    }
    return 0;
}
