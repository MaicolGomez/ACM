#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<string>
#include<map>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-8
#define ll long long

int n , target , a[15];

void doit(){
    printf("Sums of %d:\n", target );
    int tot = 0;
    vector<int> adj[5000];
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < (1<<n) ; i++){
        int suma = 0;
        vector<int> v;
        for(int j = 0 ; j < n; j++){
            if( i & (1<<j) ) suma += a[j] , v.push_back( a[j] );
        }
        if( suma == target ){
            sort( v.begin() , v.end() );
            reverse( v.begin() , v.end() );
            for(int j = 0 ; j < tot ; j++){
                if( adj[j] == v ) goto x;
            }
            adj[tot++] = v;
            x:;
        }
    }
    if( tot == 0 ) puts("NONE");
    else{
        sort( adj , adj + tot );
        reverse( adj , adj + tot );
        for(int i = 0 ; i < tot ; i++){
            printf("%d", adj[i][0] );
            for(int j = 1 ; j < adj[i].size() ; j++)
                printf("+%d",adj[i][j]);
            puts("");
        }
    }
}

int main(){
    while( cin >> target >> n ){
        if( n == 0 && target == 0 ) break;
        doit();
    }
}