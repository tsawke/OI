// // // // // // // // // // // // // // #define _USE_MATH_DEFINES
// // // // // // // // // // // // // // #include <bits/stdc++.h>

// // // // // // // // // // // // // // #define PI M_PI
// // // // // // // // // // // // // // #define E M_E

// // // // // // // // // // // // // // using namespace std;

// // // // // // // // // // // // // // mt19937 rnd(random_device{}());
// // // // // // // // // // // // // // int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

// // // // // // // // // // // // // // typedef unsigned int uint;
// // // // // // // // // // // // // // typedef unsigned long long unll;
// // // // // // // // // // // // // // typedef long long ll;



// // // // // // // // // // // // // // template<typename T = int>
// // // // // // // // // // // // // // inline T read(void);

// // // // // // // // // // // // // // #define LIM (210000)

// // // // // // // // // // // // // // #define npt nullptr

// // // // // // // // // // // // // // struct Treap{
// // // // // // // // // // // // // //     Treap *ls, *rs;
// // // // // // // // // // // // // //     ll val;      // base value
// // // // // // // // // // // // // //     int pri;
// // // // // // // // // // // // // //     int siz, cnt;
// // // // // // // // // // // // // //     ll lazy;     // 懒加：整个子树要加的 offset
// // // // // // // // // // // // // //     void* operator new(size_t);
// // // // // // // // // // // // // //     Treap(Treap* _ls, Treap* _rs, ll _val, int _pri):ls(_ls), rs(_rs), val(_val), pri(_pri), siz(1), cnt(1), lazy(0){}
// // // // // // // // // // // // // //     Treap() = default;
// // // // // // // // // // // // // // } tData[220000];
// // // // // // // // // // // // // // void* Treap::operator new(size_t){ static Treap* P = tData; return ++P; }

// // // // // // // // // // // // // // inline int lsiz(Treap* p){ return p ? (p->ls ? p->ls->siz : 0) : 0; }
// // // // // // // // // // // // // // inline int rsiz(Treap* p){ return p ? (p->rs ? p->rs->siz : 0) : 0; }
// // // // // // // // // // // // // // inline int size(Treap* p){ return p ? p->siz : 0; }

// // // // // // // // // // // // // // mt19937_64 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
// // // // // // // // // // // // // // inline int rndv(){ return uniform_int_distribution<int>(1, 1e9)(rng); }

// // // // // // // // // // // // // // void push_up(Treap* p){
// // // // // // // // // // // // // //     if(!p) return;
// // // // // // // // // // // // // //     p->siz = p->cnt + (p->ls ? p->ls->siz : 0) + (p->rs ? p->rs->siz : 0);
// // // // // // // // // // // // // // }

// // // // // // // // // // // // // // void apply_lazy(Treap* p, ll v){
// // // // // // // // // // // // // //     if(!p) return;
// // // // // // // // // // // // // //     p->val += v;
// // // // // // // // // // // // // //     p->lazy += v;
// // // // // // // // // // // // // // }

// // // // // // // // // // // // // // void push_down(Treap* p){
// // // // // // // // // // // // // //     if(!p || p->lazy == 0) return;
// // // // // // // // // // // // // //     if(p->ls) apply_lazy(p->ls, p->lazy);
// // // // // // // // // // // // // //     if(p->rs) apply_lazy(p->rs, p->lazy);
// // // // // // // // // // // // // //     p->lazy = 0;
// // // // // // // // // // // // // // }

// // // // // // // // // // // // // // pair<Treap*, Treap*> Split(Treap* P, ll val){ // <=val | >val, 电脑保留但不主要用
// // // // // // // // // // // // // //     if(!P) return {npt, npt};
// // // // // // // // // // // // // //     push_down(P);
// // // // // // // // // // // // // //     if(val >= P->val){
// // // // // // // // // // // // // //         auto tmp = Split(P->rs, val);
// // // // // // // // // // // // // //         P->rs = tmp.first;
// // // // // // // // // // // // // //         push_up(P);
// // // // // // // // // // // // // //         return {P, tmp.second};
// // // // // // // // // // // // // //     } else {
// // // // // // // // // // // // // //         auto tmp = Split(P->ls, val);
// // // // // // // // // // // // // //         P->ls = tmp.second;
// // // // // // // // // // // // // //         push_up(P);
// // // // // // // // // // // // // //         return {tmp.first, P};
// // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // }

// // // // // // // // // // // // // // // 按秩拆出：左 l 是前 rnk-1 个， mid 是第 rnk 个（含 cnt 跨越）， r 是剩下
// // // // // // // // // // // // // // tuple<Treap*, Treap*, Treap*> Split_By_Rank(Treap* p, int rnk){
// // // // // // // // // // // // // //     if(!p) return {npt, npt, npt};
// // // // // // // // // // // // // //     push_down(p);
// // // // // // // // // // // // // //     int lsz = p->ls ? p->ls->siz : 0;
// // // // // // // // // // // // // //     if(rnk <= lsz){
// // // // // // // // // // // // // //         Treap *l, *mid, *r;
// // // // // // // // // // // // // //         tie(l, mid, r) = Split_By_Rank(p->ls, rnk);
// // // // // // // // // // // // // //         p->ls = r;
// // // // // // // // // // // // // //         push_up(p);
// // // // // // // // // // // // // //         return {l, mid, p};
// // // // // // // // // // // // // //     } else if(rnk <= lsz + p->cnt){
// // // // // // // // // // // // // //         Treap* l = p->ls;
// // // // // // // // // // // // // //         Treap* r = p->rs;
// // // // // // // // // // // // // //         p->ls = p->rs = npt;
// // // // // // // // // // // // // //         push_up(p);
// // // // // // // // // // // // // //         return {l, p, r};
// // // // // // // // // // // // // //     } else {
// // // // // // // // // // // // // //         Treap *l, *mid, *r;
// // // // // // // // // // // // // //         tie(l, mid, r) = Split_By_Rank(p->rs, rnk - lsz - p->cnt);
// // // // // // // // // // // // // //         p->rs = l;
// // // // // // // // // // // // // //         push_up(p);
// // // // // // // // // // // // // //         return {p, mid, r};
// // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // }

// // // // // // // // // // // // // // Treap* Merge(Treap* l, Treap* r){
// // // // // // // // // // // // // //     if(!l) return r;
// // // // // // // // // // // // // //     if(!r) return l;
// // // // // // // // // // // // // //     if(l->pri < r->pri){
// // // // // // // // // // // // // //         push_down(l);
// // // // // // // // // // // // // //         l->rs = Merge(l->rs, r);
// // // // // // // // // // // // // //         push_up(l);
// // // // // // // // // // // // // //         return l;
// // // // // // // // // // // // // //     } else {
// // // // // // // // // // // // // //         push_down(r);
// // // // // // // // // // // // // //         r->ls = Merge(l, r->ls);
// // // // // // // // // // // // // //         push_up(r);
// // // // // // // // // // // // // //         return r;
// // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // }

// // // // // // // // // // // // // // void Insert(Treap* &p, ll val){
// // // // // // // // // // // // // //     auto spl = Split(p, val);
// // // // // // // // // // // // // //     auto spll = Split(spl.first, val - 1);
// // // // // // // // // // // // // //     if(!spll.second){
// // // // // // // // // // // // // //         spll.second = new Treap(npt, npt, val, rndv());
// // // // // // // // // // // // // //     } else {
// // // // // // // // // // // // // //         spll.second->cnt++;
// // // // // // // // // // // // // //     }
// // // // // // // // // // // // // //     push_up(spll.second);
// // // // // // // // // // // // // //     Treap* m1 = Merge(spll.first, spll.second);
// // // // // // // // // // // // // //     p = Merge(m1, spl.second);
// // // // // // // // // // // // // // }

// // // // // // // // // // // // // // void Delete(Treap* &p, ll val){
// // // // // // // // // // // // // //     auto spl = Split(p, val);
// // // // // // // // // // // // // //     auto spll = Split(spl.first, val - 1);
// // // // // // // // // // // // // //     if(!spll.second){
// // // // // // // // // // // // // //         // 不存在
// // // // // // // // // // // // // //         return;
// // // // // // // // // // // // // //     }
// // // // // // // // // // // // // //     if(spll.second->cnt == 1) spll.second = npt;
// // // // // // // // // // // // // //     else spll.second->cnt--, push_up(spll.second);
// // // // // // // // // // // // // //     Treap* m1 = Merge(spll.first, spll.second);
// // // // // // // // // // // // // //     p = Merge(m1, spl.second);
// // // // // // // // // // // // // // }

// // // // // // // // // // // // // // // 取某一棵树中最左（最小 base）节点的 val（前提是已经 push_down 了路径）
// // // // // // // // // // // // // // ll get_min_base(Treap* p){
// // // // // // // // // // // // // //     if(!p) return LLONG_MAX;
// // // // // // // // // // // // // //     push_down(p);
// // // // // // // // // // // // // //     while(p->ls){
// // // // // // // // // // // // // //         p = p->ls;
// // // // // // // // // // // // // //         push_down(p);
// // // // // // // // // // // // // //     }
// // // // // // // // // // // // // //     return p->val;
// // // // // // // // // // // // // // }

// // // // // // // // // // // // // // // 全局 root
// // // // // // // // // // // // // // Treap* root = npt;

// // // // // // // // // // // // // // // 给 top-p（最大 p 个）统一加 delta（可能正负），然后重 split 修正 membership
// // // // // // // // // // // // // // void add_to_top_p(int p, ll delta){
// // // // // // // // // // // // // //     if(!root) return;
// // // // // // // // // // // // // //     int total = size(root);
// // // // // // // // // // // // // //     if(p <= 0) return;
// // // // // // // // // // // // // //     if(p > total) p = total;
// // // // // // // // // // // // // //     Treap *A, *B, *C;
// // // // // // // // // // // // // //     // 拆出 largest p：先 split total-p 前部 A and rest BC
// // // // // // // // // // // // // //     tie(A, B, C) = Split_By_Rank(root, total - p);
// // // // // // // // // // // // // //     // B 是 top-p（最大的 p 个）
// // // // // // // // // // // // // //     // 给 B 统一加 delta（懒）
// // // // // // // // // // // // // //     apply_lazy(B, delta);
// // // // // // // // // // // // // //     // 重新合并再重切：处理减法后 membership 变化
// // // // // // // // // // // // // //     root = Merge(Merge(A, B), C);
// // // // // // // // // // // // // //     // 重新 split 出 largest p 作为新的 top-p context
// // // // // // // // // // // // // //     tie(A, B, C) = Split_By_Rank(root, total - p);
// // // // // // // // // // // // // //     // 还原结构，保留修改
// // // // // // // // // // // // // //     root = Merge(Merge(A, B), C);
// // // // // // // // // // // // // // }

// // // // // // // // // // // // // // // 查询 top-p 中的最小实际值（拆出、取最左 + lazy ）
// // // // // // // // // // // // // // ll query_min_top_p(int p){
// // // // // // // // // // // // // //     if(!root) return LLONG_MIN;
// // // // // // // // // // // // // //     int total = size(root);
// // // // // // // // // // // // // //     if(p <= 0) return LLONG_MIN;
// // // // // // // // // // // // // //     if(p > total) p = total;
// // // // // // // // // // // // // //     Treap *A, *B, *C;
// // // // // // // // // // // // // //     tie(A, B, C) = Split_By_Rank(root, total - p);
// // // // // // // // // // // // // //     // B 是当前 top-p
// // // // // // // // // // // // // //     ll base_min = get_min_base(B);
// // // // // // // // // // // // // //     // B 可能带 lazy（已体现在 B subtree via apply_lazy propagation), but get_min_base visits leftmost with push_down
// // // // // // // // // // // // // //     ll res = base_min;
// // // // // // // // // // // // // //     // 还原
// // // // // // // // // // // // // //     root = Merge(Merge(A, B), C);
// // // // // // // // // // // // // //     return res;
// // // // // // // // // // // // // // }

// // // // // // // // // // // // // // // 方便调试：中序遍历打印（带展开 lazy）
// // // // // // // // // // // // // // void inorder_print(Treap* p){
// // // // // // // // // // // // // //     if(!p) return;
// // // // // // // // // // // // // //     push_down(p);
// // // // // // // // // // // // // //     inorder_print(p->ls);
// // // // // // // // // // // // // //     for(int i=0;i<p->cnt;i++){
// // // // // // // // // // // // // //         cout << p->val << " ";
// // // // // // // // // // // // // //     }
// // // // // // // // // // // // // //     inorder_print(p->rs);
// // // // // // // // // // // // // // }

// // // // // // // // // // // // // // template<typename T = int>
// // // // // // // // // // // // // // inline T read(void);


// // // // // // // // // // // // // // int N, M, K, P;
// // // // // // // // // // // // // // int A[LIM];
// // // // // // // // // // // // // // int cnt[LIM], lft[LIM];
// // // // // // // // // // // // // // int ans(0);

// // // // // // // // // // // // // // int main(){
// // // // // // // // // // // // // //     int T = read();
// // // // // // // // // // // // // //     while(T--){
// // // // // // // // // // // // // //         ans = 0;
// // // // // // // // // // // // // //         N = read(), M = read(), K = read(), P = read();
// // // // // // // // // // // // // //         for(int i = 1; i <= N; ++i)A[i] = read(), cnt[i] = A[i] / K, lft[i] = A[i] % K, Insert(root, cnt[i]);
// // // // // // // // // // // // // //         while(M > 0 && root->siz > 0){
// // // // // // // // // // // // // //             int p = min({P, root->siz});
// // // // // // // // // // // // // //             int val = query_min_top_p(p);
// // // // // // // // // // // // // //             add_to_top_p(p, -val);
// // // // // // // // // // // // // //             ++ans;
// // // // // // // // // // // // // //             M -= p * K;
// // // // // // // // // // // // // //             Delete(root, 0);
// // // // // // // // // // // // // //         }
// // // // // // // // // // // // // //         if(M <= 0){
// // // // // // // // // // // // // //             printf("%d\n", ans);
// // // // // // // // // // // // // //             continue;
// // // // // // // // // // // // // //         }



// // // // // // // // // // // // // //     }


// // // // // // // // // // // // // //     // int Q = read();
// // // // // // // // // // // // // //     // int current_p = 0;
// // // // // // // // // // // // // //     // while(Q--){
// // // // // // // // // // // // // //     //     int type = read();
// // // // // // // // // // // // // //     //     if(type == 1){ // 插入 x
// // // // // // // // // // // // // //     //         ll x = read();
// // // // // // // // // // // // // //     //         Insert(root, x);
// // // // // // // // // // // // // //     //     } else if(type == 2){ // 删除 x
// // // // // // // // // // // // // //     //         ll x = read();
// // // // // // // // // // // // // //     //         Delete(root, x);
// // // // // // // // // // // // // //     //     } else if(type == 3){ // 设定 p 并查询 top-p 最小值（前 p 大中的最小）
// // // // // // // // // // // // // //     //         int p = read();
// // // // // // // // // // // // // //     //         current_p = p;
// // // // // // // // // // // // // //     //         ll ans = query_min_top_p(p);
// // // // // // // // // // // // // //     //         if(ans == LLONG_MIN) cout << "EMPTY\n";
// // // // // // // // // // // // // //     //         else cout << ans << "\n";
// // // // // // // // // // // // // //     //     } else if(type == 4){ // 对 top-p 统一加 delta
// // // // // // // // // // // // // //     //         ll delta = read();
// // // // // // // // // // // // // //     //         add_to_top_p(current_p, delta);
// // // // // // // // // // // // // //     //     } else if(type == 5){ // 打印当前树（调试）
// // // // // // // // // // // // // //     //         inorder_print(root);
// // // // // // // // // // // // // //     //         cout << "\n";
// // // // // // // // // // // // // //     //     }
// // // // // // // // // // // // // //     // }
// // // // // // // // // // // // // //     // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
// // // // // // // // // // // // // //     return 0;
// // // // // // // // // // // // // // }



// // // // // // // // // // // // // // template<typename T>
// // // // // // // // // // // // // // inline T read(void){
// // // // // // // // // // // // // //     T ret(0);
// // // // // // // // // // // // // //     short flag(1);
// // // // // // // // // // // // // //     char c = getchar();
// // // // // // // // // // // // // //     while(c != '-' && !isdigit(c))c = getchar();
// // // // // // // // // // // // // //     if(c == '-')flag = -1, c = getchar();
// // // // // // // // // // // // // //     while(isdigit(c)){
// // // // // // // // // // // // // //         ret *= 10;
// // // // // // // // // // // // // //         ret += int(c - '0');
// // // // // // // // // // // // // //         c = getchar();
// // // // // // // // // // // // // //     }
// // // // // // // // // // // // // //     ret *= flag;
// // // // // // // // // // // // // //     return ret;
// // // // // // // // // // // // // // }



// // // // // // // // // // // // // // // struct Node{
// // // // // // // // // // // // // // //     Node* lson;
// // // // // // // // // // // // // // //     Node* rson;
// // // // // // // // // // // // // // //     Node* fa;
// // // // // // // // // // // // // // //     int cnt;
// // // // // // // // // // // // // // //     int siz;
// // // // // // // // // // // // // // //     ll val;
// // // // // // // // // // // // // // //     ll sum;
// // // // // // // // // // // // // // //     ll lz;
// // // // // // // // // // // // // // //     // void* operator new(size_t);
// // // // // // // // // // // // // // // };//nd[LIM];
// // // // // // // // // // // // // // // // void* Node::operator new(size_t){static Node* P = nd; return P++;}

// // // // // // // // // // // // // // // Node* root;

// // // // // // // // // // // // // // // #define siz(p) (p ? p->siz : 0)
// // // // // // // // // // // // // // // #define sum(p) (p ? p->sum : 0)
// // // // // // // // // // // // // // // #define son(p, dir) ((dir) ? p->rson : p->lson)

// // // // // // // // // // // // // // // class Splay{
// // // // // // // // // // // // // // // private:
// // // // // // // // // // // // // // // public:
// // // // // // // // // // // // // // //     void Update(Node* p){
// // // // // // // // // // // // // // //         p->siz = p->cnt + siz(p->lson) + siz(p->rson);
// // // // // // // // // // // // // // //         p->sum = p->val * p->cnt + sum(p->lson) + sum(p->rson);
// // // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // //     bool GetDir(Node* p){
// // // // // // // // // // // // // // //         return p->fa ? p->fa->rson == p : false;
// // // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // //     void Link(Node* p, Node* fa, bool dir){
// // // // // // // // // // // // // // //         if(fa)son(fa, dir) = p, Update(fa);
// // // // // // // // // // // // // // //         if(p)p->fa = fa;
// // // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // //     void Rotate(Node* p){
// // // // // // // // // // // // // // //         auto fa = p->fa, gfa = fa->fa;
// // // // // // // // // // // // // // //         auto dir1 = GetDir(p), dir2 = GetDir(fa);
// // // // // // // // // // // // // // //         Link(son(p, !dir1), fa, dir1), Link(fa, p, !dir1), Link(p, gfa, dir2);
// // // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // //     void _Splay(Node* p){
// // // // // // // // // // // // // // //         if(!p)return;
// // // // // // // // // // // // // // //         while(p->fa != npt){
// // // // // // // // // // // // // // //             if(p->fa->fa != npt)
// // // // // // // // // // // // // // //                 Rotate(GetDir(p) == GetDir(p->fa) ? p->fa : p);
// // // // // // // // // // // // // // //             Rotate(p);
// // // // // // // // // // // // // // //         }root = p;
// // // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // //     void Insert(int val, Node* cur = root, Node* fa = npt){
// // // // // // // // // // // // // // //         if(cur && val != cur->val)return Insert(val, val > cur->val ? cur->rson : cur->lson, cur);
// // // // // // // // // // // // // // //         if(!cur){
// // // // // // // // // // // // // // //             cur = new Node{npt, npt, fa, 1, 1, val, val, 0};
// // // // // // // // // // // // // // //             if(fa)son(fa, val > fa->val ? true : false) = cur;
// // // // // // // // // // // // // // //         }else ++cur->cnt;
// // // // // // // // // // // // // // //         Splay(cur);
// // // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // //     Node* Find(int val, Node* cur = root, Node* fa = npt){
// // // // // // // // // // // // // // //         if(!cur)return _Splay(fa), fa;
// // // // // // // // // // // // // // //         if(cur->val != val)return Find(val, val > cur->val ? cur->rson : cur->lson, cur);
// // // // // // // // // // // // // // //         return _Splay(cur), cur;
// // // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // //     void Delete(int val){
// // // // // // // // // // // // // // //         auto cur = Find(val);
// // // // // // // // // // // // // // //         if(!cur)return;
// // // // // // // // // // // // // // //         if(cur->cnt > 1)return --cur->cnt, --cur->siz, void();
// // // // // // // // // // // // // // //         if(!cur->lson && !cur->rson)return root = npt, void();
// // // // // // // // // // // // // // //         if(!cur->lson)return root = cur->rson, cur->rson->fa = npt, void();
// // // // // // // // // // // // // // //         auto mxp = cur->lson;
// // // // // // // // // // // // // // //         while(mxp->rson)mxp = mxp->rson;
// // // // // // // // // // // // // // //         Splay(mxp);
// // // // // // // // // // // // // // //         Link(cur->rson, root, true), Link(root, npt, true);
// // // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // //     void ApplyLazy(Node* p, ll v){
// // // // // // // // // // // // // // //         if(!p)return;
// // // // // // // // // // // // // // //         p->val += v, p->lz += v;
// // // // // // // // // // // // // // //         p->sum += v * p->siz;
// // // // // // // // // // // // // // //     }

// // // // // // // // // // // // // // //     void PushDown(Node* p){
// // // // // // // // // // // // // // //         if(!p || p->lz == 0)return;
// // // // // // // // // // // // // // //         if(p->lson)ApplyLazy(p->lson, p->lz);
// // // // // // // // // // // // // // //         if(p->rson)ApplyLazy(p->rson, p->lz);
// // // // // // // // // // // // // // //         p->lz = 0;
// // // // // // // // // // // // // // //     }

// // // // // // // // // // // // // // //     int FindRankByVal(int val, Node* cur = root, int tot = siz(root->lson)){
// // // // // // // // // // // // // // //         if(!cur || cur->val == val)return _Splay(cur), tot + 1;
// // // // // // // // // // // // // // //         return FindRankByVal(
// // // // // // // // // // // // // // //             val,
// // // // // // // // // // // // // // //             val < cur->val ? cur->lson : cur->rson,
// // // // // // // // // // // // // // //             val < cur->val ? tot - siz(cur->lson) + (cur->lson ? siz(cur->lson->lson) : 0) : tot + cur->cnt + (cur->rson ? siz(cur->rson->lson) : 0)
// // // // // // // // // // // // // // //         );
// // // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // //     int FindValByRank(int rnk, Node* cur = root, int tot = siz(root->lson)){
// // // // // // // // // // // // // // //         if(!cur)return -1;
// // // // // // // // // // // // // // //         if(tot + 1 <= rnk && rnk <= tot + cur->cnt)return _Splay(cur), cur->val;
// // // // // // // // // // // // // // //         return FindValByRank(
// // // // // // // // // // // // // // //             rnk,
// // // // // // // // // // // // // // //             rnk < tot + 1 ? cur->lson : cur->rson,
// // // // // // // // // // // // // // //             rnk < tot + 1 ? tot - siz(cur->lson) + (cur->lson ? siz(cur->lson->lson) : 0) : tot + cur->cnt + (cur->rson ? siz(cur->rson->lson) : 0)
// // // // // // // // // // // // // // //         );
// // // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // //     int FindPre(int val){
// // // // // // // // // // // // // // //         auto cur = Find(val);
// // // // // // // // // // // // // // //         if(cur->val < val)return _Splay(cur), cur->val;
// // // // // // // // // // // // // // //         cur = cur->lson;
// // // // // // // // // // // // // // //         while(cur->rson)cur = cur->rson;
// // // // // // // // // // // // // // //         return _Splay(cur), cur->val;
// // // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // //     int FindNxt(int val){
// // // // // // // // // // // // // // //         auto cur = Find(val);
// // // // // // // // // // // // // // //         if(cur->val > val)return _Splay(cur), cur->val;
// // // // // // // // // // // // // // //         cur = cur->rson;
// // // // // // // // // // // // // // //         while(cur->lson)cur = cur->lson;
// // // // // // // // // // // // // // //         return _Splay(cur), cur->val;
// // // // // // // // // // // // // // //     }
// // // // // // // // // // // // // // // };


// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// template<typename T = ll>
// inline T read() {
//     T x = 0;
//     int f = 1;
//     char c = getchar();
//     while (c != '-' && !isdigit(c)) c = getchar();
//     if (c == '-') f = -1, c = getchar();
//     while (isdigit(c)) { x = x * 10 + (c - '0'); c = getchar(); }
//     return x * f;
// }

// bool feasible(ll T, int n, ll m, ll k, ll p, const vector<ll>& a) {
//     vector<pair<ll,int>> fulls;
//     fulls.reserve(n);
//     for (int i = 0; i < n; ++i) {
//         ll fi = a[i] / k;
//         fulls.emplace_back(fi, i);
//     }
//     sort(fulls.rbegin(), fulls.rend());
//     ll used_full_blocks = 0;
//     vector<int> used_full_per_person(n, 0);
//     for (auto& [fi, idx] : fulls) {
//         ll take = min<ll>(fi, T);
//         ll can_take = min<ll>(take, T * p - used_full_blocks);
//         if (can_take <= 0) break;
//         used_full_per_person[idx] = can_take;
//         used_full_blocks += can_take;
//         if (used_full_blocks == T * p) break;
//     }
//     ll total = used_full_blocks * k;
//     ll used_person_months = used_full_blocks; 
//     ll leftover_slots = T * p - used_person_months;
//     if (leftover_slots <= 0) return total >= m;

//     vector<ll> residuals;
//     residuals.reserve(n);
//     for (int i = 0; i < n; ++i) {
//         ll fi = a[i] / k;
//         if (used_full_per_person[i] < min<ll>(fi, T)) {
//             ll res = a[i] - min<ll>(fi, T) * k; 
//             res = a[i] - (ll)used_full_per_person[i] * k;
//             if (res > 0) residuals.push_back(res);
//         } else if (used_full_per_person[i] < T) {
//             ll res = a[i] - (ll)used_full_per_person[i] * k;
//             if (res > 0) residuals.push_back(res);
//         }
//     }
//     if (!residuals.empty()) {
//         sort(residuals.rbegin(), residuals.rend());
//         int take = min<ll>(leftover_slots, residuals.size());
//         for (int i = 0; i < take; ++i) total += residuals[i];
//     }

//     return total >= m;
// }

// int main() {
//     int Tcases = read<int>();
//     while (Tcases--) {
//         int n = read<int>();
//         ll m = read<ll>();
//         ll k = read<ll>();
//         ll p = read<ll>();
//         vector<ll> a(n);
//         for (int i = 0; i < n; ++i) a[i] = read<ll>();

//         ll lo = 1, hi = (m + k - 1) / k + 5; 
//         ll ans = hi;
//         while (lo <= hi) {
//             ll mid = (lo + hi) >> 1;
//             if (feasible(mid, n, m, k, p, a)) {
//                 ans = mid;
//                 hi = mid - 1;
//             } else lo = mid + 1;
//         }
//         printf("%lld\n", ans);
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T = ll>
inline T read() {
    T x = 0; int f = 1; char c = getchar();
    while (c != '-' && !isdigit(c)) c = getchar();
    if (c == '-') f = -1, c = getchar();
    while (isdigit(c)) { x = x * 10 + (c - '0'); c = getchar(); }
    return x * f;
}

bool feasible(ll T, int n, ll m, ll k, ll p, const vector<ll>& a) {
    ll S = 0;
    vector<ll> fi(n), ri(n);
    for (int i = 0; i < n; ++i) {
        fi[i] = a[i] / k;
        ri[i] = a[i] % k;      
        S += min<ll>(fi[i], T);
    }
    ll cap = T * p;

    if (S >= cap) {
        return cap * k >= m;
    }


    ll L = cap - S;
    vector<ll> residuals;
    residuals.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (ri[i] > 0 && fi[i] < T) residuals.push_back(ri[i]);
    }
    sort(residuals.begin(), residuals.end(), greater<ll>());

    ll total = S * k;
    int take = (int)min<ll>(L, residuals.size());
    for (int i = 0; i < take; ++i) total += residuals[i];

    return total >= m;
}

int main() {
    int Tcases = read<int>();
    while (Tcases--) {
        int n = read<int>();
        ll m = read<ll>();
        ll k = read<ll>();
        ll p = read<ll>();
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) a[i] = read<ll>();


        ll lo = 1, hi = (m + k - 1) / k + 2000;
        ll ans = hi;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            if (feasible(mid, n, m, k, p, a)) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
