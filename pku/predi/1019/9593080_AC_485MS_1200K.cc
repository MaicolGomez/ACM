#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<string>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-8

long long len[31270] , A[31270];

long long tam(int x){
    long long ct = 0;
    while(x>0){ ct++; x/=10; }
    return ct;
}

void proc(){
    for(int i = 1 ; i <= 31268 ; i++){
        len[i] = len[i-1] + tam(i);
    }
    for(int i = 1 ; i <= 31268 ; i++){
        A[i] = A[i-1] + len[i];
    }
}

int search(int n){
    int low = 1 , high = 31268;
    while(low < high){
        int mid = low + (high-low)/2;
        if( n <= A[mid] ) high = mid;
        else low = mid+1;
    }
    return low;
}

char busca(int n){
    int ct = 0,a;
    for(int i = 1 ; ; i++){
        int y = i;
        string s = "";
        while(y>0){
            s+= y%10 + '0';
            y/=10;
        }
        //cout<<s<<endl;
        for(int j = s.length()-1 ; j >= 0 ; j--){
            ct++;
            if(ct==n) return s[j];
        }
    }
}

void doit(){
    int n;
    scanf("%d",&n);
    int r = search(n);
    if( n - A[r] <=0 ) r--;
    //cout<<r<<endl;
    int queda = n - A[r];
    printf("%c\n",busca(queda));
}

int main(){
    proc();
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++) doit();
}