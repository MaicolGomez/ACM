#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

long long m[100001];
long long suma[100001];
long long n , s , a;

long long search( int pos ){
    if( m[pos] >= s ) return 1;
    if( suma[n] - suma[pos-1] < s ) return 1000000000;
    int low = pos;
    int high = n;
    while( high - low > 1 ){
        int mid = (high + low)/2;
        if( suma[mid] - suma[pos-1] < s ){
            low = mid;
        }
        if( suma[mid] - suma[pos-1] >= s ){
            high = mid;
        }
    }
    return high-pos+1;
}

void doit(){
    suma[0] = 0;
    cin >> n >> s;
    for(int i = 1 ; i <= n ; i++){
        cin >> a;
        m[i] = a;
        suma[i] = suma[i-1] + a;
    }
    long long mini = 1000000000;
    for(int i = 1 ; i <= n ; i++){
        mini = min( mini , search( i ) );
        if(mini == 1)break;
    }
    if( mini == 1000000000 ) mini = 0;
    cout<<mini<<endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i++) doit();
}
