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
#define MOD 10009
#define N 1005

int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , 1 , -1 };

string a[15];

int main(){
    string x = "xxx";
    for(int i = 0 ; i < 7 ; i++){
        getline( cin , a[i] );
        string k = "";
        for(int j = 0 ; j < a[i].size() ; j++)
            if( a[i][j] != ' ' ) k += a[i][j];
        if( i < 2 || i > 4 ) a[i] = "   " + k + "   ";
    }
    int r = 7 , c = 7 , ans = 0;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            if (a[i][j] == '.'){
                if (a[i][j + 1] == 'o' && a[i][j + 2] == 'o') ans++; 
                if ( j >= 2 && a[i][j - 1] == 'o' && a[i][j - 2] == 'o') ans++; 
                if ( i >= 2 && a[i - 1][j] == 'o' && a[i - 2][j] == 'o') ans++;
                if (a[i + 1][j] == 'o' && a[i + 2][j] == 'o') ans++;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
