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

string cmp1 = "section", cmp2 = "subsection", cmp3 = "subsubsection";
string title[110];
template<typename T = int>
inline T read(void);

int cur1(0), cur2(0), cur3(0);

int main(){
    int N = read();
    while(N--){
        string cmp, tit;
        cin >> cmp >> tit;
        if(!cmp1.compare(cmp))cur2 = 0, cur3 = 0, cout << ++cur1 << " " << tit << endl;
        else if(!cmp2.compare(cmp))cur3 = 0, cout << cur1 << "." << ++cur2 << " " << tit << endl;
        else cout << cur1 << "." << cur2 << "." << ++cur3 << " " << tit << endl;
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