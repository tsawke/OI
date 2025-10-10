#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int>
inline T read(void);

auto qpow = [](ll a, ll b, ll mod)->ll{
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = (ret * mul) % mod;
        b >>= 1, mul = (mul * mul) % mod;
    }return ret;
};

int N, Q, B;

class LengthContainer{
private:
    multiset < int > lens;
    vector < ll > curG;
    ll len0;
    
public:
    int prel, sufl, mxl;
    ll Cal(int b, int len){
        if(len <= (b << 1))return 0;
        int num = len - (b << 1), div = (b << 1) | 1;
        return (num + div - 1) / div;
    }
    void InsertLen(int len){
        if(len <= 0)return;
        len0 += len;
        lens.insert(len);
        if(lens.size()){
            auto it = prev(lens.end());
            if(!lens.empty())mxl = max(mxl, *it);
            mxl = max(mxl, len);
        }else mxl = max(mxl, len);
        for(int b = 0; b <= B; ++b)curG[b] += Cal(b, len);
    }
    void RemoveLen(int len){
        if(len <= 0)return;
        len0 -= len;
        auto it = lens.find(len);
        if(it != lens.end())lens.erase(it);
        for(int b = 0; b <= B; ++b)curG[b] -= Cal(b, len);
        mxl = lens.empty() ? 0 : *prev(lens.end());
    }
    ll Query(void){
        if(!len0)return 0;
        ll ans(LONG_LONG_MAX >> 2);
        int lmx = max(mxl, prel + sufl);
        ans = min(ans, (ll)((lmx + 1) >> 1));
        if(len0 == N){
            for(int b = 0; b <= B; ++b){
                ll val = b + 1 + Cal(b, N - 1);
                if(val < ans)ans = val;
            }
            return ans;
        }
        for(int b = 0; b <= B; ++b){
            ll res(0);
            if(prel > 0 && sufl > 0) res = Cal(b, prel + sufl) - Cal(b, prel) - Cal(b, sufl);
            ll val = (ll)b + curG[b] + res;
            if(val < ans)ans = val;
        }return ans;
    }
    void Clear(void){
        lens.clear();
        curG.assign(B + 1, 0);
        len0 = prel = sufl = mxl = 0;
    }
}lc;


struct Node{
    int l, r;
    int size(void)const{return r - l + 1;}
    mutable ll val;
    friend const bool operator < (const Node &x, const Node &y){return x.l < y.l;}
};

class ODT{
private:
    set < Node > tr;
public:
    auto Insert(Node p){return tr.insert(p);}
    auto Split(int p){
        auto it = tr.lower_bound(Node{p});
        if(it != tr.end() && p == it->l)return it;
        if(it == tr.begin()) return tr.end();
        --it;
        if(p > it->r)return tr.end();
        int l = it->l, r = it->r;
        ll val = it->val;
        if(!val) lc.RemoveLen(r - l + 1);
        tr.erase(it);
        if(l <= p - 1){
            Insert(Node{l, p - 1, val});
            if(!val) lc.InsertLen(p - 1 - l + 1);
        }
        auto ret = Insert(Node{p, r, val}).first;
        if(!val)lc.InsertLen(r - p + 1);
        return ret;
    }
    void Modify(int l, int r, ll val){
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR; ++it)it->val += val;
    }
    void Assign(int l, int r, ll val){
        auto itR = Split(r + 1), itL = Split(l);
        tr.erase(itL, itR);
        Insert(Node{l, r, val});
    }
    ll QueryKth(int l, int r, int k){
        vector < Node > rnk;
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR; ++it)rnk.push_back(*it);
        sort(rnk.begin(), rnk.end(), [](const Node x, const Node y)->bool{return x.val < y.val;});
        int cur(0);
        for(auto i : rnk){
            cur += i.size();
            if(cur >= k)return i.val;
        }
        return -1;
    }
    ll QuerySum(int l, int r, ll k, ll mod){
        ll ret(0);
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR; ++it)
            ret = (ret + qpow(it->val, k, mod) * it->size() % mod) % mod;
        return ret;
    }
    void Build(const vector < ll > &A){
        tr.clear();
        for(int i = 1; i <= N;){
            int cur(i);
            while(cur + 1 <= N && A[cur + 1] == A[i])++cur;
            Insert(Node{i, cur, A[i]});
            i = cur + 1;
        }
    }

    void Assign01(int l, int r, int val){
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR; ++it)
            if(!it->val)lc.RemoveLen(it->size());
        tr.erase(itL,itR);
        if(val == 1){
            auto it = tr.lower_bound(Node{l});
            int L(l), R(r);
            if(it != tr.begin() && prev(it)->r == l - 1 && prev(it)->val == 1)
                L = prev(it)->l, tr.erase(prev(it));
            it = tr.lower_bound(Node{r + 1});
            if(it != tr.end() && it->l == r + 1 && it->val == 1)
                R = it->r, tr.erase(it);
            Insert(Node{L, R, 1});
        }else{
            auto it = tr.lower_bound(Node{l});
            int L(l), R(r);
            if(it != tr.begin() && prev(it)->r == l - 1 && prev(it)->val == 0)
                lc.RemoveLen(prev(it)->size()), L = prev(it)->l, tr.erase(prev(it));
            it = tr.lower_bound(Node{r + 1});
            if(it != tr.end() && it->l == r + 1 && it->val == 0)
                lc.RemoveLen(it->size()), R = it->r, tr.erase(it);
            Insert(Node{L, R, 0});
            lc.InsertLen(R - L + 1);
        }
    }
    void Maintain(){
        if(tr.empty()){lc.prel = lc.sufl = 0; return;}
        lc.prel = (tr.begin()->l == 1 && tr.begin()->val == 0) ? tr.begin()->size() : 0;
        lc.sufl = (prev(tr.end())->r == N && prev(tr.end())->val == 0) ? prev(tr.end())->size() : 0;
    }
    void Initialize(void){
        for(auto i : tr)
            if(i.val == 0)lc.InsertLen(i.size());
    }
}odt;

int main(){
    int T = read();
    while(T--){
        N = read(), Q = read();
        vector < ll > A(N + 10);
        string S; cin >> S;
        for(int i = 1; i <= N; ++i)A[i] = S.at(i - 1) - '0';

        odt.Build(A);
        B = (int)sqrt((double)N) + 1;

        lc.Clear();
        odt.Initialize();
        odt.Maintain();

        while(Q--){
            int opt = read(), l = read(), r = read();
            odt.Assign01(l, r, opt == 1 ? 1 : 0);
            odt.Maintain();
            printf("%lld\n", lc.Query());
        }
    }


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
