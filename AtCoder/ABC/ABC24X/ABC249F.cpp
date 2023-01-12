#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template < typename T = int >
inline T read(void);

int N, K;
ll sum(0);
ll ans(LONG_LONG_MIN);
int mp[210000];
struct Pair{int first, second;};
basic_string < Pair > opt;
basic_string < int > _data;

class SegTree{
private:
    int tr[210000 << 2];
    ll sum[210000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){
        tr[p] = tr[LS] + tr[RS];
        sum[p] = sum[LS] + sum[RS];
    }
    void Modify(int pos, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p]++, sum[p] += mp[pos], void();
        if(pos <= MID)Modify(pos, LS, gl, MID);
        else Modify(pos, RS, MID + 1, gr);
        Pushup(p);
    }
    ll Query(int K, int p = 1, int gl = 1, int gr = N){
        if(tr[p] <= K)return sum[p];
        if(gl == gr)return 0;
        if(tr[LS] > K)return Query(K, LS, gl, MID);
        else return sum[LS] + Query(K - tr[LS], RS, MID + 1, gr);
    }
}st;

int main(){
    // freopen("in.txt", "r", stdin);
    N = read(), K = read();
    opt += {1, 0};
    for(int i = 1; i <= N; ++i){
        int f = read(), v = read();
        opt += {f, v};
        if(f == 2)_data += v;
    }sort(_data.begin(), _data.end());
    _data.erase(unique(_data.begin(), _data.end()), _data.end());
    // N = _data.size();
    for(auto &op : opt){
        if(op.first == 1)continue;
        int dis = distance(_data.begin(), upper_bound(_data.begin(), _data.end(), op.second));
        mp[dis] = op.second, op.second = dis;
    }
    for(auto it = opt.rbegin(); it != opt.rend(); ++it){
        if(it->first == 1){
            ans = max(ans, (ll)it->second + sum - st.Query(K--));
            if(K < 0)break;
            // printf("cur, ans = %lld\n", it->second + sum - st.Query(K + 1));
        }else{
            sum += mp[it->second];
            if(mp[it->second] < 0)st.Modify(it->second);
        }
    }printf("%lld\n", ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
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