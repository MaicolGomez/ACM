#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct nodo{
    long long id , a , b;
        nodo( long long I , long long A , long long B ){
            id = I;
            a = A;
            b = B;
        }
};

bool operator<( nodo X , nodo Y ){
    if( X.b != Y.b ) return X.b < Y.b;
    if( X.a != Y.a ) return X.a < Y.a;
    return X.id < Y.id;
}

long long n , k;
int main(){
    long long a , b;
    vector<nodo> v;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> a >> b;
        v.push_back( nodo( i , a , b) );
    }
    sort( v.begin() , v.end() );
    reverse( v.begin() , v.end() );
    int ct = 0;
    long long pos = -1, maxi = -1 , num = 10000000;
    for(int i = 0 ; i < k ; i++){
        if( v[i].a > maxi ){ maxi = v[i].a;  }
    }
    for(int i = 0 ; i < k ; i++){
        if( v[i].a == maxi ) if( v[i].id < num ) num = v[i].id;
    }
    cout<<num<<endl;
}
