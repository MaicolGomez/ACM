#include<cstdio>
#include<map>
using namespace std;
#define N 1000005

int f(int x , int d){
	if(x == 0) return 0;
	if( x < 10 ) return  d?(d<=x):0;
	return (x/10) + (d<=(x%10) ) + ((x%10)+1)*( f(x/10, d) - f( (x/10) - 1 , d) ) - (d==0) + 10*f(x/10 -1 , d);
}

int main(){
	int tc;
	scanf("%d",&tc);
	while( tc-- ){
		int n;
		scanf("%d",&n);
		int ans = 0;
		for (int m = 1; m <= n; m*=10){
			int a = n / m, b = n%m;
			if (a % 10 == 1)ans += b + 1;
			if (a % 10>1)ans += m;
			ans += a / 10 * m;
		}
		printf("%d\n", ans);
		
	}
	return 0;
}
