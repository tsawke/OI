#define USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

typedef long long ll;
typedef unsigned long long unll;
typedef unsigned int uint;
typedef long double ld;

template < typename T = int >
T read(void);

int N, M;
int a[110000];
// bool vis[110000];
bitset < 101000 > vis;
// int buc100[1100][110000];
// vector < int > arr;
int main(){
    freopen("interval.in", "r", stdin);
    freopen("interval.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    // sort(arr.begin(), arr.end());
    // for(int i = 1; i <= N; ++i)a[i] = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), a[i])) + 1;
    // for()
    if(M <= 1000){
        while(M--){
            int l = read(), r = read(), x = read(), y = read();
            int ans1(0), ans2(0);
            vis.reset();
            for(int i = l; i <= r; ++i){
                if(x <= a[i] && a[i] <= y){
                    ++ans1;
                    if(!vis[a[i]])vis.set(a[i]), ++ans2;
                }
            }
            printf("%d %d\n", ans1, ans2);
        }
        return 0;
    }
    if(N <= 1000){
        while(M--){
            int l = read(), r = read(), x = read(), y = read();
            int ans1(0);
            vector < int > tmp;
            for(int i = l; i <= r; ++i)
                if(x <= a[i] && a[i] <= y)++ans1, tmp.push_back(a[i]);
            auto endpos = unique(tmp.begin(), tmp.end());
            printf("%d %d\n", ans1, (int)distance(tmp.begin(), endpos));
        }
        return 0;
    }

    return 0;
}

template < typename T >
T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }ret *= flag;
    return ret;
}