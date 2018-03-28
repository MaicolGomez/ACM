#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<deque>
#include<map>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pii (2.0*acos(0.0))
#define inf (1<<30)
#define eps 1e-8
#define ll long long
#define vi vector<int> 
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define N 1005
string a , b;
int n1 , n2;
int t[N][N];

int f(int x,int y){
    if( x == n1 ) return n2 - y;
    if( y == n2 ) return n1 - x;
    int &ret = t[x][y];
    if( ret != -1 ) return ret;
    ret = inf;
    if( a[x] == b[y] ) ret = f(x+1,y+1);
    if( a[x] != b[y] ) ret = min( ret , 1 + f(x+1,y+1) );
    ret = min( ret , 1 + f(x+1,y) );
    ret = min( ret , 1 + f(x,y+1) );
    return ret;
}

int main(){
    while( cin >> n1 >> a >> n2 >> b){
        //cin >> n1 >> a >> n2 >> b;
        me(t,-1);
        cout << f(0,0) << endl;
    }
}