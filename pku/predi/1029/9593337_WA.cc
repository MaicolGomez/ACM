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

int n , k , t = 0;
int val[1005];
void doit(){
    int x;
    cin >> x;
    vector<int> v(2*x);
    for(int i = 0 ; i < 2*x ; i++){
        cin >> v[i];
    }
    char p;
    cin >> p;
    for(int i = 0 ; i < x ; i++){
        if( p == '=' ) val[ v[i] ] = 1;
        if( p == '<' ) val[ v[i] ]-- , t++;
        if( p == '>' ) val[ v[i] ]++ , t++;
    }
    for(int i = x ; i < 2*x ; i++){
        if( p == '=' ) val[ v[i] ] = 1;
        if( p == '>' ) val[ v[i] ]--;
        if( p == '<' ) val[ v[i] ]++;
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0 ; i < k ; i++) doit();
    int ct = 0 , res;
    for(int i = 1 ; i <= n ; i++) if( val[i] == t || val[i] == -t ) ct++ , res = i;
    if( ct != 1 ) res = 0;
    printf("%d\n",res);
}