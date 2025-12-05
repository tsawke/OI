#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int c2d(char c){
    if(isdigit(c))return c - '0';
    if(isupper(c))return c - 'A' + 10;
    if(islower(c))return c - 'a' + 36;
    return -1;
}

struct Trie{
    Trie* son[65];
    int val;
    int times;
    Trie(int val, int times = 0):val(val), times(times){;}
    Trie(void) = default;
    void* operator new(size_t);
}tData[3100000];
static Trie* P = tData;
Trie* root = new Trie(0);

void* Trie::operator new(size_t){return ++P;}
void Clear(void){memset(tData, 0, (P - tData + 1) * sizeof(tData[0])); P = tData; root = new Trie(0);}



int N, Q;

void Insert(string str){
    Trie* ptr = root;
    // int cnt(0);
    for(auto c : str){
        int v = c2d(c);
        if(!ptr->son[v])ptr->son[v] = new Trie(v);
        // if(c == *(str.end() - 1))ptr->son[v]->times++;
        // if(++cnt == (int)str.size())ptr->son[v]->times++;
        ptr = ptr->son[v];
        ptr->times++;
    }
}
// int QuerySub(Trie* p){
//     int ret = p->times;
//     for(int i = 1; i <= 62; ++i)ret += p->son[i] ? QuerySub(p->son[i]) : 0;
//     return ret;
// }
int Query(string str){
    Trie* ptr = root;
    for(auto c : str){
        int v = c2d(c);
        if(!ptr->son[v])return 0;
        ptr = ptr->son[v];
    }
    // return QuerySub(ptr);
    return ptr->times;
}

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T = read();
    while(T--){
        Clear();
        N = read(), Q = read();
        string str;
        while(N--)cin >> str, Insert(str);
        while(Q--)cin >> str, printf("%d\n", Query(str));
    }



    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



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