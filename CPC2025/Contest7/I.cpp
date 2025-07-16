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

int L, N;
string S[110000];
bool exists[110000][30];

auto Cal = [](auto&& self, basic_string < int > idxs, bitset < 26 > used) -> void{
    // printf("In Cal, idxs = ");
    // for(auto i : idxs)printf("%d ", i);
    // printf("\n");
    if(idxs.size() <= 1)return;
    map < vector < int >, basic_string < int > > mp;
    int label = -1;
    for(int c = 0; c < 26; ++c){
        if(used[c])continue;
        bool flag(true);
        for(auto i : idxs){
            if(!exists[i][c]){
                flag = false;
                break;
            }
        }
        // printf("c = %d, flag = %d\n", c, flag);
        if(flag){
            label = c; break;
        }
    }
    if(!~label){
        printf("NO\n");
        exit(0);
    }used[label] = true;
    for(auto i : idxs){
        vector < int > pos;
        for(int p = 1; p <= L; ++p)
            if(S[i][p - 1] - 'a' == label)
                pos.push_back(p);
        // printf("i = %d, pos = ", i);
        // for(auto j : pos)printf("%d ", j);
        // printf("\n");
        mp[pos] += i;
    }
    for(auto [ignore, i] : mp)
        self(self, i, used);
};

bitset < 26 > bits;

int main(){
    L = read(), N = read();
    basic_string < int > idxs;
    for(int i = 1; i <= N; ++i){
        idxs += i;
        cin >> S[i];
        for(auto c : S[i])exists[i][c - 'a'] = true;
    }
    Cal(Cal, idxs, bits);
    printf("YES\n");
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