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
#define fi first
#define se second
#define MOD 10009
#define N 200005

int z[N];
string s;

void zeta(){
    int L = 0, R = 0;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        }
        else{
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
}

int main(){
    string a , b;
    while( cin >> a >> b ){
        s = a + '$' + b;
        zeta();
        int x = z[a.size() + 1 ];
        int last = a.size() + 1;
        if( x == b.size() ){
            cout << "No\n";
            cout << b << '\n';
            continue;
        }
        bool ok = 0;
        vector<string> v;
        //cout << x << " " << last << endl;
        while( 1 ){
            int maxi = 0 , pos = -1;
            for(int i = last + 1 ; i <= last + x ; i++){
                if( z[i] > maxi ){
                    maxi = z[i];
                    pos = i;
                }
            }
            if( maxi == 0 ) break;
            v.pb( s.substr( last , pos - last ) );
            last = pos;
            x = maxi;
            if( pos + maxi == s.size() ){
                v.pb( s.substr( pos ) );
                ok = 1;
                break;
            }
        }
        if( ok ){
            puts("No");
            for(int i = 0 ; i < v.size() ; i++){
                if( i ) printf(" ");
                printf("%s",v[i].c_str());
            }
            printf("\n");
        }
        else puts("Yes");
    }
    return 0;
}
