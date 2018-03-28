#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<string>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-8
#define ll long long

int n , k;
bool val[1005];
void doit(){
    int x;
    cin >> x;
    vector<int> v(2*x);
    for(int i = 0 ; i < 2* x ; i++){
        cin >> v[i];
    }
    char p;
    cin >> p;
    for(int i = 0 ; i < x ; i++){
        if( p == '=' ) val[ v[i] ] = 0;
        if( p == '<' ) val[ v[i] ] = 0;
    }
    for(int i = x ; i < 2*x ; i++){
        if( p == '=' ) val[ v[i] ] = 0;
        if( p == '>' ) val[ v[i] ] = 0;
    }
}

int main(){
    cin >> n >> k;
    memset( val , 1 , sizeof(val) );
    for(int i = 0 ; i < k ; i++) doit();
    int ct = 0 , res;
    for(int i = 1 ; i <= n ; i++) if(val[i]) ct++ , res = i;
    printf("%d\n",ct==1?res:0);
}