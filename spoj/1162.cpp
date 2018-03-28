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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define N 1005

set< vector<string> > S;
string t = "XO";

int win( vector<string> v , char x ){
    string need = "";
    for(int i = 0 ; i < 3 ; i++) need += x;
    int ans = 0;
    for(int i = 0 ; i < 3 ; i++)
        if( v[i] == need ) ans++;
        
    for(int i = 0 ; i < 3 ; i++){
        string a = "";
        a += v[0][i];
        a += v[1][i];
        a += v[2][i];
        if( a == need ) ans++;
    }
    string a = "";
    a += v[0][0]; a += v[1][1]; a += v[2][2];
    if( a == need ) ans++;
    a = "";
    a += v[0][2]; a += v[1][1]; a += v[2][0];
    if( a == need ) ans++;
    return ans;
}


int main(){
    string s;
    while( cin >> s ){
        if( s == "end" ) break;
        vector<string> v;
        for(int i = 0 ; i < 9 ; i += 3){
            string t = s.substr( i , 3 );
            v.pb(t);
        }
        
        int winx = win( v , 'X' ) , wino = win( v , 'O' ) , x = 0 , o = 0 , d = 0;
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                x += (v[i][j]=='X') , o += (v[i][j]=='O') , d += (v[i][j]=='.');
        if( (o>x) || (x>o+1) || (x==o+1&&wino) || (x==o&&winx) || (winx>2) || (wino>1) || (winx&&wino) ) cout << "invalid" << endl;
        else if( winx && wino == 0 ) cout << "valid" << endl;
        else if( winx == 0 && wino ) cout << "valid" << endl;
        else if( winx == 0 && wino == 0 && d == 0 ) cout << "valid" << endl;
        else cout << "invalid" << endl;
    }
    return 0;
}
