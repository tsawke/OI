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

#define EPS (1e-6)

template < typename T = int >
inline T read(void);

int N, A;
int w[2100], x[2100], v[2100];
double l[2100], r[2100];
int d[4100];
int ans(0);
basic_string < double > _data;

int main(){
    // freopen("in.txt", "r", stdin);
    N = read(), A = read();
    for(int i = 1; i <= N; ++i)w[i] = read(), x[i] = read(), v[i] = read();
    for(int i = 1; i <= N; ++i){
        ans = max(ans, w[i]);
        memset(d, 0, sizeof d), _data.clear();
        for(int j = 1; j <= N; ++j){
            if(i == j)continue;
            if(v[i] == v[j]){
                if(0 <= x[j] - x[i] && x[j] - x[i] <= A)l[j] = 0, r[j] = 1e9;
                else l[j] = r[j] = 0;
            }else if(v[j] > v[i]){
                l[j] = (double)(x[i] - x[j]) / (v[j] - v[i]), r[j] = (double)(x[i] - x[j] + A) / (v[j] - v[i]) + EPS;
            }else
                r[j] = (double)(x[i] - x[j]) / (v[j] - v[i]) + EPS, l[j] = (double)(x[i] - x[j] + A) / (v[j] - v[i]);
            l[j] = max(l[j], 0.0), r[j] = max(r[j], 0.0);
            _data += {l[j], r[j]};
        }
        sort(_data.begin(), _data.end());
        _data.erase(unique(_data.begin(), _data.end()), _data.end());
        for(int j = 1; j <= N; ++j){
            if(i == j)continue;
            d[distance(_data.begin(), next(lower_bound(_data.begin(), _data.end(), l[j])))] += w[j];
            d[distance(_data.begin(), next(lower_bound(_data.begin(), _data.end(), r[j])))] -= w[j];
        }
        for(int j = 1; j <= (int)_data.size(); ++j)ans = max(ans, (d[j] += d[j - 1]) + w[i]);
    }printf("%d\n", ans);

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