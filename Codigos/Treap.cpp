
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
void insert(int x)
{
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

