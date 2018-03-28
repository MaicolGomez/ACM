#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int x = 0;
	for(int i = 0 ; i < s.size() ; i++)
		x = (10 * x + (s[i] - '0') )%6;
	
	if( x % 3 == 0 )
		printf("0\n");
	else if( x == 1 or x == 4 )
		printf("1\n");
	else printf("2\n");

	return 0;
}
