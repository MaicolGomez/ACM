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
#include<ctype.h>
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

int main(){
    string s;
    while( getline( cin , s ) ){
        string k = "";
        for(int i = 0 ; i < s.size() ; i++)
            if( (s[i] >= '0' && s[i] <= '9') || ( tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z' ) ){
                if( (s[i] >= '0' && s[i] <= '9') ) k += s[i];
                else k += tolower(s[i]);
            }
        cout << k << endl;
    }
    return 0;
}
