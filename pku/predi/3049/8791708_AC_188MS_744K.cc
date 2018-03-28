#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int total;
vector<char> v;
map<char , bool> m;
void f(string s, int voc , int con){
    if( s.length() == total ){
        if( voc >= 1 && con >=2 ) cout<<s<<endl;
        return;
    }
    for(int i = 0 ; i < v.size() ; i++){
        bool ok = 1;
        if( char(v[i]) <= char(s[s.length()-1]) ) continue;
        if( m.find(v[i]) != m.end() ) voc++;
        else{ con++; ok = 0; }
        string cad = s;
        cad += v[i];
        f( cad , voc , con );
        if( ok ) voc--;
        else con--;
    }
}

int main(){
    m['a'] = 1;
    m['e'] = 1;
    m['i'] = 1;
    m['o'] = 1;
    m['u'] = 1;
    int t;
    char p;
    scanf("%d%d",&total,&t);
    for(int i = 0 ; i < t ; i++){
        cin >> p;
        v.push_back(p);
    }
    sort( v.begin() , v.end() );
    for(int i = 0 ; i < v.size() ; i++){
        string sol = "";
        sol += v[i];
        int voc = 0 , con = 0;
        if( m.find(v[i]) != m.end() ) voc++;
        else con++;
        f( sol , voc , con );
    }
}
