#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int m[100001];
long long suma[100001];
long long n , s , a;

long long search( int pos ){
    if( m[pos] >= s ) return 1;
    if( suma[n] - suma[pos-1] < s ) return INT_MAX;
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
    long long mini = INT_MAX;
    for(int i = 1 ; i <= n ; i++){
        mini = min( mini , search( i ) );
        if(mini == 1)break;
    }
    if( mini == INT_MAX ) mini = 0;
    printf("%d\n",mini);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++) doit();
}
