#include <bits/stdc++.h>
using namespace std;

template<typename T = int>
inline T read(void);

typedef long long ll;
int dfs(int, int, ll);
vector<int> ReadVec(void);
int bucket[10];
bool used[20];
int len;
int main(){
    int T = read();
    while(T--){
        vector<int>values(ReadVec());
        len = values.size();
        int d = read();	
		// for(auto i : values)printf("%d ", i);
        memset(used, false, sizeof(used));
        memset(bucket, 0, sizeof(bucket));
        for(auto i : values)++bucket[i];
        // printf("%d\n", d);//fflush(stdout);
        printf("%d\n", dfs(d, 1, 0));
    }


    return 0;
}
int dfs(int d, int deep, ll cur){
    if(deep > len){
        if(cur % d == 0)return 1;
        return 0;
    }
    int ret(0);
    for(int i = 0; i <= 9; ++i){
        if(bucket[i]){
            --bucket[i];
            ret += dfs(d, deep + 1, cur * 10 + i);
            ++bucket[i];
        }
    }
    // for(auto i : values){
    //     if(used[i])continue;
    //     used[i] = true;
    //     ret += dfs(values, d, deep + 1, );
    //     used[i] = false;
    // }
    return ret;
}
vector<int> ReadVec(void){
    vector<int>ret;
    char c = getchar();
    while(!isdigit(c))c = getchar();
    while(isdigit(c)){
        ret.push_back(int(c - '0'));
        c = getchar();
    }
    return ret;
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
    return (T)(ret * flag);
}