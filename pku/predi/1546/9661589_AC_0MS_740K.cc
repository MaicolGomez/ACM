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

string s;
ll x , y;

ll toint(string ss , int basee){
    ll xx = 0 , pott = 1;
    //reverse( ss.begin() , ss.end() );
    for(int i = 0 ; i < ss.length() ; i++){
        if( ss[i] <= '9' && ss[i] >= '0'  ) xx = xx + (ss[i]-'0') * pott;
        else xx = xx + ( ss[i]-'A'+10 ) * pott;
        pott *= basee;
    }
    return xx;
}

string tostring(ll numm , int basee){
    string res = "";
    while( numm > 0 ){
        if( numm % basee > 9 ) res += ('A' + numm % basee - 10 );
        else res += numm%basee + '0';
        numm /= basee;
    }
    reverse( res.begin() , res.end() );
    return res;
}

string doit(){
    reverse( s.begin() , s.end() );
    ll num = toint( s , x );
    //cout<<"num: "<<num<<endl;
    string res = tostring( num , y );
    if( res.length() > 7 ) return "  ERROR";
    for(int i = res.length() ; i < 7 ; i++) cout<<" ";
    return res;
}

int main(){
    while( cin >> s >> x >> y ){
        cout<<doit()<<endl;
    }
}