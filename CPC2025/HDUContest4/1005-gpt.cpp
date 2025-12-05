#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const ll MOD = 998244353;

template<typename T=int>
inline T read(){
    T x=0; int f=1; char c=getchar();
    while(c!='-' && !isdigit(c)) c=getchar();
    if(c=='-'){ f=-1; c=getchar(); }
    while(isdigit(c)){ x = x*10 + (c-'0'); c=getchar(); }
    return x*f;
}

struct Edge {
    Edge* nxt;
    int to;
} ed[61000];
Edge* head[310];
int ed_cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) Precompute inverses up to 300
    static ll inv[310];
    auto qpow = [&](ll a, ll b){
        ll r=1, m=a%MOD;
        while(b){
            if(b&1) r = r*m % MOD;
            m = m*m % MOD;
            b >>= 1;
        }
        return r;
    };
    inv[0]=1;
    for(int i=1;i<310;i++) inv[i] = qpow(i, MOD-2);

    int T = read();
    while(T--){
        int N = read();
        string S;
        cin >> S;

        // --- 读树结构 ---
        // reset
        ed_cnt = 0;
        for(int i=1;i<=N;i++){
            head[i] = nullptr;
        }
        static int deg_son[310], fa[310];
        static bitset<310> isRoot;
        isRoot.set();
        isRoot[0]=0;

        memset(deg_son,0,sizeof deg_son);
        memset(fa,0,sizeof fa);

        // read children
        for(int u=1;u<=N;u++){
            int k = read();
            deg_son[u] = k;
            if(k>0){
                while(k--){
                    int v = read();
                    // add edge u->v
                    ed[ed_cnt].to = v;
                    ed[ed_cnt].nxt = head[u];
                    head[u] = &ed[ed_cnt++];
                    fa[v] = u;
                    isRoot[v] = 0;
                }
            } else {
                // leaf
                // nothing special here
                // but deg_son[u]==0 later used
            }
        }
        int root = isRoot._Find_first();

        // --- 正向 DP 状态 (p, j) 以及 root 单独一个量 ---
        // f_cur[p][j]: 当前位置在 p 且 p 在父亲排列中的下标 = j 的概率（模意义下）
        static ll f_cur[310][310], f_nxt[310][310];
        // 0 ≤ j ≤ deg_son[fa[p]]; 对于 root 我们不放到此表，用 F_root
        ll F_root = 1, F_root_next;

        // 初始：除 root 之外，全是 0
        for(int p=1;p<=N;p++){
            int kp = deg_son[ fa[p] ];
            for(int j=1;j<=kp;j++){
                f_cur[p][j] = 0;
            }
        }

        // 逐步把 S 中的每个指令“线性地”作用到 (f_cur, F_root) → (f_nxt, F_root_next)
        for(char c: S){
            // 清空 f_nxt
            for(int p=1;p<=N;p++){
                int kp = deg_son[ fa[p] ];
                for(int j=1;j<=kp;j++){
                    f_nxt[p][j] = 0;
                }
            }
            F_root_next = 0;

            if(c=='L'){
                // L: 在 root 上什么也不变；在 p≠root 上，(p,j)->(p,1) if j=1
                //             else (p,j)->对每个兄弟 q≠p 均匀走到 (q,j-1)
                F_root_next = F_root;
                for(int p=1;p<=N;p++){
                    if(p==root) continue;
                    int u = fa[p];
                    int kp = deg_son[u];    // 父亲的度
                    if(kp==0) continue;     // 说明这 p 本身是 root，已跳过
                    for(int j=1;j<=kp;j++){
                        ll v = f_cur[p][j];
                        if(!v) continue;
                        if(j==1){
                            // stay
                            f_nxt[p][1] = (f_nxt[p][1] + v) % MOD;
                        } else {
                            // 均匀分给 u 的其他 k−1 个孩子
                            ll t = v * inv[kp-1] % MOD;
                            for(Edge* e = head[u]; e; e=e->nxt){
                                int q = e->to;
                                if(q==p) continue;
                                f_nxt[q][j-1] = (f_nxt[q][j-1] + t) % MOD;
                            }
                        }
                    }
                }
            }
            else if(c=='R'){
                // R: (p,j)->(p,k) if j=k; else (p,j)->对每个兄弟 q≠p 均匀走到 (q,j+1)
                F_root_next = F_root;
                for(int p=1;p<=N;p++){
                    if(p==root) continue;
                    int u = fa[p], kp = deg_son[u];
                    if(kp==0) continue;
                    for(int j=1;j<=kp;j++){
                        ll v = f_cur[p][j];
                        if(!v) continue;
                        if(j==kp){
                            f_nxt[p][kp] = (f_nxt[p][kp] + v) % MOD;
                        } else {
                            ll t = v * inv[kp-1] % MOD;
                            for(Edge* e = head[u]; e; e=e->nxt){
                                int q = e->to;
                                if(q==p) continue;
                                f_nxt[q][j+1] = (f_nxt[q][j+1] + t) % MOD;
                            }
                        }
                    }
                }
            }
            else { // c=='D'
                // D: non-leaf p → 均匀跳到自己孩子列表中下标=1的那条 (q,1)
                //    leaf p → (p,j) 不变
                // 同样 root 也是“非叶子”或“叶子”分开处理
                // 先处理 root
                if(deg_son[root]==0){
                    // root 是叶子，D 不动
                    F_root_next = (F_root_next + F_root) % MOD;
                } else {
                    // root 有孩子
                    ll P = F_root;
                    ll invk = inv[ deg_son[root] ];
                    for(Edge* e=head[root]; e; e=e->nxt){
                        int q = e->to;
                        f_nxt[q][1] = (f_nxt[q][1] + P*invk) % MOD;
                    }
                }
                // 再处理 p≠root
                for(int p=1;p<=N;p++){
                    if(p==root) continue;
                    if(deg_son[p]==0){
                        // 叶子：所有 (p,j) 保持
                        int kp = deg_son[ fa[p] ];
                        for(int j=1;j<=kp;j++){
                            f_nxt[p][j] = (f_nxt[p][j] + f_cur[p][j]) % MOD;
                        }
                    } else {
                        // 非叶：先把 p 上所有质量 P 收起来
                        ll P = 0;
                        int kpar = deg_son[ fa[p] ];
                        for(int j=1;j<=kpar;j++){
                            P = (P + f_cur[p][j]) % MOD;
                        }
                        // 再均匀分给 p 的孩子们，新的 j=1
                        ll invk = inv[ deg_son[p] ];
                        for(Edge* e = head[p]; e; e=e->nxt){
                            int q = e->to;
                            f_nxt[q][1] = (f_nxt[q][1] + P*invk) % MOD;
                        }
                    }
                }
            }

            // step 完成，交换
            F_root = F_root_next;
            for(int p=1;p<=N;p++){
                int kp = deg_son[ fa[p] ];
                for(int j=1;j<=kp;j++){
                    f_cur[p][j] = f_nxt[p][j];
                }
            }
        } // end for c in S

        // --- 汇总答案 E[ final_node ] ---
        ll ans = F_root * root % MOD;
        for(int p=1;p<=N;p++){
            if(p==root) continue;
            ll sumj = 0;
            int kp = deg_son[ fa[p] ];
            for(int j=1;j<=kp;j++){
                sumj = (sumj + f_cur[p][j]) % MOD;
            }
            ans = (ans + sumj * p) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
