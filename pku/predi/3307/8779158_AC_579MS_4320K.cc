#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<iostream>
#define UP 1000000000000000000LL
using namespace std;
set<long long>s;
set<long long>::iterator it;


void genera(){
	for(long long i=1;i<=UP;i*=2){
		for(long long j=1;j*i<=UP;j*=3){
			for(long long k=1;i*j*k<=UP;k*=5){
				for(long long q=1;i*j*k*q<=UP;q*=7){
					s.insert(i*j*k*q);
				}
			}
		}
	}
}

int main(){
	int t;
	genera();
	vector<long long>v(s.begin(),s.end());
	long long x;
	scanf("%d",&t);
	for(int i=0;i<t;++i){
		scanf("%lld",&x);
		printf("%lld\n",v[x-1]);
	}
}
