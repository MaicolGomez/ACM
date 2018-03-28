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
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 100001

int n;

string P(string s){
    for(int i = 0 ; i < n ; i++)
        if( '0' <= s[i] and s[i] <= '9' ){
            if( s[i] > '0' ) s[i]--;
            else s[i] = '9';
        }
    return s;
}
string M(string s){
    for(int i = 0 ; i < n ; i++)
        if( '0' <= s[i] and s[i] <= '9' ){
            if( s[i] < '9' ) s[i]++;
            else s[i] = '0';
        }
    return s;
}

string C(string s){ return s.substr( 1 ) + s.substr(0 , 1); }
string J(string s){ return s.substr( n - 1 , 1 ) + s.substr( 0 , n - 1 ); }
string E(string s){
    if( n&1 ) return s.substr( n - n/2 , n/2 ) + s.substr( n/2 , 1 ) + s.substr( 0 , n/2 );
    else return s.substr( n - n/2 , n/2 ) + s.substr( 0 , n/2 );
}

string A(string s){ reverse(all(s)); return s; }

int main(){
    int tc;
    sc(tc);
    string make , s;
    while( tc-- ){
        cin >> make >> s;
        n = s.size();
        for(int i = make.size() - 1 ; i >= 0 ; i--){
            if( make[i] == 'J' ) s = J( s );
            else if( make[i] == 'C' ) s = C( s );
            else if( make[i] == 'E' ) s = E( s );
            else if( make[i] == 'A' ) s = A( s );
            else if( make[i] == 'P' ) s = P( s );
            else if( make[i] == 'M' ) s = M( s );
        }
        cout << s << "\n";
    }
    return 0;
}
