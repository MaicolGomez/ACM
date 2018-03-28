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

string s;

int f( int a , int b ){
    int ct = 0;
    for(int i = a ; i <= b ; i++){
        if( s[i] == '(' ) ct++;
        if( s[i] == ')' ) ct--;
        if( ct == 0 && s[i] == '*' ) return f( a , i - 1 ) * f( i + 1 , b );
        if( ct == 0 && s[i] == '+' ) return f( a , i - 1 ) + f( i + 1 , b );
        if( ct == 0 && s[i] == '-' ) return f( a , i - 1 ) - f( i + 1 , b );
    }
    if( s[a] == '(' ) return f( a + 1 , b - 1 );
    int ans = 0;
    for(int i = a ; i <= b ; i++) ans = ans * 10 + (s[i]-'0');
    return ans;
}

int main(){
    while( cin >> s ){
        cout << f( 0 , s.size() - 1 ) << endl;
    }
}


