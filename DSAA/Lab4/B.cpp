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
    int N = read();
    multiset < int > S;
    vector < string > res;
    while(N--){
        string opt; cin >> opt;
        if(opt == "insert"){
            int val = read();
            S.insert(val);
            res.push_back("insert " + to_string(val));
        }
        if(opt == "removeMin"){
            if(S.empty())res.push_back("insert 1");
            else S.erase(S.begin());
            res.push_back("removeMin");
        }
        if(opt == "getMin"){
            int val = read();
            while(!S.empty() && *S.begin() < val)res.push_back("removeMin"), S.erase(S.begin());
            if(S.empty() || *S.begin() > val)res.push_back("insert " + to_string(val)), S.insert(val);
            res.push_back("getMin " + to_string(val));
        }
    }
    printf("%d\n", (int)res.size());
    for(auto &s : res)cout << s << endl;

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