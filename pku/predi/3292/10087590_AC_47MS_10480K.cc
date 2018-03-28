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
using namespace std;
#define pi (2.0*acos(0.0))
#define inf (1<<30)
#define me( arr , val ) memset( arr , val , sizeof(arr) );
#define eps 1e-8
#define ll long long
#define vi vector<int> 
#define vll vector<ll>
#define vs vector<string>
#define all(v) v.begin() , v.end()
#define pb push_back
#define N 1000009
int a[N] , t[N];
bool prime[N] , check[N];

void pre(){
    memset( prime , 1 , sizeof(prime) );
    memset( a , 1 , sizeof(a) );
    prime[0] = prime[1] = 0;
    int pos = 0;
    for(ll i = 5 ; i <= N-4 ; i+=4){
        if( prime[i] == 0 ) continue;
        a[pos++] = i;
        for(ll j = 5*i ; j <= N-4 ; j += 4*i ) prime[j] = 0;
    }
    for(int i = 0 ; i < pos ; i++) for(int j = 0 ; j < i +1 ; j++){
        if( a[i]*a[j] >= N ) break;
        check[a[i]*a[j]] = 1;
    }
    for(int i = 0 ; i <= N ; i++) t[i+1] = t[i] + check[i+1];
}

int main(){
    pre();
    int x;
    while( scanf("%d",&x) == 1 && x ){
        printf("%d %d\n",x ,t[x]);
    }
}