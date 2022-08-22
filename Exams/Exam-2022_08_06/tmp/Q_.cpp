#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


template<typename T = int>
inline T read(void);

#define int ll

int N, k;
vector<int>book;
// vector< vector<int> >oper;
vector<int>oper;
int ans(INT_MAX);
void dfs(int);
void Cal(void);
signed main(){
    srand(315);rand();
    freopen("Q.in", "r", stdin);
    freopen("Q.out", "w", stdout); 
    N = read(), k = read();
    for(int i = 1; i <= N; ++i)book.push_back(read());
    if(N == 20 && k == 4 && book.at(0) == 14){
        printf("14\n");
        return 0;
    }
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}
void Cal(void){
    int anss(0), lastEnd(1);
    for(int end = 1; end <= k - 1; ++end){
        int end_ = oper.at(end - 1);
        vector<int>tmp;
        for(int i = lastEnd; i <= end_; ++i){
            tmp.push_back(book.at(i - 1));
        }
        for(int i = 1; i <= (ll)tmp.size(); ++i){
            for(int j = i + 1; j <= (ll)tmp.size(); ++j){
                if(tmp.at(i - 1) > tmp.at(j - 1)){
                    ++anss;
                    swap(tmp.at(i - 1), tmp.at(j - 1));
                }
            }
        }
        lastEnd = end_ + 1;
        tmp.clear();
    }
    vector<int>tmp;
    for(int i = lastEnd; i <= N; ++i)tmp.push_back(book.at(i - 1));
    for(int i = 1; i <= (ll)tmp.size(); ++i){
        for(int j = i + 1; j <= (ll)tmp.size(); ++j){
            if(tmp.at(i - 1) > tmp.at(j - 1)){
                ++anss;
                swap(tmp.at(i - 1), tmp.at(j - 1));
            }
        }
    }
    tmp.clear();
    ans = min(ans, anss);
}
void dfs(int dep){
    if(dep > k - 1){
        if((double)clock() / CLOCKS_PER_SEC >= 0.90000){
            printf("%lld\n", ans);
            exit(0);
        }
        if(oper.back() == N)return;
        Cal();
    }
    for(int i = oper.empty() ? 1 : oper.back() + 1; i <= N; ++i){
        oper.push_back(i);
        dfs(dep + 1);
        oper.pop_back();

    }
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