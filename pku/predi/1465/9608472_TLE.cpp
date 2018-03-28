#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
#define inf (1<<30)
#define eps 1e-8
#define ll long long

struct nodo{
    int mod;
    string s;
        nodo( int Mod , string S){
            mod = Mod;
            s = S;
        }
};

int mod , n , a[11];
bool vis[5005];

string f(){
    memset( vis , 0 , sizeof(vis) );
    deque<nodo> Q;
    Q.push_back( nodo(0,"") );
    while( !Q.empty() ){
        nodo q = Q.front();
        Q.pop_front();
        //cout<<"papa : "<<q.s<<endl;
        for(int i = 0 ; i < n ; i++){
            if( vis[ (q.mod *10 + a[i] )%mod ] ) continue;
            string x = q.s;
            x += (a[i] + '0');
            //cout<<"creada: "<<x<<endl;
            if( (q.mod *10 + a[i])%mod == 0 && x[0] != '0' ) return x;
            if( x[0] != '0' ) vis[ (q.mod *10 + a[i] )%mod ] = 1;
            Q.push_back( nodo( (q.mod *10 + a[i] )%mod , x ) );
        }
    }
    return "0";
}

int main(){
    while( cin >> mod ){
        cin >> n;
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        sort(a , a + n);
        if(mod==0 || n == 0){
            cout<<"0"<<endl;
        }
        else cout<<f()<<endl;
        string s;
        getline(cin , s); getline(cin, s);
        //cout<<mod<<endl;
        //cout<<mod<<endl;
        //cout<<f()<<endl;
    }
}