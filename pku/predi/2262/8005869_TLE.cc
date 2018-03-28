#include<sstream>
#include<iostream>
#include<deque>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct nodo{
    int a , b , dif;
        nodo( int A , int B , int Dif ){
            a = A;
            b = B;
            dif = Dif;
        }
};

bool operator <(nodo A , nodo B){
    return A.dif < B.dif;        
}

vector <int> v;
bool primo(int n){
    if(n == 2) return true;
    if(n == 3) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i * i <= n ; i += 2 ){
        if( n % i == 0) return false;    
    }
    return true;
}

void f(){
    for(int i = 2 ; i <= 1000000 ; i++){
        if( primo(i) ) v.push_back(i);
    }
}

void doit(int n){
    int cont = 0;
    priority_queue <nodo> Q;
    for(int i = 0 ; i < v.size() ; i++ ){
        if( v[i] >= n ) break;
        if( binary_search(v.begin(), v.end(), n - v[i] ) == 1){
            int temp = lower_bound( v.begin(), v.end(), n - v[i] )-v.begin();
            Q.push( nodo( v[i] , v[temp] , abs(v[temp] - v[i]) ) );   
        }
    }
    if( Q.size() == 0 ) {printf("Goldbach's conjecture is wrong.\n");return;}
    nodo q = Q.top();
    int minimo = min( q.a , q.b );
    int resto = q.a + q.b - minimo;
    printf("%d = %d + %d\n",n , minimo , resto);
}

int main(){
    f();
    int n;
    /*int tam = v.size();
    printf("%d\n",tam);*/
    while( scanf("%d",&n) ){
        if( n == 0 ) break;
        doit(n);    
    }
}
