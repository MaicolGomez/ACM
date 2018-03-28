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
#define inf 2000000000
#define eps 1e-6
#define ll long long
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
#define N 16005
#define ALF 26

int T[N][ALF];
int C[N] , node;

void init(){
    node = 1;
    me(T,-1);
}

void add(string s,int x){
    int ac = 0;
    for(int i = 0 ; i < s.size() ; i++){
        if( T[ac][s[i]-'a'] == -1 ) T[ac][s[i]-'a'] = node++;
        ac = T[ac][s[i]-'a'];
    }
    C[ac] = x;
}

int find(string s){
    int ac = 0;
    for(int i = 0 ; i < s.size() ; i++){
        if( T[ac][s[i]-'a'] == -1 ) return 0;
        ac = T[ac][s[i]-'a'];
    }
    return C[ac];
}

int main(){
    ios::sync_with_stdio(0);
    init();
    int n , m , val;
    string s , t;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> s >> val;
        add( s , val );
    }
    getline(cin,s);
    while( m-- ){
        int ans = 0;
        while( getline( cin , s) ){
            if( s == "." ) break;
            stringstream in(s);
            while( in >> t )
                ans += find( t );
        }
        cout << ans << '\n';
    }
}