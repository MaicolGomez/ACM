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
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 1000005

int z[2][3*N];

void zeta(string &s,int *zz){
    int L = 0, R = 0;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            zz[i] = R-L; R--;
        }
        else{
        int k = i-L;
        if (zz[k] < R-i+1) zz[i] = zz[k];
        else {
          L = i;
          while (R < n && s[R-L] == s[R]) R++;
          zz[i] = R-L; R--;
        }
      }
    }
}

string rotacion(string s){
    int n = s.size();
    s += s;
    int mini = 0, p = 1, l = 0;
    while(p < n && mini + l + 1< n)
        if(s[mini + l] == s[p + l])
            l++;
        else if(s[mini + l] < s[p + l]){
            p = p + l + 1;
            l = 0;
        }else if(s[mini + l] > s[p + l]){
            mini = max(mini + l + 1, p);
            p = mini + 1;
        l = 0;
    }
    string ans = "";
    for(int i = mini ; i < mini + n ; i++) ans += s[i];
    return ans;
}

int main(){
    ios
    string p , s;
    int l1 , l2;
    while( cin >> l1 >> l2){
        cin >> p >> s;
        s = rotacion( s );
        string np , ns;
        ns = s;
        np = p;
        reverse( all(ns) );
        reverse( all(np) );
        p = s + "$" +  p + p;
        np = ns + "$" + np + np;
        zeta( p , z[0] );
        zeta( np , z[1] );
        cout << s << "\n";
        int best = (int)(1e10) , pos = -1;
        int size = l1 + l2 + 1;
        int r = l1 + 1;
        for(int i = l2 + 1 ; i < l2 + l1 + 1 ; i++){
            int x = z[0][i];
            if( x >= l2 - 1 ){
                if( i - (l2 + 1) < best ){
                    best = i - (l2 + 1) , pos = i;
                }
                if( l1 + l2 + 1 - i < best ){ best = l1 + l2 + 1 - i , pos = i;}
            }
            if( r < l2 + 1 ) r = l1 + l2;
            if( z[1][r] >= l2 - 1 or x + z[1][r] >= l2 - 1 ){
                if( i - (l2 + 1) < best ){ best = i - (l2 + 1) , pos = i;}
                if( l1 + l2 + 1 - i < best ){ best = l1 + l2 + 1 - i , pos = i; }
            }
            r--;
        }
        for(int j = 0 ; j < l1 ; j++)
                cout << p[pos + j];
        cout << "\n";
    }
}

