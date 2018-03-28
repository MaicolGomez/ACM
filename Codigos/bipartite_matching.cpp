#define MAX_V1 301
#define MAX_V2 501
#define MAX_E 65536
  
int V1,V2,l[MAX_V1],r[MAX_V2]; 
int E,to[MAX_E],next[MAX_E],last[MAX_V1]; 
bool visited[MAX_V1];
 
void init(){ 
    memset(last,-1,sizeof(int)*V1); 
    E = 0; 
} 
   
void add_edge(int u, int v){ 
    to[E] = v, next[E] = last[u]; last[u] = E; ++E; 
}

bool pairup(int u){ 
    if (visited[u])  return false; 
    visited[u] = true; 
      
    for(int e = last[u];e!=-1;e = next[e]){ 
        int v = to[e]; 
          
        if(r[v]==-1 || pairup(r[v])){ 
            l[u] = v; 
            r[v] = u; 
            return true; 
        } 
    } 
      
    return false; 
} 
  /////////////////////////////////////IMPORTANTE definir V1 y V2
  // V1 [ 0 - V1 - 1 ] 
  // V2 [ 0 - V2 - 1 ]
int hopcroft_karp(){ 
    bool change = true; 
    memset(l,-1,sizeof(int)*V1); 
    memset(r,-1,sizeof(int)*V2); 
      
    while(change){ 
        change = false; 
        memset(visited,false,sizeof(bool)*V1); 
          
        for(int i = 0;i<V1;++i) 
            if(l[i]==-1) change |= pairup(i); 
    } 
      
    int ret = 0; 
    for(int i = 0;i<V1;++i) 
        if(l[i]!=-1) ++ret; 
      
    return ret; 
} 
