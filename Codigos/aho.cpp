
//Aho Corasick -- term[] depende del problema actualizarlo 
int next[N][27] , T[N] , term[N] , fa[N] , node;

void add(char *s){
    int ac = 0;
    int l = strlen(s);
    for(int i = 0 ; i < l ; i++){
        if( next[ac][s[i] - 'a'] == 0 ) me(next[node],0), next[ac][s[i] - 'a'] = node++;
        fa[next[ac][s[i] - 'a']] = ac;
        ac = next[ac][s[i]- 'a'];
    }
    term[ac] = 1;
}

void aho(){
    queue<int> Q;
    for(int i = 0 ; i < 26 ; i++){
        int v = next[0][i];
        if( v ) T[v] = 0, Q.push(v);
    }
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        for(int i = 0 ; i < 26 ; i++){
            int v = next[u][i] , x = next[T[u]][i];
            if( v == 0 ) next[u][i] = x;
            else Q.push(v) , T[v] = x;//, term[v] |= term[x];
        }
    }
}
