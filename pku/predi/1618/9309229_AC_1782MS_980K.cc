#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int n , l , m , t[601][101];
vector<string> v;

bool val(int &a , int &b){
    for(int i = 1 ; i < v[a].length() ; i++){
        if( v[a][i] - 'A' >= n ) return 0;
        if( v[a][i] != v[b][i-1] ) return 0;
    }
    return 1;
}

int f(int pos, int tam){
    if(tam==l) return 1;
    int &ret = t[pos][tam];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i = 0 ; i < m ; i++){
        if( val( pos , i ) ) ret += f(i,tam+1);
    }
    return ret;
}

void doit(){
    v.clear();
    memset( t, -1 , sizeof(t) );
    string s;
    for(int i = 0 ; i < m ; i++){
        cin >> s;
        v.push_back(s);
    }
    int res = 0;
    if(l < v[0].length() ) goto xx;
    for(int i = 0 ; i < m ; i++){
        res += f(i , v[i].length() );
    }
    xx:;
    printf("%d\n",res);
}

int main(){
    while( scanf("%d%d%d",&n,&l,&m) == 3 ){
        if( !n && !l && !m ) return 0;
        doit();
    }
}
