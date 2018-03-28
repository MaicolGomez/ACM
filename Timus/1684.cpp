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
#define N 75005

int z[2*N] , A[N];
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

int R[N][20];

void RMQ(int l){
    for(int i = 0 ; i < l ; i++) R[i][0] = i;
    for(int j = 1 ; (1<<j) <= l ; j++)
        for(int i = 0 ; i + (1<<j) - 1 < l ; i++){
            if( A[ R[i][j-1] ] > A[ R[i + (1<<(j-1)) ][j-1] ] )
                R[i][j] = R[i][j-1];
            else R[i][j] = R[i+(1<<(j-1))][j-1];
            //cout << i << " " << j << " " << R[i][j] << " --> " << R[i][j-1] << " " << R[i + (1<<(j-1))][j-1] << endl;
        }
}

int query(int a,int b){
    int l = b - a + 1;
    if( l == 0 ) return R[a][0];
    int k = 0;
    while( (1<<k) <= l ) k++;
    k--;
    return ( A[R[a][k]] > A[R[b-(1<<k)+1][k]] )?R[a][k]:R[b-(1<<k)+1][k];
}

int main(){
    string a , b;
    while( cin >> a >> b ){
        s = a + '$' + b;
        zeta();
        for(int i = a.size() + 1 ; i < s.size() ; i++){
            A[i-a.size()-1] = (i - a.size() - 1) + z[i] - 1;
            if( z[i] == 0 ) A[ i - a.size() - 1 ] = -1;
        }
        RMQ( b.size() );
        int last = 0;
        if( A[last] == b.size() ){
            cout << "No" << '\n';
            cout << b << '\n';
            continue;
        }
        bool ok = 0;
        vector<string> v;
        while( 1 ){
            if( A[last] < 0 ) break;
            int der = A[last];
            //cout << last << " " << der << endl;
            int q = query( last , der );
            int go = A[q];
            //cout << q << " - " << go << endl;
            if( der == b.size() - 1 ){
                //v.pb( b.substr( last , q - 1 ) );
                v.pb( b.substr( last ) );
                ok = 1;
                break;
            }
            if( go > der ){
                v.pb( b.substr( last , q - last ) );
                last = q;
            }
            else{
                v.pb( b.substr( last , der - last + 1 ) );
                last = der + 1;
            }
        }
        if( ok ){
            puts("No");
            for(int i = 0 ; i < v.size() ; i++){
                if( i ) printf(" ");
                cout << v[i];
            }
            printf("\n");
        }
        else puts("Yes");
    }
    return 0;
}
