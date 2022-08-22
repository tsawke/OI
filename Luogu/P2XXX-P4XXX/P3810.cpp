#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define MID(l, r) ((l + r) >> 1)

template<typename T = int>
inline T read(void);

class TreeArray{
    private:
        int N;
        int t[210000];
    public:
        void setLim(int lim){this->N = lim;}
        int lowbit(int x){return x & (-x);}
        void add(int x, int v){while(x <= this->N){this->t[x] += v; x += this->lowbit(x);}}
        int query(int x){int ret(0); while(x){ret += this->t[x]; x -= this->lowbit(x);} return ret;}
        void clear(void){for(int i = 1; i <= this->N; ++i)this->t[i] = 0;}
        void Print(void){for(int i = 1; i <= this->N; ++i)printf("%d%c", this->t[i], i == this->N ? '\n' : ' ');}
};
int N, k;
struct Element{
    int a, b, c;
    int cnt;
    int ans;
    void Init(void){this->a = read(), this->b = read(), this->c = read(); this->cnt = 1; this->ans = 0;}
    void operator=(const Element f){this->a = f.a, this->b = f.b, this->c = f.c; this->cnt = f.cnt; this->ans = f.ans;}
    const bool operator==(const Element f){return this->a == f.a && this->b == f.b && this->c == f.c;}
}tmp[110000], arr[110000];
bool cmpByA(Element x, Element y){if(x.a == y.a && x.b == y.b)return x.c < y.c; if(x.a == y.a)return x.b < y.b; return x.a < y.a;}
bool cmpByB(Element x, Element y){if(x.a == y.a && x.b == y.b)return x.c < y.c; if(x.b == y.b)return x.a < y.a; return x.b < y.b;}
bool cmpByC(Element x, Element y){if(x.a == y.a && x.c == y.c)return x.b < y.b; if(x.c == y.c)return x.a < y.a; return x.c < y.c;}
int anss[110000];
void CDQ(int, int);
TreeArray T;
int main(){
    // (void)!freopen("P3810_2.in", "r", stdin);
    N = read(), k = read();
    T.setLim(k);
    for(int i = 1; i <= N; ++i)tmp[i].Init();
    sort(tmp + 1, tmp + N + 1, cmpByA);
    int cnt(0);
    for(int i = 1; i <= N; ++i){
        if(i == 1){arr[i] = tmp[i]; ++cnt; continue;}
        if(tmp[i] == arr[cnt])arr[cnt].cnt++;
        else arr[++cnt] = tmp[i];
    }
    int _N = cnt;
    CDQ(1, _N);
    for(int i = 1; i <= _N; ++i){
        anss[arr[i].ans + arr[i].cnt - 1] += arr[i].cnt;
    }
    for(int i = 0; i <= N - 1; ++i)printf("%d\n", anss[i]);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
void CDQ(int l, int r){
    if(l == r)return;
    int mid(MID(l, r));
    CDQ(l, mid);
    CDQ(mid + 1, r);
    int Lptr = l;
    int Rptr = mid + 1;
    while(Rptr <= r){
        while(Lptr <= mid && arr[Lptr].b <= arr[Rptr].b){
            T.add(arr[Lptr].c, arr[Lptr].cnt);
            ++Lptr;
        }
        arr[Rptr].ans += T.query(arr[Rptr].c);
        ++Rptr;
    }
    for(int i = l; i <= Lptr - 1; ++i)T.add(arr[i].c, -arr[i].cnt);
    inplace_merge(arr + l, arr + mid + 1, arr + r + 1, cmpByB);
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