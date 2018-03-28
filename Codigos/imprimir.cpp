#include <bits/stdc++.h>

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

//Bipartite matching
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

//Componentes Fuertemente Conexas -- Recordar la lista Transpuesta y limpieza

int n , m , comp[N+10] , ncomp , in[N+10] , cost[N+5], mini[N+5];
vi adj[N+10] , adjT[N+10];
bool vis[N+10];
stack<int> nodes;
void clean(){
    for(int i = 0 ; i < n ; i++){
        mini[i] = inf;
        adj[i].clear();
        adjT[i].clear();
    }
    me(vis,0);
    me(in,0);
}

void dfs1(int u){
    vis[u] = 1;
    for(int i = 0 ; i < adj[u].size() ; i++) if( !vis[ adj[u][i] ] ) dfs1( adj[u][i] );
    nodes.push(u);
}

void dfs2(int u){
    vis[u] = 0;
    for(int i = 0 ; i < adjT[u].size() ; i++) if( vis[ adjT[u][i] ] ) dfs2( adjT[u][i] );
    comp[u] = ncomp;
}

void solve(){
    for(int i = 0 ; i < n ; i++) if( !vis[i] ) dfs1( i );
    ncomp = 0;
    while( !nodes.empty() ){
        int q = nodes.top();
        nodes.pop();
        if( vis[ q ] ){
            dfs2(q);
            ++ncomp;
        }
    }
    for(int i = 0 ; i < n ; i++){
        mini[ comp[i] ] = min( mini[ comp[i] ] , cost[i] );
        for(int j = 0 ; j < adj[i].size() ; j++){
            if( comp[i] != comp[ adj[i][j] ] ) in[ comp[ adj[i][j] ] ]++;
        }
    }
    int res = 0;
    for(int i = 0 ; i < ncomp ; i++) if( !in[i] ) res+=mini[i];
    printf("%d\n",res);
}

int main(){
    while( scanf("%d%d",&n,&m) == 2 && (n||m) ){
        clean();
        for(int i = 0 ; i < n ; i++) scanf("%d",&cost[i]);
        int x , y;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&x,&y);
            x--,y--;
            adj[x].pb(y);
            adjT[y].pb(x);
        }
        solve();
    }
}

//Contar digitos - ya vino por siaca :P

long long cuenta(long long n){
    if(n == 0) return 1;
        vector<long long>dev(10,0); 
        for(long long i=1;i<=n;i*=10){ 
            long long a=(n/i)/10;
            for(long long j=0;j<10;j++)dev[j]+=a*i;
            dev[0]-=i;
            for(long long j=0;j<(n/i)%10;j++)dev[j]+=i; 
            dev[(n/i)%10]+= (n%i)+1; 
        }
        return dev[0] + 1;
}

int main(){
    long long m , n;
    while( cin>>m>>n ){
        if(m < 0 && n < 0)break;
        if( m == 0 ){
             if( n == 0 ){ cout<<"1"<<endl; continue; }
             cout<<cuenta( n  )<<endl; continue; 
        }
        cout<<cuenta( n  ) - cuenta( m - 1) <<endl;
    }    
}

//Ultimo digito en N!
int get(int n,int x){
    if(n == 0) return 0;
    return n / x + get( n / x , x );
}

int t[4][4] = 
            {
                6 , 2 , 4 , 8,
                1 , 3 , 9 , 7,
                1 , 7 , 9 , 3,
                1 , 9 , 1 , 9
            };

int g(int n,int x){
    if( n == 0 )
        return 0;
    return n/10 + (n%10 >= x) + g( n/5 , x );
}            

int f(int n,int x){
    if( n == 0 ) return 0;
    return f(n/2 , x) + g(n , x);
}

int main(){
    int n , m;
    while( scanf("%d%d",&n,&m) == 2 ){
        
        int k2 = get( n , 2 ) - get( n - m , 2 );
        int k5 = get( n , 5 ) - get( n - m , 5 );
        int k3 = f( n , 3 ) - f( n - m , 3 );
        int k7 = f( n , 7 ) - f( n - m , 7 );
        int k9 = f( n , 9 ) - f( n - m , 9 );
        
        if( k5 > k2 )
            printf("5\n");
        else{
            int ans = 1;
            if( k2 > k5 ) ans *= t[0][(k2-k5)%4];
            ans *= t[1][k3%4];
            ans *= t[2][k7%4];
            ans *= t[3][k9%4];
            ans %= MOD;
            printf("%d\n",ans);
        }
    }
    return 0;
}

//LCA good method

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

//struct Matrix
struct Mat{
    int n;
    int m[N][N];
    Mat( int _n , bool ok = 1 ){
        me(m,0);
        n = _n;
        if(ok)
            for(int i = 0 ; i < n ; i++)
                m[i][i] = 1;
    }
    Mat operator*( Mat A ){
        Mat X( A.n , 0 );
        for(int i = 0 ; i < A.n ; i++)
            for(int j = 0 ; j < A.n ; j++)
                for(int k = 0 ; k < A.n ; k++)
                    X.m[i][j] = (X.m[i][j] +  A.m[i][k] * m[k][j])%MOD; // need define MOD
                
        return X;
    }
    Mat fastpow( Mat x , ll y ){
        Mat P( x.n );
        while( y ){
		    if(y & 1) P = P * x;
		
		    y >>= 1;
		    x = x * x;
	    }
	    return P;
    }
    void resize(int _n){
        n = _n;
    }
    void clean(){
        me(m,0);
    }
    void print(){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++)
                cout << m[i][j] << "";
            puts("");
        }
    }
};

//Tener la Media online 
priority_queue < int , vector<int>, less <int> > a;
priority_queue < int , vector<int>, greater <int> > b;
char s[12];
int n = 0;
while( scanf("%s",s) == 1 ){
    if( s[0] == '#' ){             //query o consulta
        if( n&1 ) printf("%d\n",a.top()); a.pop();
        else if( b.size() > 0 )
            printf("%d\n",b.top()); b.pop();
        n--;
    }
    else{           //insert value
        int x = toint( s );
        if( n&1 ){
            a.push(x);
            b.push( a.top() ); a.pop();
        }
        else{
            b.push(x);
            a.push( b.top() ); b.pop();
        }
    }
}
    
//Minimo Cost Arboresence el costo minimo para un arbol dirigido
#define FF(a, b) for(a=0; a<b; a++)
#define CC(a,b) memset(a, b, sizeof(a))

#define M 120
#define type int
#define inf INT_MAX

// Problem -- root = 0, need MinimunCostArborescence

struct Node{
		int u , v;
		type cost;
}E[M*M];

struct node{
		int x, y;
}q[M];

int pre[M],ID[M],vis[M];  
type In[M];               


type Directed_MST(int root,int NV,int NE) {
		type ret = 0;
		while(true) {

				int i;
				FF(i,NV) In[i] = inf;
				FF(i,NE) {
						int u = E[i].u;
						int v = E[i].v;
						if(E[i].cost < In[v] && u != v) {
								pre[v] = u;
								In[v] = E[i].cost;
						}
				}               
				FF(i,NV) {
						if(i == root) continue;
						if(In[i] == inf)	return -1;
				}

				int cntnode = 0;
				CC(ID,-1);
				CC(vis,-1);
				In[root] = 0;
				FF(i,NV) {//����ÿ����
						ret += In[i];
						int v = i;
						while(vis[v] != i && ID[v] == -1 && v != root) {
								vis[v] = i;
								v = pre[v];
						}
						if(v != root && ID[v] == -1) {
								for(int u = pre[v] ; u != v ; u = pre[u]) {
										ID[u] = cntnode;
								}
								ID[v] = cntnode ++;
						}
				}
				if(cntnode == 0)	break;
				FF(i,NV) if(ID[i] == -1) {
						ID[i] = cntnode ++;
				}

				FF(i,NE) {
						int v = E[i].v;
						E[i].u = ID[E[i].u];
						E[i].v = ID[E[i].v];
						if(E[i].u != E[i].v) {
								E[i].cost -= In[v];
						}
				}
				NV = cntnode;
				root = ID[root];
		}
		return ret;
}

int main(){
		int n, m;
		int i, j, k;
		while(scanf("%d %d", &n, &m) == 2){
				if(!n && !m) sbreak;
				for(i=0; i<m; i++){
						int a, b, c;
						scanf("%d %d %d", &a, &b, &c); // Edge a -- > b whit cost c
						a--;
						b--;
						E[i].u = a;
						E[i].v = b;
						E[i].cost = c;			
				}
				int cnt = Directed_MST(0, n, m);
				if(cnt == -1) printf("impossible\n");
				else printf("%d\n", cnt);
		}
}

//Rotating Callipers
void Rating_Calipers(){
    for(int i=0, j=2; i<n; i++){
        // P[j] debe ser el punto mas lejano a la linea P[i], P[(i+1)%n]:
        while(area(P[i], P[(i+1)%n], P[(j+1)%n]) > area(P[i], P[(i+1)%n], P[j])) j = (j+1)%n;
     
        // Par antipodal: i, j
        // Par antipodal: (i+1)%n, j
    }
}

//Treap
typedef struct node * pnode;

struct node{
	int x, y, cnt;
	bool rev;
	pnode L, R;
	node() {}
	node(int X, int Y){ x = X , y = Y , cnt = 1, L = NULL, R = NULL; }
};

pnode T;

inline int cnt(pnode &it){
	return it ? it->cnt : 0;
}

inline void upd_cnt(pnode &it){
	if(it){
		it->cnt = cnt(it->L) + cnt(it->R) + 1;
	}
}

// Lazy propagation
void push(pnode it){
	if (it && it->rev){
		it->rev = false;
		swap(it->L, it->R);
		if (it->L) it->L->rev ^= true;
		if (it->R) it->R->rev ^= true;
	}
}

// Split Treap
void split(pnode t, int x, pnode &L, pnode &R){
	if (!t) L = R = NULL;
	else{
		//push(t);
		if (x < t->x)
			split (t->L, x, L, t->L), R = t;
		else
			split (t->R, x, t->R, R), L = t;
		upd_cnt(t);
	}
}

// Split Implicit Treap
void split(pnode t, pnode &L, pnode &R, int key){
	if (!t) L = R = NULL;
	else{
		//push(t);
		int cntL = cnt(t->L);
		if (key <= cntL)
			split (t->L, L, t->L, key), R = t;
		else
			split (t->R, t->R, R, key - cntL - 1), L = t;
		upd_cnt(t);
	}
}

// For Treap & Implicit Treap
void merge(pnode &t, pnode L, pnode R){
	//push(L);
	//push(R);
	if (!L) t = R;
	else if(!R) t = L;
	else if (L->y > R->y)
		merge (L->R, L->R, R), t = L;
	else
		merge (R->L, L, R->L), t = R;
	upd_cnt(t);
}

// Combines 2 treaps
pnode unite (pnode l, pnode r){
	if (!l || !r) return l? l: r;
	if (l->y > r->y) swap (l, r);
	pnode lt, rt;
	split (r, l->x, lt, rt);
	l->L = unite(l->L, lt);
	l->R = unite(l->R, rt);
	return l;
}

// Find in Treap
bool find (pnode &t, int x) {
	if(!t) return 0;
	else if (t->x == x) return 1;
	else return find (x < t->x ? t->L: t->R, x);
}

// Erase from Treap
void erase (pnode &t, int x) {
    if(t) {
	   if (t-> x == x)
		  merge (t, t->L, t->R);
	   else
		  erase (x < t->x ? t->L: t->R, x);
	    upd_cnt(t);
    }
}

// Insert into Treap
void insert(pnode &t, pnode it) {
	if (!t) t = it;
	else if (it->y > t->y)
		split (t, it->x, it->L, it->R), t = it;
	else insert (it->x < t->x ? t->L: t->R, it);
	upd_cnt(t);
}

// Insert into Treap and return the # of greater elements
int insert(pnode &t, pnode it){
	int ret = 0;
	if (!t) t = it;
	else if (it->y > t->y)
		split (t, it->x, it->L, it->R), t = it, ret = cnt(t->R);
	else if(it->x < t->x)
		ret = 1 + cnt(t->R) + insert(t->L, it);
	else
		ret = insert(t->R, it);
	upd_cnt(t);
	return ret;
}

// Safely insert into Treap
void insert(int x){
	if(!find(T, x))
		insert(T, new node(x, rand()));
}

// Insert into implicit Treap
void insert(pnode &t, int value, int pos){
	pnode t1, t2;
	split(t, t1, t2, pos);
	merge(t1, t1, new node(value, rand()));
	merge(t, t1, t2);
}

// Reverse implicit Treap
void reverse(pnode &t, int l, int r){
	pnode t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r-l +1);
	t2->rev ^= true;
	merge(t, t1, t2);
	merge(t, t, t3);
}

//LIS Nlog(N)

int LIS(vector<int> X){
    int n = X.size(),L = 0,M[n+1],P[n]; 
    int lo,hi,mi;
    
    L = 0;
    M[0] = 0;
    
    for(int i=0,j;i<n;i++){
        lo = 0; hi = L;
        
        while(lo!=hi){
            mi = (lo+hi+1)/2;
            
            if(X[M[mi]]<X[i]) lo = mi;
            else hi = mi-1;
        }
        
        j = lo;
        
        P[i] = M[j];
        
        if(j==L || X[i]<X[M[j+1]]){
            M[j+1] = i;
            L = max(L,j+1);
        }
    }
    
    return L;
}
//Con lista de padres
/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
void find_lis(vector<int> &a, vector<int> &b)
{
  vector<int> p(a.size());
  int u, v;

  if (a.empty()) return;

  b.push_back(0);

  for (size_t i = 1; i < a.size(); i++) {
      if (a[b.back()] < a[i]) {
          p[i] = b.back();
          b.push_back(i);
          continue;
      }

      for (u = 0, v = b.size()-1; u < v;) {
          int c = (u + v) / 2;
          if (a[b[c]] < a[i]) u=c+1; else v=c;
      }

      if (a[i] < a[b[u]]) {
          if (u > 0) p[i] = b[u-1];
          b[u] = i;
      }   
  }

  for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

/* Example of usage: */
#include <cstdio>
int main()
{
  int a[] = { 1, 9, 3, 8, 11, 4, 5, 6, 4, 19, 7, 1, 7 };
  vector<int> seq(a, a+sizeof(a)/sizeof(a[0]));
  vector<int> lis;
        find_lis(seq, lis);

  for (size_t i = 0; i < lis.size(); i++)
      printf("%d ", seq[lis[i]]);
        printf("\n");    

  return 0;
}

//3D BIT 
if( m == 3 ) break;
        else if( m == 1 ){
            scanf("%d%d%d%d",&x,&y,&z,&c); x++,y++,z++;
            if( a[x][y][z] + c <= 0 ) c = -a[x][y][z];
            update( x , y , z , c );
            a[x][y][z] = a[x][y][z] + c;
        }
        else{
            scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2); x2++,y2++,z2++,x1++,y1++,z1++;
            int ans = query(x2,y2,z2) - query(x2,y2,z1-1) - query(x2,y1-1,z2) - query(x1-1,y2,z2)
                            + query(x1-1,y1-1,z2) + query(x1-1,y2,z1-1) + query(x2,y1-1,z1-1) - query(x1-1,y1-1,z1-1);
             printf("%d\n",ans);
        }

//Devuelve el promedio de los LCP pero de forma 
1   11  'IMISSISSIPP'	1
2	8	'IPPIMISSISS'	1
3	5	'ISSIPPIMISS'	4
4	2	'ISSISSIPPIM'	0
5	1	'MISSISSIPPI'	0
6	10	'PIMISSISSIP'	1
7	9	'PPIMISSISSI'	0
8	7	'SIPPIMISSIS'	2
9	4	'SISSIPPIMIS'	1
10	6	'SSIPPIMISSI'	3
11	3	'SSISSIPPIMI'

while(cin >> t){
        getline( cin , s );
        getline( cin , s );
        int lim = s.length();
        s += s;
        s += "$";
        n = s.size();
        suff_arr();
        lcp();
        //for(int i = 0 ; i < n ; i++)
            //cout << s.substr( r[i] ) << endl;
        ll ans = 0;
        int ct = 0 , lleva = lim;
        for(int i = 0 ; i < n ; i++){
            if( r[i] < lim ){
                //cout << s.substr( r[i] ) << endl;
                ct++;
                if( ct == 2 ){
                    ans += lleva;
                    ct--;
                    lleva = lim;
                }
                lleva = min( lleva , h[i] );
            }
        }
        double k = (1.0*ans);
        k /= (lim-1);
        printf("%.3lf\n", k );
    }

//Dinic Algotihm MaxFlow con problema de juego
struct flow_graph{
    int MAX_V,E,s,t,head,tail;
    int *cap,*to,*next,*last,*dist,*q,*now;
    flow_graph(){}
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = 0;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], q = new int[MAX_V];
        dist = new int[MAX_V], now = new int[MAX_V];
        fill(last,last+MAX_V,-1);
    }
    void clear(){
        fill(last,last+MAX_V,-1);
        E = 0;
    }
    void add_edge(int u, int v, int uv, int vu = 0){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = vu, next[E] = last[v]; last[v] = E++;
    }
    bool bfs(){
        fill(dist,dist+MAX_V,-1);
        head = tail = 0;
		
        q[tail] = t; ++tail;
        dist[t] = 0;
		
        while(head<tail){
            int v = q[head]; ++head;
            
            for(int e = last[v];e!=-1;e = next[e]){
                if(cap[e^1]>0 && dist[to[e]]==-1){
                    q[tail] = to[e]; ++tail;
                    dist[to[e]] = dist[v]+1;
                }
            }
        }
        
        return dist[s]!=-1;
    }
	
    int dfs(int v, int f){
        if(v==t) return f;
		
        for(int &e = now[v];e!=-1;e = next[e]){
            if(cap[e]>0 && dist[to[e]]==dist[v]-1){
                int ret = dfs(to[e],min(f,cap[e]));
				
                if(ret>0){
                    cap[e] -= ret;
                    cap[e^1] += ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    int max_flow(int source, int sink){
        s = source; t = sink;
        int f = 0;
        int x;
        while(bfs()){
            for(int i = 0;i<MAX_V;++i) now[i] = last[i];
			
            while(true){
                x = dfs(s,inf);
                if(x==0) break;
                f += x;
            }
        }
        return f;
    }
};
int n , S , T , peso[201];
flow_graph F;
void build(){
    for(int i = 1 ; i <= n ; i++)
        F.add_edge( S , i , peso[i] );
    int ct = n+1;
    for(int i = 1 ; i < n ; i++){
        for(int j = i+1 ; j <= n ; j++)if(i!=j){
            F.add_edge( i , ct , 3 );
            F.add_edge( j , ct , 3 );
            F.add_edge( ct++ , T , 3 );
        }
    }
}

void print(){
    for(int e = 2*n ; e < F.E ; e+=6){
        int d = e+2;
        int a = 3 - F.cap[e] , b = 3 - F.cap[d];
        printf("%d",F.to[e^1]);
        if( a-b == 3 ) printf(" > ");
        if( a-b == -3 ) printf(" < ");
        if( a-b == 1 ) printf(" >= ");
        if( a-b == -1 ) printf(" <= ");
        printf("%d\n",F.to[d^1]);
    }
}

void doit(){
    scanf("%d",&n);
    S = 0;
    T = (n*(n-1))/2 + n + 1;
    F = flow_graph( T+1 , 3*T+1 );
    for(int i = 1 ; i <= n ; i++)
        scanf("%d",&peso[i]);
    build();
    if( F.max_flow(S,T) == (3*n*(n-1))/2 ){
        puts("CORRECT");
        print();
    }
    else puts("INCORRECT");
}
//Derangement Number
//modificacion (A+B) //B esta bien

dp[0] = F[B];
for(int i=1; i<=A; i++)
{
	long long x = F[i+B];
	for(int k=1; k<=i; k++)
		x = ((x - C[i][k] * dp[i-k] % MOD) + MOD) % MOD;
	dp[i] = x;
}

public class Main {

    public static void main(String[] args) {
        
        BigInteger F[] = new BigInteger[1001];
        F[1] = BigInteger.ZERO;
        F[2] = BigInteger.ONE;
        for(int i = 3 ; i < 1001 ; i++)
            F[i] = BigInteger.valueOf(i-1).multiply( F[i-1].add(F[i-2]) );
        
        Scanner in = new Scanner( System.in );
        int n = in.nextInt();
        System.out.println(F[n]);
        
        
    }
}
//Nice DP
One day, Huang Yaoshi, Zhou Botong and Li Qiushui meet in SCU again. No contact for so many years, they all have a great progress in Kung Fu, and still can not differentiate who is the best in the world. So they ask the famous Lord Windy to decide. But in fact, it is also difficut for Lord Windy to know who is the best in the three young man in Kung Fu, so he make an ACM problem to differentiate who is clever for them, and the one who first solve it is the best in the world.
The problem is this:

This year there are K students to participate in ACM competition. After the competion, every one of the K participants can get a rank between 1 and K, and there are no two students whose ranks are the same. To enable all the K students to have a harvest, the organizers decide to distribute apples to the K participants according to their ranks. At first the organizers buy N apples which are the same, and then distribute the N apples with the rules of this:

(1) The number of apples the student ranking i gets can not be less than the number of apples the student ranking i + 1 gets.
(2) Every student at lest gets one apple.
(3) At last there is no apple left.

For example: if N=4 and K=3, there are only one way to distribute the apples: the one ranking 1 gets 2 apples, the one ranking 2 gets 1 apple, and the one ranking 3 gets 1 apple.

Now give the N and K, you just tell me after the competition, how many different ways to distribute the N apples to the K participants. Because the result may be very large, we make the result module 10009 for the output.

Huang Yaoshi, Zhou Botong ahd Li Qiushui can not solve the problem, they ask you to help them.
int f(int n,int k){
    if( n == 0 )
        return (k == 0);
    
    int &ret = t[n][k];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = 0 ; i <= k and k >= i * n ; i++)
        ret = ( ret + f( n - 1 , k - n * i ) )%MOD;
    
    return ret;
}

int main(){
    int tc;
    sc(tc);
    me(t,-1);
    while( tc-- ){
        int n , k;
        scanf("%d%d",&k,&n);
        k -= n;
        if( k < 0 )
            printf("%d\n",0);
        else printf("%d\n",f( n , k ));
    }
    return 0;
}

//Catalan Number
0	1
1	1
2	2
3	5
4	14
5	42
6	132
7	429
8	1.430
9	4.862
10	16.796
11	58.786
12	208.012
13	742.900
14	2.674.440
15	9.694.845
16	35.357.670
17	129.644.790
18	477.638.700
19	1.767.263.190
20	6.564.120.420
21	24.466.267.020
22	91.482.563.640
23	343.059.613.650
24	1.289.904.147.324
25	4.861.946.401.452

void generate_catalan_numbers() {
    catalan[1] = 1;
    for (int i = 2; i <= MAX_NUMBERS; i++) {
        for (int j = 1; j <= i - 1; j++) {
            catalan[i] = (catalan[i] + ((catalan[j]) * catalan[i - j]) % MODULO) % MODULO;
        }
        catalan[i] = catalan[i] % MODULO;
    }
}
function catalan(n,  ans) {
    if (n == 0) {
      ans = 1
    }
    else {
      ans = ((2*(2*n-1))/(n+1))*catalan(n-1)
    }
    return(ans)
}

//Stirling numbers type 2

n \ k	0	1	2	3	4	5	6	7	8	9	10
0	    1
1	    0	1
2	    0	1	1
3	    0	1	3	1
4	    0	1	7	6	1
5	    0	1	15	25	10	1
6	    0	1	31	90	65	15	1
7	    0	1	63	301	350	140	21	1
8	    0	1	127	966	1701	1050	266	28	1
9	    0	1	255	3025	7770	6951	2646	462	36	1
10	    0	1	511	9330	34105	42525	22827	5880	750	45	1

S(n,k) = S(n-1,k-1) + k * S(n-1,k), if 1 < k < n

S(n,k) = 1, if k=1 ou k=n

unsigned long long int a[n][k];
   for (int i=0; i<=n; i++){     //clearing the table with zeros
   	for (int j=0; j<=k; j++){
   		a[i][j]=0;	
   		};
   }; 
   
    for (int i=0; i<=n; i++){     
   	for (int j=0; j<=k; j++){
   		if (i<j) a[i][j]=0;
   		else if (i==j) a[i][j]=1;
   		else if (j==1) a[i][j]=1;
   		else if (j==0) a[i][j]=0;
   		else if ((j<i)&&((!(j==1))&&(!(j==0))))  a[i][j]= (j * a[i-1][j]) + a[i-1][j-1];
   		cout<<"i: "<<i<<", j: "<<j<<", a[i][j]: "<<a[i][j]<<endl;	
   		};
   }; 
