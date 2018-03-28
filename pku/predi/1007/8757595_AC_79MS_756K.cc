#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

struct nodo{
    string s;
    int sum;
        nodo(string S ,int Sum ){
            s = S;
            sum = Sum;
        }
};

bool operator<(nodo A , nodo B){
    if( A.sum != B.sum ) return A.sum < B.sum;
    return 1;
}

int cal(int pos , string ss){
    int ct = 0;
    for(int i = pos +1 ; i < ss.length() ; i++){
        if( ss[pos] > ss[i] ) ct++;
    }
    return ct;
}

int main(){
    int n , k;
    scanf("%d%d",&k,&n);
    vector<nodo> v;
    string ss;
    for(int i = 0 ; i < n ; i++){
        cin >> ss;
        int suma = 0;
        for(int j = 0 ; j < ss.length() ; j++){
            suma += cal( j , ss );
        }
        v.push_back( nodo( ss , suma ) );
    }
    sort( v.begin() , v.end() );
    for(int i = 0 ; i < v.size() ; i++) cout<<v[i].s<<endl;
}