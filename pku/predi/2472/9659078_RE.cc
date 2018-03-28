#include<iostream>
#include<cmath>
#include<deque>
#include<cstdio>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
#include<cstdlib>
using namespace std;
#define ll long long
#define eps 1e-6

int n , m;
double val[105][105];
vector<int> adj[105];

double bfs(){
    double pro[105];
    for(int i = 1; i <= n ; i++) pro[i] = -1.0;
    deque<int> Q(1 , 1);
    pro[1] = 1.0;
    while( !Q.empty() ){
        int q = Q.front();
        Q.pop_front();
        vector<int> v = adj[q];
        for(int i = 0 ; i < v.size() ; i++){
            int vec = v[i];
            if( pro[q] * val[q][vec] > pro[vec] * 100.0 + eps ){
                pro[vec] = ( val[q][vec] * pro[q] ) / 100.0;
                Q.push_back(vec);
            }
        }
    }
    return pro[n];
}

int main(){
    int a, b;
    while( cin >> n ){
        if( n == 0 ) break;
        cin >> m;
        for(int i = 0 ; i <= n ; i++) adj[i].clear();
        for(int i = 0 ; i < m ; i++){
            cin >> a >> b >> val[a][b];
            //cout<< a << " " << b << " " << val[a][b]<<endl;
            adj[a].push_back(b);
            adj[b].push_back(a);
            val[b][a] = val[a][b];
        }
        printf("%.6lf percent\n", bfs()*100.0 );
    }
}
