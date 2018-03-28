#include<vector>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

struct nodo{
    string x , y , z;
        nodo(string X , string Y , string Z){
            x = X , y = Y , z = Z;
        }
};

vector<string> v;
vector<nodo> sol;

bool f(char a, char b , char c){
    if(a==b&&b==c) return 1;
    if(a!=b&&b!=c&&a!=c) return 1;
    return 0;
}

void doit(){
    sol.clear();
    for(int i = 0 ; i < v.size() ; i++)
        for(int j = i+1 ; j < v.size() ; j++)
            for(int k = j + 1 ; k < v.size() ; k++){
                string a = v[i] , b = v[j] , c = v[k];
                if( f(a[0],b[0],c[0]) && f(a[1],b[1],c[1]) && f(a[2],b[2],c[2]) && f(a[3],b[3],c[3]) ) sol.push_back(nodo(v[i],v[j],v[k]));
            }
        
    printf("CARDS: ");
    for(int i = 0 ; i < v.size() ; i++) cout<<" "<<v[i];
    puts("");
    printf("SETS:   ");
    if(sol.size()==0) puts("*** None Found ***");
    else{
        for(int i = 0 ; i < sol.size() ; i++){
            if(i==0) cout<<i+1<<".  "<<sol[i].x<<" "<<sol[i].y<<" "<<sol[i].z<<"\n";
            else cout<<"        "<<i+1<<".  "<<sol[i].x<<" "<<sol[i].y<<" "<<sol[i].z<<"\n";
        }
    }
             
}

int main(){
    int cont = 0;
    string s;
    while(cin>>s){
        cont++;
        v.push_back(s);
        if(cont==12){
            cont = 0;
            doit();
            puts("");
            v.clear();
        }
    }
}
