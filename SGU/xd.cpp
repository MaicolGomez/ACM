#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<deque>
#include<queue>
#include<map>
#include<climits>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf (1<<29)
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define MAXN 200005
#define BASE 27
int min(int a, int b){
	return a < b ? a : b;
}

char str[2][MAXN];
unsigned long long int hash[2][MAXN];
unsigned long long int bpow[MAXN];

int N, M;

#define getHash(h,a,b) (a ? (h[(b)] - h[(a)-1] * bpow[(b)-(a)+1]) : h[(b)])

int firstDiffChar(char *a, int aoff, char *b, int boff, unsigned long long int *h1, unsigned long long int *h2, int n){
	int lo = 0, hi = n, mid;

	while (lo < hi){
		mid = (lo + hi) / 2;
		if (getHash(h1, aoff, mid + aoff) != getHash(h2, boff, mid + boff))
			hi = mid;
		else
			lo = mid + 1;
	}

	return hi;
}

int hstrncmp(char *a, int aoff, char *b, int boff, unsigned long long int *h1, unsigned long long int *h2, int n){
	int d = firstDiffChar(a, aoff, b, boff, h1, h2, n);
	return d < n ? a[aoff + d] - b[boff + d] : 0;
}

void getHashes(char *str, unsigned long long int *hash, int len){
	int i;

	for (i = 0; i < len; i++)
		hash[i] = (i > 0 ? hash[i-1] : 0) * BASE + str[i] - 'A';
}

int getLeastLex(void){
	int i, best = 0;

	for (i = 1; i < M; i++)
		if (hstrncmp(str[1], best, str[1], i, hash[1], hash[1], M) > 0)
			best = i;

	return best;
}

int main(void){
	int i, best = -1, d;

	while( scanf("%d %d", &N, &M) == 2 ){

	scanf("%s", str[0]);
	scanf("%s", str[1]);

	bpow[0] = 1;
	for (i = 1; i <= N*2; i++)
		bpow[i] = bpow[i-1] * BASE;

	strncpy(str[0] + N, str[0], N);
	strncpy(str[1] + M, str[1], M);

	getHashes(str[0], hash[0], N*2);
	getHashes(str[1], hash[1], M*2);

	int leastLex = getLeastLex();

	for (i = 0; i < M; i++)
		putchar(str[1][leastLex + i]);
	putchar('\n');

	for (i = 0; i < N; i++){
		d = firstDiffChar(str[1], leastLex, str[0], i, hash[1], hash[0], M);
		if (d >= M - 1 || getHash(hash[1], leastLex + d + 1, leastLex + M - 1) == getHash(hash[0], i + d + 1, i + M - 1)){
			best = i;
			break;
		}

		d = firstDiffChar(str[1], leastLex, str[0], N - i, hash[1], hash[0], M);
		if (d >= M - 1 || getHash(hash[1], leastLex + d + 1, leastLex + M - 1) == getHash(hash[0], N - i + d + 1, N - i + M - 1)){
			best = N - i;
			break;
		}
	}

	for (i = 0; i < N; i++)
		putchar(str[0][best + i]);
	putchar('\n');
	
    }
	return 0;
}
