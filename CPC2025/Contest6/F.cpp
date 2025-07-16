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

int N;
int cnt[1100][1100][31];
unordered_map < char, int > lst;
// class interval{
//     public:
//         unordered_map < int, int > cnt;
// }

vector < string > str; 

int main(){
    N = read();
    string S; cin >> S;
    for(int l = 1; l <= N; ++l){
        for(int r = l; r <= N; ++r){
            for(int i = 0; i <= 30; ++i)cnt[l][r][i] = cnt[l][r - 1][i];
            ++cnt[l][r][S.at(r - 1) - 'a'];
            // cnt[l][r] = cnt[l][r - 1];
            // if(cnt[l][r].find(S.at(r - 1)) != cnt[l][r].end())
            //     ++cnt[l][r][S.at(r - 1)];
            // else cnt[l][r].insert({S.at(r - 1), 1});
        }
        // cnt[l + 1][l] = cnt[l][l];
        for(int i = 0; i <= 30; ++i)cnt[l + 1][l][i] = cnt[l][l][i];
        --cnt[l + 1][l][S.at(l - 1) - 'a'];
        // if(!cnt[l + 1][l][S.at(l - 1)])cnt[l + 1][l].erase(S.at(l - 1));
    }
    for(int r = 1; r <= N; ++r){
        basic_string < char > s;
        lst[S.at(r - 1)] = r;
        for(int l = 1; l <= r; ++l){
            int siz(0);
            for(int i = 0; i <= 30; ++i)if(cnt[lst[S.at(l - 1)]][r][i])++siz;
            s += 'a' + siz - 1;
            // s += 'a' + cnt[lst[S.at(l - 1) - 'a']][r].size() - 1;
        }
        str.push_back(s.c_str());
    }
    sort(str.begin(), str.end());
    cout << *prev(str.end()) << endl;

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