#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

#define abbr
#define lgst longest_len
#define trch translate_char_to_coord
#define gn GetNum

#define add(from, to, lgst) do{\
    head[from] = new Edge(head[from], to, lgst);\
}while(false)

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

int trch(char c){return int(c - 'a');}

int nSize(0);

struct Node{
    Node* link;
    int lgst;
    Node* nxt[26];
    void* operator new(size_t);
    Node(Node* linkk, int lgstt):link(linkk), lgst(lgstt){;}
    Node(void) = default;
}nData[2100000];
void* Node::operator new(size_t){
    static Node* P = nData; 
    ++nSize; 
    return ++P;}
Node *root, *last;

struct Edge{
    Edge* nxt;
    int to, lgst;
    void* operator new(size_t);
    Edge(Edge* _nxt, int _to, int _lgst):nxt(_nxt), to(_to), lgst(_lgst){;}
    Edge(void) = default;
}eData[2100000];
Edge* head[1100000];
void* Edge::operator new(size_t){static Edge* eP = eData; return ++eP;}

int GetNum(Node* p){return p - nData;}
void DescTree(int lim){
    for(int i = 0; i <= lim; ++i){
        printf("No.%d lgst = %d, link = %d\nnxt[]=>", i, nData[i].lgst, GetNum(nData[i].link));
        for(int j = 0; j <= 25; ++j)printf("%d ", nData[i].nxt[j] ? GetNum(nData[i].nxt[j]) : -1);
        printf("\n");
    }
}

void Build(void);
void ExtendSAM(char);
template<typename T = int>
inline T read(void);

int ans(INT_MIN);

// int dfs(Node* p = root){
//     bool hasSon(false);
//     int times(0);
//     for(int i = 0; i <= 25; ++i)if(p->nxt[i]){
//         times += dfs(p->nxt[i]);
//         hasSon = true;
//     }
//     if(!hasSon)return 1;
//     ans = max(ans, times * p->lgst);
//     return times;
// }
void ReBuild(void){
    for(int i = 0; i <= nSize; ++i){;
        add(gn(nData[i].link), i, nData[i].lgst);
    }
}
int dfs(int p = 0){
    if(!head[p])return 1;
    int sum(0);
    for(auto i = head[p]; i; i = i->nxt){
        sum += dfs(i->to);
    }
    ans = max(ans, sum);
    return sum * (nData + p)->lgst;
}
int main(){
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    string S;
    cin >> S;
    // len = S.size();
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    Build();
    for(auto i : S)ExtendSAM(i);
    ReBuild();
    dfs();
    printf("%d\n", ans);

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
void ExtendSAM(char c){
    int cp = trch(c);
    Node* cur = new Node(npt, last->lgst + 1);
    Node* p = last;
    while(p && !p->nxt[cp])p->nxt[cp] = cur, p = p->link;
    if(!p)cur->link = root;
    else{
        Node* nxt = p->nxt[cp];
        if(p->lgst + 1 == nxt->lgst)cur->link = nxt;
        else{
            Node* clone = new Node(nxt->link, p->lgst + 1);
            copy(nxt->nxt, nxt->nxt + 26, clone->nxt);
            while(p && p->nxt[cp] == nxt){p->nxt[cp] = clone; p = p->link;}
            nxt->link = cur->link = clone;
        }
    }
    last = cur;
}
void Build(void){root = new Node(npt, 0); last = root;}


template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c))c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}