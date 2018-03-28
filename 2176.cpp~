#include<cstdio>
using namespace std;
#define N 200000
#define sc(x) scanf("%d",&x)

int a[N];

int main(){
	int tc;
	sc(tc);
	while( tc-- ){
		int n;
		sc(n);
		int S = 0 , ans = 0 , p = 0 , C;
		for(int i = 0 ; i < n ; i++)
			sc(a[i]);
		sc(C);
		for(int i = 0 ; i < n ; i++){
			S += a[i];
			if( S >= C ){				
				while( S >= C ){
					ans += (S == C);
					S -= a[p++];
				}
			}
		}
		printf("%d\n",ans);
	}
}
