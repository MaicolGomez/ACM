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

string get(string a,string b){
    string ans = "";
    for(int i = 0 ; i < a.size() ; i++){
        ans += b[i];
        ans += a[i];
    }
    return ans;
}

void I(string s,string &a,string &b){
    a = "" , b = "";
    for(int i = 0 ; i < s.size() ; i++)
        if( i * 2 < s.size() ) a += s[i];
        else b += s[i];
    return;
}

int main(){
    int tc , test = 1;
    sc(tc);
    while( tc-- ){
        string a , b , target;
        int n;
        cin >> n >> a >> b >> target;
        string init = get( a , b );
        I( init , a , b );
        if( init == target ){
            printf("%d %d\n",test++,1);
            continue;
        }
        int r = 1;
        bool ok = 0;
        while( 1 ){
            string s = get( a , b ); r++;
            if( s == target ){
                ok = 1;
                break;
            }
            if( s == init ) break;
            I( s , a , b );
        }
        int ans = -1;
        if( ok ) ans = r;
        printf("%d %d\n",test++,ans);
    }
    return 0;
}
