#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<queue>
#include<stack>

using namespace std;

#define inf (1<<29)
#define ll long long
#define eps 1e-7
#define vi vector<int>
#define all(v) v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define Q(x) (x)*(x)
#define N 10000000

int prime[N+5];
ll a[N+5];

int main(){
    
    for(int i = 2 ; i <= N ; i++)
        prime[i] = i;
    
    for(int i = 2 ; i*i <= N ; i++)
        if( prime[i] == i )
            for(int j = i*i ; j < N + 1 ; j+=i)
                if( prime[j] == j ) prime[j] = i;
    
    a[0] = a[1] = 0;
    
    for(int i = 2 ; i < N + 1 ; i++)
        a[i] = a[i-1] + prime[i];
    
    int n , tc;
    sc(tc);
    while(tc--){
        sc(n);
        cout << a[n] << "\n";
    }
}

