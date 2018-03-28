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
#define MOD 10009
#define N 2005

string A[20];

string parsea(string s){

    for(int i = 0 ; i + 2 < s.size() ; i++){
        string x = "";
        x += s[i]; x += s[i+1]; x += s[i+2];
        if( x == "(N)" ){
            int r = i+3;
            while( r < s.size() && ( !isdigit(s[r]) && s[r] < 'A' || s[r] > 'Z' ) ) s[r++] = ' ';
        }
    }
    return s;
}

int main(){
    string s;
    while( getline(cin,s)  ){
        s = parsea(s);
        stringstream in(s);
        int n = 0 , k = 0;
        while( in >> A[n] ){
            if( A[n++].find("(") != -1 ) k++;
        }
        int c = 4;
        if( 4 + k == n ) c = 3;
        for(int i = 0 ; i < k ; i++){
                for(int j = 0 ; j < c ; j++)
                    cout << A[j] << " ";
                cout << A[c + i].substr(0,6) << " ";
                cout << A[n-1] << endl;
        }
    }
    return 0;
}
