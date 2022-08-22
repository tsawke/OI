#include <bits/stdc++.h>
using namespace std;

#define CLEAR(str) memset(str, 0, sizeof(str))

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


template<typename T = int>
inline T read(void);

//Root -> [1][1]
vector< int >vert[4100000];
// bitset< 110000000 > exist;
int times[4100000];
int _count[110];

short idx[4100000];
// int hash_(int fdep, int fwid, int tdep, int twid){
//     return fdep * 1000000 + fwid * 10000 + tdep * 100 + twid;
// }
int cnt(1);
unll ans(0ull);
int fais[4100000];
void Clear(int N_){
    for(int i = 0; i <= N_; ++i)vert[i].clear();
    // exist.reset();
    CLEAR(times);
    CLEAR(idx);
    CLEAR(_count);
    CLEAR(fais);
    cnt = 1;
    ans = 0ull;
}
unll Cal1(int dep){//上层不同链
    return ((unll)dep - 1ull) * 2ull + 1ull;
}
unll Cal2(int dep){//上层相同链
    return (unll)dep * 2ull + 1ull;
}
unll Cal3(int dep){//同层不同链
    return ((unll)dep - 1ull) * 2ull + 1ull;
}
unll Cal4(int dep){//同层同链
    return ((unll)dep + 1ull) * 2ull;
}
void BuildTrie(vector<int>&, int, int, int);
void Search(int, int, int, unll, int);
void ReadStr(void);
int N;
int main(){
    // freopen("sort.in", "r", stdin);
    // freopen("sort.out", "w", stdout); 
    int T = read();
    while(T--){
        Clear(cnt + 1);
        N = read();
        for(int i = 1; i <= N; ++i)
            ReadStr();
        printf("COUNT:");
        for(int i = 1; i <= 10; ++i)printf("%d ", _count[i]);
        printf("\n");
        printf("FAIS:");
        for(int i = 1; i <= 10; ++i)printf("%d ", fais[i]);
        printf("\n");
        printf("Times:");
        for(int i = 1; i <= 10; ++i)printf("%d ", times[i]);
        printf("\n");
        Search(0, 1, 0, 0ull, 0);
        printf("%llu\n", ans);
    }
    return 0;
}
void Search(int dep, int vertex, int pass, unll curAns, int fa){
    printf("In Search dep=%d, vert=%d, pas=%d, cans=%llu, fa=%d\n", dep, vertex, pass, curAns, fa);
    int tmp(_count[dep]), tmp2(fais[fa]);
    if(times[vertex]){
        ans += curAns;
        printf("ans->%llu\n", ans);
        ans += ((unll)fais[fa] - times[vertex]) *  Cal3(dep);
        ans += ((unll)_count[dep] - fais[fa]) * 1ull;
        printf("ans->%llu\n", ans);
        ans += (unll)pass * 1ull;
        ans += (unll)(times[vertex] * (times[vertex] - 1)) / 2ull * Cal4(dep);
        printf("ans->%llu\n", ans);
        curAns += Cal2(dep) * times[vertex];
        _count[dep] -= times[vertex];
        fais[fa] -= times[vertex];

    }
    pass += tmp - tmp2;
    curAns += Cal1(dep) * (unll)(tmp2 - times[vertex]);
    for(auto i : vert[vertex]){
        Search(dep + 1, i, pass, curAns, vertex);
    }
}
void BuildTrie(vector<int>&str, int dep, int vertex, int fa){//Root - dep = 0
    printf("Build, dep=%d, v=%d, fa=%d\n", dep, vertex, fa);
    if(dep == (int)str.size()){
        times[vertex]++;
        _count[dep]++;
        fais[fa]++;
        return;
    }
    int ch = str.at(dep);
    int nxtV(-1);
    for(auto i : vert[vertex]){
        if(idx[i] == ch){
            nxtV = i;
            break;
        }
    }
    if(nxtV == -1){
        nxtV = ++cnt;
        vert[vertex].push_back(cnt);
        idx[cnt] = ch;
    }
    BuildTrie(str, dep + 1, nxtV, vertex);
    // int fax(1), fay(1);
    // for(int dep = 1; dep <= str.size(); ++dep){
    //     int ch = str.at(dep - 1);
    //     if(exist[hash_(fax, fay, dep, ch)]){
    //         fax = dep;
    //         fay = ch;
    //         continue;
    //     }
    //     vert[fax][fay].push_back(make_pair(dep, ch));
    //     fax = dep, fay = ch;
    // }
    // times[str.size()][str.back()]++;

}

void ReadStr(void){
    vector<int>str;
    char c = getchar();
    while(!isdigit(c) && !isalpha(c))c = getchar();
    while(isdigit(c) || isalpha(c)){
        str.push_back(c - 40);
        c = getchar();
    }
    BuildTrie(str, 0, 1, 0);
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