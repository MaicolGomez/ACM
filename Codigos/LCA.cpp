void dfs( int u , int lvl , int f ){
    L[ u ] = lvl;
    F[ u ] = f;
    for(int i = 0 ; i < adj[ u ].size() ; i++)if( adj[u][i] != f ){
        dfs( adj[ u ][i] , lvl + 1 , u );
    }
}

void init(){
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; (1<<j) < n ; j++)
            M[i][j] = -1;
    
    for(int i = 0 ; i < n ; i++)
        M[i][0] = F[i];
    
    for(int j = 1 ; (1<<j) < n ; j++)
        for(int i = 0 ; i < n ; i++)
            if( M[i][j-1] != -1 )
                M[i][j] = M[ M[i][j-1] ][j-1];
}

int query(int p,int q){
    if( L[p] < L[q] )
        swap( p , q );
    
    int log = 1;
    for(log = 1 ; 1<<log <= L[p] ; log++);
    log--; 
    
    for(int i = log ; i >= 0 ; i--)
        if( L[p] - (1<<i) >= L[q] )
            p = M[p][i];
    
    if( p == q ) return p;
    
    for(int i = log ; i >= 0 ; i--)
        if( M[p][i] != -1 && M[p][i] != M[q][i] )
            p = M[p][i] , q = M[q][i];
    
    return F[p];
}

