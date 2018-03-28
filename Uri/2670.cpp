#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int x,y,z;
	x = 2*b + 4*c;
	y = 2*a + 2*c;
	z = 4*a + 2*b;
	printf("%d\n",min(x,min(y,z)));
	
	return 0;
}
