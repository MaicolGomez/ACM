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
#define ios ios::sync_with_stdio(0);
#define N 100001

int main(){
    int a , b;
    while( cin >> a >> b ){
        if( b == 1 ) cout <<"infinity\n";
        else if( a == 1 ){
            if( b == 2 ) cout << "2/1\n";
            if( b == 3 ) cout << "3/4\n";
            if( b == 4 ) cout << "irrational\n";
            if( b == 5 ) cout << "5/16\n";
            if( b == 6 ) cout << "6/25\n";
            if( b == 7 ) cout << "7/36\n";
            if( b == 8 ) cout << "irrational\n";
            if( b == 9 ) cout << "9/64\n";
            if( b == 10 ) cout << "10/81\n";
        }
        else if( a == 2 ){
            if( b == 2 ) cout << "6/1\n";
            if( b == 3 ) cout << "3/2\n";
            if( b == 4 ) cout << "irrational\n";
            if( b == 5 ) cout << "15/32\n";
            if( b == 6 ) cout << "42/125\n";
            if( b == 7 ) cout << "irrational\n";
            if( b == 8 ) cout << "irrational\n";
            if( b == 9 ) cout << "45/256\n";
            if( b == 10 ) cout << "irrational\n";
        }
        else if( a == 3 ){
            if( b == 2 ) cout << "26/1\n";
            if( b == 3 ) cout << "33/8\n";
            if( b == 4 ) cout << "irrational\n";
            if( b == 5 ) cout << "115/128\n";
            if( b == 6 ) cout << "366/625\n";
            if( b == 7 ) cout << "irrational\n";
            if( b == 8 ) cout << "irrational\n";
            if( b == 9 ) cout << "531/2048\n";
            if( b == 10 ) cout << "irrational\n";
        }
        else if( a == 4 ){
            if( b == 2 ) cout << "150/1\n";
            if( b == 3 ) cout << "15/1\n";
            if( b == 4 ) cout << "irrational\n";
            if( b == 5 ) cout << "285/128\n";
            if( b == 6 ) cout << "4074/3125\n";
            if( b == 7 ) cout << "irrational\n";
            if( b == 8 ) cout << "irrational\n";
            if( b == 9 ) cout << "1935/4096\n";
            if( b == 10 ) cout << "irrational\n";
        }
        else if( a == 5 ){
            if( b == 2 ) cout << "1082/1\n";
            if( b == 3 ) cout << "273/4\n";
            if( b == 4 ) cout << "irrational\n";
            if( b == 5 ) cout << "3535/512\n";
            if( b == 6 ) cout << "11334/3125\n";
            if( b == 7 ) cout << "irrational\n";
            if( b == 8 ) cout << "irrational\n";
            if( b == 9 ) cout << "34938/32768\n";
            if( b == 10 ) cout << "irrational\n";
        }
        else if( a == 6 ){
            if( b == 2 ) cout << "9366/1\n";
            if( b == 3 ) cout << "1491/4\n";
            if( b == 4 ) cout << "irrational\n";
            if( b == 5 ) cout << "26355/1024\n";
            if( b == 6 ) cout << "189714/15625\n";
            if( b == 7 ) cout << "irrational\n";
            if( b == 8 ) cout << "irrational\n";
            if( b == 9 ) cout << "381465/131072\n";
            if( b == 10 ) cout << "irrational\n";
        }
        else if( a == 7 ){
            if( b == 2 ) cout << "94586/1\n";
            if( b == 3 ) cout << "38001/16\n";
            if( b == 4 ) cout << "irrational\n";
            if( b == 5 ) cout << "458555/4096\n";
            if( b == 6 ) cout << "3706518/78125\n";
            if( b == 7 ) cout << "irrational\n";
            if( b == 8 ) cout << "irrational\n";
            if( b == 9 ) cout << "9725787/1048576\n";
            if( b == 10 ) cout << "irrational\n";
        }
        else if( a == 8 ){
            if( b == 2 ) cout << "1091670/1\n";
            if( b == 3 ) cout << "17295/1\n";
            if( b == 4 ) cout << "irrational\n";
            if( b == 5 ) cout << "1139685/2048\n";
            if( b == 6 ) cout << "82749954/390625\n";
            if( b == 7 ) cout << "irrational\n";
            if( b == 8 ) cout << "irrational\n";
            if( b == 9 ) cout << "35420535/1048576\n";
            if( b == 10 ) cout << "irrational\n";
        }
        else if( a == 9 ){
            if( b == 2 ) cout << "14174522/1\n";
            if( b == 3 ) cout << "566733/4\n";
            if( b == 4 ) cout << "irrational\n";
            if( b == 5 ) cout << "25492435/8192\n";
            if( b == 6 ) cout << "2078250726/1953125\n";
            if( b == 7 ) cout << "irrational\n";
            if( b == 8 ) cout << "irrational\n";
            if( b == 9 ) cout << "1160703963/8388608\n";
            if( b == 10 ) cout << "irrational\n";
        }
        else if( a == 10 ){
            if( b == 2 ) cout << "204495126/1\n";
            if( b == 3 ) cout << "2579313/2\n";
            if( b == 4 ) cout << "irrational\n";
            if( b == 5 ) cout << "316786305/16384\n";
            if( b == 6 ) cout << "11598884682/1953125\n";
            if( b == 7 ) cout << "irrational\n";
            if( b == 8 ) cout << "irrational\n";
            if( b == 9 ) cout << "21129845715/33554432\n";
            if( b == 10 ) cout << "irrational\n";
        }
    }
    return 0;
}
