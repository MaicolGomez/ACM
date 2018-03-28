#include<iostream>
#include<vector>
using namespace std;
bool primo(int n){
    if(n == 2) return true;
    if(n == 3) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i * i <= n ; i += 2 ){
        if( n % i == 0) return false;    
    }
    return true;
}
vector <int> v;
vector <int> res;
int n , c;
void todo(){
    for(int i = 0 ; i < res.size() ; i++){
        printf(" %d",res[i] );
    }
    cout<<"\n";    
}
void imprime(){
    cout<<res.size()<<endl;
    printf("%d %d:",n,c);
    if( int(res.size()) % 2 == 0 ){     
        if( 2 * c >= int( res.size() ) ){ todo(); return; }
        for(int i = res.size()/2 - c ; i < res.size()/2 + c ; i++ ){
            printf(" %d",res[i] );
        }
        cout<<"\n";
        return;
    }
    if( 2 * c - 1 >= res.size() ){ todo(); return; }
    for(int i = (res.size()- 1)/2 - c + 1 ; i <= (res.size()- 1)/2 + c - 1 ; i++ ){
        printf(" %d",res[i] );
    }
    cout<<"\n";
}

int main(){
    v.push_back(1);
    for(int i = 2; i < 1001 ;i++){
        if( primo(i) ) v.push_back( i );    
    }
    while( scanf("%d%d" ,&n , &c) == 2 ){
        res.clear();
        for(int i = 0 ; i < v.size() ; i++){
            if( n >= v[i] ) res.push_back( v[i] );
            else break;
        }
        imprime();
        cout<<"\n"; 
    }
}
