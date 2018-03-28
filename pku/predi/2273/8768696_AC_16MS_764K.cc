#include<iostream>
#include<cmath>
#include<cctype>
#include<deque>
#include<cstdio>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int a[100],num;

string doit(int n){
    int k = n;
    num = 0;
    while( n > 0){        
        int m  = n % 26;
        if(m == 0){
            a[num] = 26;
            n /=26;
            n--;
        }
        else{ a[num] = m; n /=26;}
        num++;      
    } 
    string s1="";
    for(int i = num -1 ; i >= 0 ; i--){
        s1 += 'A' - 1 + a[i];
    }
    return s1;
}

int main(){
    string s;
    while(cin>>s){
        if( s == "R0C0" ) break;    
        for(int i = 0 ; i < s.length() ; i++){
            if( s[i] == 'R' || s[i] == 'C') s[i] = ' '; 
        }
        istringstream in( s );
        int x;
        vector <int> v;
        while( in >> x){
            v.push_back(x);    
        }
        int k = v[1];
        s = doit(k);
        cout<<s<<v[0]<<endl;
    }   
}
