#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int>
inline T read(void);

int N;
map < string, string > idx;
string str[11000];
int main(){
    N = read();
    for(int i = 1; i <= N; ++i)cin >> str[i];
    for(int i = 0; i <= 9999; ++i){
        char* tmp = new char[10];
        sprintf(tmp, "%d", i);
        string tmps(tmp);
        cout << tmps << endl;
        string md5s;
        cin >> md5s;
        idx.insert(make_pair(md5s, tmps));
        delete[] tmp;
    }
    printf("Completely Hacked!\n");fflush(stdout);
    for(int i = 1; i <= N; ++i)printf("%s\n", idx[str[i]].c_str()), fflush(stdout);
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