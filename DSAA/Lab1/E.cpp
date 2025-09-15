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

template < typename T = int >
inline T read(void);



int main(){
    vector < tuple < int, int, string > > team;
    int N = read();
    for(int i = 1; i <= N; ++i){
        string S; cin >> S;
        int s = read();
        basic_string < int > vals;
        for(int j = 1; j <= 6; ++j)vals += read();
        team.push_back({i, accumulate(vals.begin(), vals.end(), s * 10) - *max_element(vals.begin(), vals.end()) - *min_element(vals.begin(), vals.end()), S});
    }
    for(auto it = team.begin(); it != prev(team.end()); advance(it, 1))
        swap(*it, *min_element(it, team.end(), [](const tuple < int, int, string > &a, const tuple < int, int, string > &b)->bool{
            return get < 1 >(a) == get < 1 >(b) ? get < 0 >(a) < get < 0 >(b) : get < 1 >(a) > get < 1 >(b);
        }));
    int M = min(N, 3);
    int cutoff = get < 1 >(team.at(M - 1));
    while(M < N && get < 1 >(team.at(M)) == cutoff)++M;

    team.resize(M);
    for(auto [idx, s, S] : team)cout << S << " " << s << endl;

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
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