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

int b[1100];
int cur[1100];
int N;

vector < pair < int, int > > ans;

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read();
    for(int i = 1; i <= N; ++i)b[i] = read();
    // int mid = (N + 1) >> 1;
    // for(int i = 1; i <= N; ++i)
    //     if(b[i] > mid)printf("2 %d\n", i), ++cur[i];
    auto Solve = [](auto&& self, int l, int r) -> void{
        // printf("Solving l = %d, r = %d\n", l, r);
        if(l == r){
            for(int i = 1; i <= N; ++i)
                if(b[i] == l)
                    while(cur[i] < b[i])
                    ans.push_back({2, i}), ++cur[i];//printf("2 %d\n", i), ++cur[i];
            return;
        }
        if(l > r)return;
        int mid = (l + r) >> 1;
        vector < int > idx;
        for(int i = 1; i <= N; ++i)
            if(mid < b[i] && b[i] <= r)
               idx.push_back(i), ans.push_back({2, i}), ++cur[i]; //idx += i, printf("2 %d\n", i), ++cur[i];
        // printf("In[%d, %d], siz = %d\n", l, r, idx.size());
        if(idx.size()){
            while(cur[*idx.begin()] < mid)
                ans.push_back({1, cur[*idx.begin()]}), ++cur[*idx.begin()];//printf("1 %d\n", cur[*idx.begin()]), ++cur[*idx.begin()];
            for(auto p : idx)cur[p] = mid;
        }
        self(self, mid + 1, r);
        self(self, l, mid);
    }; Solve(Solve, 1, N);
    printf("%d\n", ans.size());
    for(auto [a, b] : ans)printf("%d %d\n", a, b);

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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