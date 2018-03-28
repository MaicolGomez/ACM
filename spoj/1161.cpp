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
    int tc;
    cin >> tc;
    while( tc-- ){
        vector<string> v(3);
        for(int i = 0 ; i < 3 ; i++)
            cin >> v[i];
        
        int winx = win( v , 'X' ) , wino = win( v , 'O' ) , x = 0 , o = 0;
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                x += (v[i][j]=='X') , o += (v[i][j]=='O');
        //cout << x << " " << o << " " << winx << " " << wino << endl;
        if( (o>x) || (x>o+1) || (x==o+1&&wino) || (x==o&&winx) || (winx>2) || (wino>1) || (winx&&wino) ) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}
