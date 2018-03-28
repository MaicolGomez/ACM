#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<stack>
#include<map>
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

vi v;

int n;

bool solve(){
    deque<int> pila;
    /*for(int i = 1 ; i <= 5 ; i++) pila.push_back(i);
    while( !pila.empty() ){
        for(int i = 0 ; i < pila.size() ; i++) cout << pila[i] << " ";
        cout << endl;
        pila.pop_back();
    }*/
    int quede = 0;
    for(int i = 0 ; i < n ; i++){
        int busco = v[i];
        if( busco <= quede ){
            int q = pila.back();
            if( q != busco ) return 0;
            pila.pop_back();
        }
        else{
            for(int j = quede + 1 ; j < busco ; j++) pila.push_back( j );
            quede = busco;
        }
    }
    return 1;
}

int main(){
    while( scanf("%d",&n) == 1 && n ){
        while( 1 ){
            v.resize(n);
            for(int i = 0 ; i < n ; i++){
                scanf("%d",&v[i]);
                if( v[i] == 0 ) goto xx;
            }
            puts(solve()?"Yes":"No");
        }
        xx:;
        printf("\n");
    }
}