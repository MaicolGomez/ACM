#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

double v,r,c,w;
int n;

int main(){
    cin>>v>>r>>c;
    cin>>n;
    for(int i = 0;i < n ; i++){
        cin >> w;
        double res = v/sqrt( r*r+1.0/(w*w*c*c) );
        printf("%.3lf\n",res);
    }
}
