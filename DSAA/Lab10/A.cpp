#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

using ll = long long;
using unll = unsigned long long;
using ld = long double;

template < typename T = int >
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c))c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c))ret = ret * 10 + (c - '0'), c = getchar();
    return ret * flag;
}

struct Node{
    Node *ls, *rs;
    int val;
    int siz;
    int cnt;
    int h;
};

Node* root = nullptr;

#define siz(p)    ((p) ? (p)->siz : 0)
#define height(p) ((p) ? (p)->h   : 0)

class Tree{
public:
    // 维护子树大小和高度
    void Pushup(Node* p){
        if(!p) return;
        p->siz = siz(p->ls) + siz(p->rs) + p->cnt;
        p->h   = max(height(p->ls), height(p->rs)) + 1;
    }

    // 平衡因子 = 左高 - 右高
    int GetBalance(Node* p){
        if(!p) return 0;
        return height(p->ls) - height(p->rs);
    }

    // 右旋
    Node* RotateRight(Node* y){
        Node* x  = y->ls;
        Node* T2 = x->rs;
        x->rs = y;
        y->ls = T2;
        Pushup(y);
        Pushup(x);
        return x;
    }

    // 左旋
    Node* RotateLeft(Node* x){
        Node* y  = x->rs;
        Node* T2 = y->ls;
        y->ls = x;
        x->rs = T2;
        Pushup(x);
        Pushup(y);
        return y;
    }

    Node* QueryMx(Node* p = root){
        if(!p) return p;
        while(p->rs) p = p->rs;
        return p;
    }

    Node* QueryMn(Node* p = root){
        if(!p) return p;
        while(p->ls) p = p->ls;
        return p;
    }

    // AVL 插入，返回当前子树的新根
    Node* Insert(int val, Node* p = root){
        if(!p) return new Node(val);

        if(val < p->val){
            p->ls = Insert(val, p->ls);
        }else if(val > p->val){
            p->rs = Insert(val, p->rs);
        }else{
            // 多重集：相同键只增加 cnt
            ++p->cnt;
            Pushup(p);
            return p;
        }

        // 回溯更新高度和 size
        Pushup(p);

        int bf = GetBalance(p);

        // 四种失衡情况

        // LL
        if(bf > 1 && val < p->ls->val)
            return RotateRight(p);

        // RR
        if(bf < -1 && val > p->rs->val)
            return RotateLeft(p);

        // LR
        if(bf > 1 && val > p->ls->val){
            p->ls = RotateLeft(p->ls);
            return RotateRight(p);
        }

        // RL
        if(bf < -1 && val < p->rs->val){
            p->rs = RotateRight(p->rs);
            return RotateLeft(p);
        }

        return p;
    }

    // AVL 删除，返回当前子树的新根
    Node* Delete(int val, Node* p = root){
        if(!p) return p;

        if(val < p->val){
            p->ls = Delete(val, p->ls);
        }else if(val > p->val){
            p->rs = Delete(val, p->rs);
        }else{
            // 找到要删的结点
            if(p->cnt > 1){
                // 多重集：有多个，先减一
                --p->cnt;
            }else if(!p->ls || !p->rs){
                // 度为 0 或 1
                Node* tmp = p->ls ? p->ls : p->rs;
                if(!tmp){
                    delete p;
                    return nullptr;
                }else{
                    Node* old = p;
                    p = tmp;
                    delete old;
                }
            }else{
                // 度为 2：用右子树最小结点(后继)顶替
                Node* succ = QueryMn(p->rs);
                // 把后继的键值和计数整体搬上来
                p->val = succ->val;
                p->cnt = succ->cnt;
                // 让真正的后继结点只剩 1 个, 方便彻底删掉它
                succ->cnt = 1;
                // 在右子树里删掉这个后继结点
                p->rs = Delete(succ->val, p->rs);
            }
        }

        // 子树被删空
        if(!p) return p;

        // 回溯维护高度和 size
        Pushup(p);

        int bf = GetBalance(p);

        // 左高：可能 LL 或 LR
        if(bf > 1){
            if(GetBalance(p->ls) >= 0){
                // LL
                return RotateRight(p);
            }else{
                // LR
                p->ls = RotateLeft(p->ls);
                return RotateRight(p);
            }
        }

        // 右高：可能 RR 或 RL
        if(bf < -1){
            if(GetBalance(p->rs) <= 0){
                // RR
                return RotateLeft(p);
            }else{
                // RL
                p->rs = RotateRight(p->rs);
                return RotateLeft(p);
            }
        }

        return p;
    }

    // 查询有多少数 < val
    int QueryRnk(int val, Node* p = root){
        if(!p) return 0;
        if(val == p->val) return siz(p->ls);
        if(val < p->val)  return QueryRnk(val, p->ls);
        return siz(p->ls) + p->cnt + QueryRnk(val, p->rs);
    }

    // 按排名查询：第 rnk 小的结点
    Node* QueryByRnk(int rnk, Node* p = root){
        if(!p) return p;
        if(rnk <= siz(p->ls)) return QueryByRnk(rnk, p->ls);
        if(rnk <= siz(p->ls) + p->cnt) return p;
        return QueryByRnk(rnk - siz(p->ls) - p->cnt, p->rs);
    }

    // 后继：严格大于 val 的最小值
    Node* QuerySuc(int val, Node* p = root){
        if(!p) return p;
        if(val >= p->val) return QuerySuc(val, p->rs);
        Node* res = QuerySuc(val, p->ls);
        return res ? res : p;
    }

    // 前驱：严格小于 val 的最大值
    Node* QueryPre(int val, Node* p = root){
        if(!p) return p;
        if(val <= p->val) return QueryPre(val, p->ls);
        Node* res = QueryPre(val, p->rs);
        return res ? res : p;
    }
}tr;

// 先序遍历计算校验和：
// ans += (idx ^ |val|), idx 从 1 开始
void PreOrderChecksum(Node* p, unsigned int &idx, unsigned int &ans){
    if(!p) return;
    ans += (idx ^ (unsigned int)std::abs(p->val));
    ++idx;
    PreOrderChecksum(p->ls, idx, ans);
    PreOrderChecksum(p->rs, idx, ans);
}

int main(){
    int T = read<int>();
    while(T--){
        int opt = read<int>(), val = read<int>();
        switch(opt){
            case 1:
                root = tr.Insert(val, root);
                break;
            case 2:
                root = tr.Delete(val, root);
                break;
            case 3:
                printf("%d\n", tr.QueryRnk(val, root) + 1);
                break;
            case 4:{
                Node* p = tr.QueryByRnk(val, root);
                printf("%d\n", p->val);
                break;
            }
            case 5:{
                Node* p = tr.QueryPre(val, root);
                printf("%d\n", p->val);
                break;
            }
            case 6:{
                Node* p = tr.QuerySuc(val, root);
                printf("%d\n", p->val);
                break;
            }
        }
    }

    // 如果题目要求输出 AVL 校验和，则保留下面这段
    // 如果不需要校验和，可以直接删掉
    unsigned int idx = 1;
    unsigned int ans = 0;
    PreOrderChecksum(root, idx, ans);
    printf("%u\n", ans);

    return 0;
}
