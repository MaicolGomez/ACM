#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,i,k,a[1001];
	scanf("%d%d",&n,&k);
	for(i = 0 ; i < n ; i++)
		scanf("%d",a+i);
	
	sort( a , a + n );
	reverse( a , a + n );
	
	for(i = k; i < n ; i++){
		if( a[i] != a[i-1] )
			break;
	}
	printf("%d\n",i);
	
	return 0;
}
