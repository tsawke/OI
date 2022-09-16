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

void Init(void);
map < string, string > idx;
int main(){
    Init();
    int num = 2;
    for(int i = 2; i <= 5; ++i){
num = i;

    char* filei = new char[50];
    char* fileo = new char[50];
    sprintf(filei, "T3/hackllq%d.in", num);
    sprintf(fileo, "T3/hackllq%d.out", num);
    freopen(filei, "w", stdout);
    int N = rndd(90, 100);
    printf("%d\n", N);
    for(int i = 1; i <= N; ++i){
        int tmpd = rndd(0, 99);
        char* tmp = new char[10];
        sprintf(tmp, "%d", tmpd);
        string tmps(tmp);
        freopen(filei, "w", stdout);
        cout << tmps << endl;

        string md5s = idx[tmps];
        freopen(fileo, "w", stdout);
        cout << md5s << endl;
        delete[] tmp;
    }


    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}