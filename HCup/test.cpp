#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

#define N 20

int n, T, caso;

double dp[N + 5];


int C[N + 5][N + 5];


double p;

double pow[N + 5], pow_com[N + 5];


double f(int count){

	if(count >= N)return 0;

	double &ret = dp[count];

	if(ret > - 0.5) return ret;

	double ans = 1.0;

	int n = N - count;
	
	for(int i = 1; i <= n; ++i){
		double aux = f(count + i);
		ans = ans +  aux * pow[i] * pow_com[n - i] * C[n][i];
	}

	ans /= (1.0 - pow_com[n]);

	return ret = ans;

	
}

void doCase(){
	scanf("%lf", &p);

	pow[0] = 1.0;
	
	for(int i = 1; i <= N; ++i)pow[i] = pow[i - 1] * p;

	pow_com[0] = 1.0;
	
	for(int i = 1; i <= N; ++i)pow_com[i] = pow_com[i - 1] * (1.0 - p);

	for(int i = 0; i <= N; ++i)dp[i] = -1.0;

	double ans = f(0);

	printf("Case #%d: %.5lf\n", ++caso, ans);

}

void combinatory(){

	for(int i = 0; i <= N ; ++i)C[i][0] = 1;

	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= i; ++j)C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
}

int main(){

	combinatory();

	caso = 0;
	
	scanf("%d", &T);
	for(int i = 0; i < T; ++i)doCase();

		
}
