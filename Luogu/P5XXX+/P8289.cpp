#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define S(i) (S.at(i - 1))

template < typename T = int >
inline T read(void);

unordered_map < string, string > mp;
unordered_map < string, bool > vis;

int main(){
    int N = read();
    while(N--){
        string S;
        getline(cin, S);
        int len = (int)S.length();
        if(strstr(S.c_str(), "#define")){
            int cp = 8;
            while(!isalpha(S(cp)) && !isdigit(S(cp)) && S(cp) != '_')++cp;
            string A;
            while(isalpha(S(cp)) || isdigit(S(cp)) || S(cp) == '_')A += S(cp), ++cp;
            ++cp;
            string B;
            while(cp <= len)B += S(cp), ++cp;
            mp[A] = B;
            printf("\n");
            continue;
        }else if(strstr(S.c_str(), "#undef")){
            int cp = 7;
            while(!isalpha(S(cp)) && !isdigit(S(cp)) && S(cp) != '_')++cp;
            string A;
            while(cp <= len && (isalpha(S(cp)) || isdigit(S(cp)) || S(cp) == '_'))A += S(cp), ++cp;
            mp.erase(A);
            printf("\n");
            continue;
        }
        auto MakeStr = [](auto&& self, string S, int dep = 1)->string{
            string ret;
            int len = S.length();
            int cp(1);
            while(cp <= len){
                string A;
                while(cp <= len && !isalpha(S(cp)) && !isdigit(S(cp)) && S(cp) != '_')ret += S(cp), ++cp;
                while(cp <= len && (isalpha(S(cp)) || isdigit(S(cp)) || S(cp) == '_'))A += S(cp), ++cp;
                string tmp = A;
                if(mp.find(A) != mp.end() && !vis[A])vis[A] = true, A = self(self, mp[A], dep + 1), vis[tmp] = false;
                ret += A;
            }return ret;
        };
        for(auto& v : vis)v.second = false;
        string ans = MakeStr(MakeStr, S);
        cout << ans << endl;
    }
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
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