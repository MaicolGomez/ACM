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
#define N 100005

char s[N];
int a[N];

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        scanf("%s",s);
        int n = strlen(s);
        for(int i = 0 ; i < n ; i++)
            a[i] = s[n - i - 1] - '0';
        while( 1 ){
            a[0]++;
            int h = 0;
            while( a[h] >= 10 ){
                if( h == n - 1 )
                    n++;
                a[h] -= 10;
                a[h+1]++;
                h++;
            }
            int S = 0;
            for(int i = 0 ; i < n ; i++)
                S += a[i];
            
            if( S % 10 == 0 ) break;
        }
        for(int i = n - 1 ; i >= 0 ; i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}