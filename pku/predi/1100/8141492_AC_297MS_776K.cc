#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
string s , res;
int sol;
string respuesta;
int espacios, poss[15];

string arregla(string res){
    vector <string> v;
    string ret = "";
    istringstream in(res);
    string r;
    while( in >> r ){
        v.push_back( r );
    }
    ret += v[0];
    for(int i = 1 ; i < v.size() - 1 ; i++){
        if( v[i-1][ v[i-1].length() - 1 ] != '(' && v[i][ 0 ] != ')' ){ ret += " "; espacios++; }
        ret += v[i];
    }
    if( v.size() > 1 ){
        if( v[ v.size() - 1 ][0] != ')'  &&  v[v.size()-2][ v[v.size()-2].length() - 1 ] != '(' ){ ret+= " ";  espacios++;}
    }
    if( v.size() > 1 ) ret += v[v.size() - 1];
    return ret;
}

int parsea( string a ){
    istringstream in(a);
    int t;
    in >> t;
    return t;
}

int f(int ini , int fin){
    int cont1 = 0 , cont2 = 0;
    for(int i = fin ; i >= ini ; i-- ){
        if( s[i] == '(' ) cont1++;
        if( s[i] == ')' ) cont2++;
        if( s[i] == '+' && cont1 == cont2 ) return f(ini , i - 1 ) + f(i+1 , fin);
        if( s[i] == '-' && cont1 == cont2 ) return f(ini , i - 1 ) - f(i+1 , fin);
        if( s[i] == '*' && cont1 == cont2 ) return f(ini , i - 1 ) * f(i+1 , fin);
    }
    if( s[ini] == '(' ) return f(ini+1,fin-1);
    int n=0;
    for(int i=ini;i<=fin;n=n*10+s[i]-'0',++i);
    return n;
}

bool ok = 0;
void combina(int pos){
	if( !ok ){
        if(pos==espacios){
            if(f(0,s.length()-1)==sol){
				cout<<sol<<"="<<s<<endl;
            	ok = 1;
            	return;
            }
        }
        else{
            s[poss[pos]]='+';
            combina(pos+1);                
            s[poss[pos]]='*';
            combina(pos+1);
            s[poss[pos]]='-';
            combina(pos+1);
        }
	}
}

int tot = 0;
int main(){
    while( getline( cin , s ) ){
        if( s == "0" ) break;
        res = "";
        ok = 0;
        for(int i = 0 ; i < s.length() ; i++ ){
            if( s[i] == '=' ){
                string par = "";
                for(int j = 0; j < i  ; j++ ){
                    par += s[j];    
                }
                sol = parsea( par );
                for(int j = i + 1 ; j < s.length() ; j++ ){
                    res += s[j];
                    if( j < s.length() - 1 ){
                        if( s[j] == ')' && s[j+1] == '(' ) res += " ";
                        if( s[j] == ')' && isdigit( s[j+1] ) ) res += " ";
                        if( isdigit(s[j]) && s[j+1] == '(' ) res += " ";
                    }
                }
                break;
            }
        }
        tot++;
        cout<<"Equation #"<<tot<<":"<<"\n";
        res = arregla(res);
        s = res;    
		espacios = 0;
        for(int i = 0; i < s.length() ; i++)if(s[i] == ' '){ poss[espacios] = i; espacios++;}
        combina(0);
        if( !ok ) cout<<"Impossible"<<endl;
        puts("");
    }
}
