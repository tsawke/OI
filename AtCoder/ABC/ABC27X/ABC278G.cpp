#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



// template < typename T = int >
// inline T read(void);

int N, L, R;
int SG[2100];
int curSG(0);

struct Node{
    int l, r;
    friend const bool operator < (const Node &a, const Node &b){
        return a.l < b.l;
    }
};

class ODT{
private:
    set < Node > tr;
public:
    auto Insert(Node p){return tr.insert(p).first;}
    // auto Split(int p){
    //     auto it = tr.lower_bound(Node{p});
    //     if(it != tr.end() && it->l == p)return it;
    //     if(p > it->r)return tr.end();
    //     advance(it, -1);
    //     auto l = it->l, r = it->r;
    //     tr.erase(it);
    //     Insert(Node{l, p - 1});
    //     return Insert(Node{p, r});
    // }
    void Erase(int l, int r){
        auto it = tr.lower_bound(Node{l});
        if(it == tr.end() || it->l != l)advance(it, -1);
        curSG ^= SG[it->r - it->l + 1];
        // printf("EEEErase curSG = %d\n", curSG);
        auto itL = it->l, itR = it->r;
        // printf("Erase L = %d, R = %d, l = %d, r = %d\n", itL, itR, l, r);
        tr.erase(it);
        if(itL == l){
            if(itR != r){
                curSG ^= SG[itR - r - 1 + 1];
                // printf("xor = %d\n", SG[itR - r - 1 + 1]);
                Insert(Node{r + 1, itR});
            }
        }else{
            curSG ^= SG[l - 1 - itL + 1];
            // printf("xor = %d\n", SG[l - 1 - itL + 1]);
            Insert(Node{itL, l - 1});
            if(itR != r){
                curSG ^= SG[itR - r - 1 + 1];
                // printf("xor = %d\n", SG[itR - r - 1 + 1]);
                Insert(Node{r + 1, itR});
            }
        }
    }
    void FindAndErase(void){
        for(auto it = tr.begin(); it != tr.end(); advance(it, 1)){
            int siz = it->r - it->l + 1;
            if(siz < L)continue;
            for(int i = 0; i + L <= siz; ++i){
                // if(it->l + i == 250)printf("Completely find!, curSG = %d, siz = %d, val = %d, i = %d\n", curSG, siz, SG[siz] ^ SG[i] ^ SG[siz - L - i], i);
                if((curSG ^ SG[siz] ^ SG[i] ^ SG[siz - L - i]) == 0){
                    // printf("Answer, curSG = %d, siz = %d, val = %d, i = %d\n", curSG, siz, SG[siz] ^ SG[i] ^ SG[siz - L - i], i);
                    auto itl = it->l, itr = it->r;
                    // cout << itl + i << " " << itl + i + L - 1 << endl;
                    cout << itl + i << " " << L << endl;
                    tr.erase(it);
                    if(i)Insert(Node{itl, itl + i - 1});
                    if(siz - L - i)Insert(Node{itr - (siz - L - i) + 1, itr});
                    curSG = 0;
                    return;
                }
            }
        }
    }
}odt;

int main(){
    // N = read(), L = read(), R = read();
    cin >> N >> L >> R;
    if(L != R || (L == R && !((L ^ N) & 1))){
        cout << "First" << endl;
        int mid;
        if(N & 1){
            int len = L + (!(L & 1) ? 1 : 0);
            len >>= 1;
            mid = (N >> 1) + 1;
            // cout << mid - len << " " << mid + len << endl;
            cout << mid - len << " " << ((len << 1) | 1) << endl;
        }else{
            int len = L + (L & 1 ? 1 : 0);
            len >>= 1;
            mid = (N >> 1);
            // cout << mid - len + 1 << " " << mid + len << endl;
            cout << mid - len + 1 << " " << (len << 1) << endl;
        }
        while(true){
            int l, r; cin >> l >> r;
            if((!l && !r) || (!~l && !~r))break;
            r = l + r - 1;
            if(N & 1)
                // cout << 2 * mid - r << " " << 2 * mid - l << endl;
                cout << 2 * mid - r << " " << (2 * mid - l) - (2 * mid - r) + 1 << endl;
            else
                // cout << 2 * mid + 1 - r << " " << 2 * mid + 1 - l << endl;
                cout << 2 * mid + 1 - r << " " << (2 * mid + 1 - l) - (2 * mid + 1 - r) + 1 << endl;
        }
    }else{
        for(int l = L; l <= N; ++l){
            bitset < 2100 > ext;
            for(int i = 0; i + L <= l; ++i){
                int pos = SG[i] ^ SG[l - L - i];
                ext[pos] = true;
            }
            while(ext[SG[l]])++SG[l];
        }
        // for(int i = N - 100; i <= N; ++i)printf("%d ", SG[i]);
        // printf("\n");
        cout << (SG[N] ? "First" : "Second") << endl;
        odt.Insert(Node{1, N});
        curSG = SG[N];
        if(SG[N])
            for(int i = 0; i + L <= N; ++i)
                if(!(SG[i] ^ SG[N - L - i])){
                    // printf("len is %d, %d\n", i, N - L - i);
                    odt.Erase(1 + i, 1 + i + L - 1);
                    // cout << 1 + i << " " << 1 + i + L - 1 << endl;
                    cout << 1 + i << " " << L << endl;
                    break;
                }
        // printf("After del SG = %d\n", curSG);
        while(true){
            int l, r; cin >> l >> r;
            if((!l && !r) || (!~l && !~r))break;
            r = l + r - 1;
            odt.Erase(l, r);
            odt.FindAndErase();
        }
    }
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

// template < typename T >
// inline T read(void){
//     T ret(0);
//     int flag(1);
//     char c = getchar();
//     while(c != '-' && !isdigit(c))c = getchar();
//     if(c == '-')flag = -1, c = getchar();
//     while(isdigit(c)){
//         ret *= 10;
//         ret += int(c - '0');
//         c = getchar();
//     }
//     ret *= flag;
//     return ret;
// }