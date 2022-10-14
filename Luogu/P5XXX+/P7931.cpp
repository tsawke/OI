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
pair < int, int > LIS[1100000];
int N;
vector < int > current;
vector < int > tier[1100000];
int arr[1100000];
vector < vector < int > > anss;
int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        arr[i] = read();
        if(LISv.empty() || LISv.back() < arr[i])LISv.push_back(arr[i]), tier[(int)LISv.size()].push_back(i);
        else{
            auto pos = lower_bound(LISv.begin(), LISv.end(), arr[i]);
            int len = distance(LISv.begin(), pos) + 1;
            *pos = arr[i];
            tier[len].push_back(i);
        }
    }
    int maxLen = (int)LISv.size();
    for(int i = 1; i <= maxLen; ++i)
        reverse(tier[i].begin(), tier[i].end());
    while(true){
        if(current.empty()){
            if(tier[1].empty())break;
            current.push_back(tier[1].back());
            tier[1].pop_back();
        }else if((int)current.size() == maxLen){
            anss.push_back(current);
            current.clear();
        }else{
            int pos = current.size() + 1;
            int last = current.back();
            while(!tier[pos].empty() && tier[pos].back() < last)tier[pos].pop_back();
            if(tier[pos].empty() || arr[tier[pos].back()] < arr[last])current.pop_back();
            else current.push_back(tier[pos].back()), tier[pos].pop_back();
        }
    }
    printf("%d %d\n", (int)anss.size(), maxLen);
    for(auto i : anss){
        for(auto j : i)printf("%d ", j);
        printf("\n");
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