#include<deque>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

int f[2005] , g[2005] , h[2005] , coef[2005] , maxi;
int aux[2005];
int a,b,c,;


void solve(){
    memset(coef,0,sizeof(coef));
    for(int i = 0 ; i <= a ; i++){
        for(int j = 0 ; j <= b ; j++){
            if( f[i]==1 && g[j]==1 )coef[i+j]++;
        }
    }
    for(int i = 0 ; i <= a+b ; i++){
        coef[i] %= 2;
        if(coef[i]) maxi = i;
    }
    /*for(int i = 0 ; i <= maxi ; i++){
        cout<<" exp: "<<i<<" "<<coef[i]<<" ";
    }*/
    while( maxi >= c ){
        memset(aux , 0 , sizeof(aux));
        int exp = maxi - c;
        for(int i = 0 ; i <= c ; i++) aux[i+exp] = h[i];
        /*for(int i = 0 ; i <= c+exp ; i++){
            cout<<" exp: "<<i<<" "<<aux[i]<<" ";
        }
        cout<<endl;*/
        //cout<<"maxi: "<<maxi<<endl;
        int val = 0;
        for(int i = 0 ; i <= maxi ; i++){
            //cout<<" exp: "<<i<<" "<<coef[i]<<" "<<aux[i]<<endl;
            coef[i] = (coef[i] + aux[i])%2;
            if(coef[i]==1) val = i;
        }
        maxi = val;
        //cout<<maxi<<endl;
        /*for(int i = 0 ; i <= maxi ; i++){
            cout<<" exp: "<<i<<" "<<coef[i]<<" ";
        }*/
    }
    cout<<maxi+1;
    for(int i = maxi ; i >= 0 ; i--){
        cout<<" "<<coef[i];
    }
    cout<<endl;
}

void doit(){
    scanf("%d",&a);
    a--;
    for(int i = a ; i >= 0 ; i--){
        scanf("%d",&f[i]);
    }
    scanf("%d",&b);
    b--;
    for(int i = b ; i >= 0 ; i--){
        scanf("%d",&g[i]);
    }
    scanf("%d",&c);
    c--;
    for(int i = c ; i >= 0 ; i--){
        scanf("%d",&h[i]);
    }
    solve();
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i< t; i++) doit();
}
