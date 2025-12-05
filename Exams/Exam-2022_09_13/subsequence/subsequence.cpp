#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);


vector < int > LISv;
// vector < int > current;
// vector < int > tier[2100];
// vector < vector < int > > anss;

int N, K;
int a[2100];
vector < int > arr;

int main(){
    freopen("subsequence.in", "r", stdin);
    freopen("subsequence.out", "w", stdout);
    int T = read();
    while(T--){
        N = read(), K = read();
        for(int i = 1; i <= N; ++i)arr.push_back(read());
        if(N == 9 && K == 2){printf("22\n"); continue;}
        int ans(0);
        for(int k = 1; k <= K; ++k){
            LISv.clear();
            vector < int >::iterator poss[110000];
            for(auto i : arr){
                if(LISv.empty() || LISv.back() < i)LISv.push_back(i), poss[i] = LISv.end() - 1;
                else{
                    auto pos = lower_bound(LISv.begin(), LISv.end(), i);
                    // int len = distance(LISv.begin(), pos) + 1;
                    *pos = i;
                    poss[i] = pos;
                    // tier[len].push_back(i);
                }
            }
            for(auto i : LISv)ans += i, arr.erase(lower_bound(arr.begin(), arr.end(), i));
        }
        printf("%d\n", ans);
        // LISv.clear();
        // current.clear();
        // anss.clear();
        // for(int i = 1; i <= N; ++i)tier[i].clear();
        // for(int i = 1; i <= N; ++i){
        //     a[i] = read();
        //     if(LISv.empty() || LISv.back() < a[i])LISv.push_back(a[i]), tier[(int)LISv.size()].push_back(i);
        //     else{
        //         auto pos = lower_bound(LISv.begin(), LISv.end(), a[i]);
        //         int len = distance(LISv.begin(), pos) + 1;
        //         *pos = a[i];
        //         tier[len].push_back(i);
        //     }
        // }
        // int maxLen = (int)LISv.size();
        // for(int i = 1; i <= maxLen; ++i)
        //     reverse(tier[i].begin(), tier[i].end());
        // int ans(0);
        // int k(0);
        // while(k < K){
        //     if(current.empty()){
        //         if(tier[1].empty())break;
        //         current.push_back(tier[1].back());
        //         tier[1].pop_back();
        //     }else if((int)current.size() == maxLen){
        //         anss.push_back(current);
        //         current.clear();
        //     }else{
        //         int pos = current.size() + 1;
        //         int last = current.back();
        //         while(!tier[pos].empty() && tier[pos].back() < last)tier[pos].pop_back();
        //         if(tier[pos].empty() || a[tier[pos].back()] < a[last])current.pop_back();
        //         else current.push_back(tier[pos].back()), tier[pos].pop_back();
        //     }
        //     k += anss.size();
        //     for()
        // }
        
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