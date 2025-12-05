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
    auto CalMax = [](const bool &a, const bool &b)->bool{return max(a, b);};
    auto CalMin = [](const bool &a, const bool &b)->bool{return min(a, b);};
    auto CalLE = [](const bool &a, const bool &b)->bool{return a <= b;};
    auto CalL = [](const bool &a, const bool &b)->bool{return a < b;};
    unordered_map < string, function < bool(const bool&, const bool&) > > table;
    table["|"] = CalMax, table["&"] = CalMin;
    table["#"] = CalLE, table["<"] = CalL;
    vector < bool > val(10, 0);
    queue < string > res;
    char c[21000]; cin.getline(c, 20000); int len = strlen(c);
    string S; for(int i = 0; i < len; ++i)S.push_back(c[i]);

    int pos(0);
    while((pos = S.find("max")) != string::npos)S.replace(pos, 3, "|");
    pos = 0;
    while((pos = S.find("min")) != string::npos)S.replace(pos, 3, "&");
    pos = 0;
    while((pos = S.find("<=")) != string::npos)S.replace(pos, 2, "#");

    unordered_set < int > allAlpha;
    for(auto c : S)if(isalpha(c))allAlpha.insert(c - 'a');
    int examp = *allAlpha.begin();

    auto GenerateDis = [&](auto&& self, unordered_set < int > &idxs)->string{
        if(idxs.empty())return "(" + string(1, char('a' + examp)) + " <= " + string(1, char('a' + examp)) + ")";
        if(idxs.size() == 1)return "(min " + string(1, char('a' + *idxs.begin())) + " " + string(1, char('a' + *idxs.begin())) + ")";
        if(idxs.size() == 2)return "(min " + string(1, char('a' + *idxs.begin())) + " " + string(1, char('a' + *next(idxs.begin()))) + ")";
        int idx = *idxs.begin(); idxs.erase(idxs.begin());
        return "(min " + string(1, char('a' + idx)) + " " + self(self, idxs) + ")";
    };
    auto GenerateCon = [&](auto&& self, unordered_set < int > &idxs)->string{
        if(idxs.empty())return "(" + string(1, char('a' + examp)) + " <= " + string(1, char('a' + examp)) + ")";
        if(idxs.size() == 1)return "(min " + string(1, char('a' + *idxs.begin())) + " " + string(1, char('a' + *idxs.begin())) + ")";
        if(idxs.size() == 2)return "((" + string(1, char('a' + *idxs.begin())) + " <= " + string(1, char('a' + *next(idxs.begin()))) + ") <= " + char('a' + *next(idxs.begin())) + ")";
        int idx = *idxs.begin(); idxs.erase(idxs.begin());
        return "((" + self(self, idxs) + " <= " + string(1, char('a' + idx)) + ") <= " + string(1, char('a' + idx)) + ")";
    };
    // cout << "> Modified S is " << S << endl;

    auto dfs01 = [&](auto&& self, int dep = 0)->void{
        // printf("# In dfs dep = %d\n", dep); fflush(stdout);
        if(dep >= 10){
            // printf("# Reach dfs:\n"); fflush(stdout);
            auto Cal = [&](auto&& self, int& curp)->bool{
                // printf("## Caling curp = %d\n", curp); fflush(stdout);
                string model = "?";
                bool val1, val2;
                while(curp < S.length()){
                    // printf("### (Before)In while#1 curp = %d\n", curp); fflush(stdout);
                    if(S[curp] == '('){val1 = self(self, ++curp); break;}
                    // printf("#### Pass 1, curp = %d\n", curp); fflush(stdout);
                    if(isalpha(S[curp])){val1 = val.at(S[curp] - 'a'), ++curp; break;};
                    // printf("#### Pass 2, curp = %d\n", curp); fflush(stdout);
                    if(S[curp] == '|' || S[curp] == '&'){model = "" + string(1, S.at(curp++));}
                    else ++curp;
                    // printf("### In while#1 curp = %d\n", curp);fflush(stdout);
                }
                // printf("> Reach ckpt 1, model = %s\n", model.c_str());fflush(stdout);
                if(model == "?"){
                    while(curp < S.length()){
                        if(S[curp] == '#' || S[curp] == '<'){model = "" + string(1, S.at(curp++)); break;}
                        ++curp;
                    }
                }
                // printf("> Reach ckpt 2, model = %s\n", model.c_str());fflush(stdout);
                while(curp < S.length()){
                    if(S[curp] == '('){val2 = self(self, ++curp); break;}
                    if(isalpha(S[curp])){val2 = val[S[curp] - 'a'], ++curp; break;};
                    ++curp;
                }
                // printf("> Reach ckpt 3, model = %s\n", model.c_str());fflush(stdout);
                return table[model](val1, val2);
            };
            int curp(0); bool ret(false);
            if(S[curp] != '('){
                cout << "YES\n" << S[curp] << endl;
                exit(0);
            }else ret = Cal(Cal, ++curp);
            
            bool all1 = true;
            for(int i = 0; i <= 9; ++i){
                if(allAlpha.find(i) == allAlpha.end())continue;
                if(!val[i])all1 = false;
            }
            if(all1 && !ret){
                printf("NO\n"); exit(0);
            }

            // bool all0 = true;
            // for(int i = 0; i <= 9; ++i){
            //     if(allAlpha.find(i) == allAlpha.end())continue;
            //     if(val[i])all0 = false;
            // }
            // if(all0 && !ret){
            //     printf("NO\n"); exit(0);
            // }

            if(ret == false){
                unordered_set < int > is0, is1;
                for(int i = 0; i <= 9; ++i){
                    if(allAlpha.find(i) == allAlpha.end())continue;
                    (val[i] ? is1 : is0).insert(i);
                }
                res.push("(" + GenerateDis(GenerateDis, is1) + " <= " + GenerateCon(GenerateCon, is0) + ")");
            }
            return;
        }
        if(allAlpha.find(dep) == allAlpha.end()){self(self, dep + 1); return;}
        val[dep] = 1;
        self(self, dep + 1);
        val[dep] = 0;
        self(self, dep + 1);
    }; dfs01(dfs01);

    auto GenerateDisWhenEmpty = [&](auto&& self, unordered_set < int > &idxs)->string{
        // if(idxs.empty())return "(" + string(1, char('a' + examp)) + " <= " + string(1, char('a' + examp)) + ")";
        if(idxs.size() == 1)return "(" + string(1, char('a' + *idxs.begin())) + " <= " + string(1, char('a' + *idxs.begin())) + ")";
        if(idxs.size() == 2)return "(min (" + string(1, char('a' + *idxs.begin())) + " <= " + string(1, char('a' + *idxs.begin())) + ") (" + string(1, char('a' + *next(idxs.begin()))) + " <= " + string(1, char('a' + *next(idxs.begin()))) + "))";
        int idx = *idxs.begin(); idxs.erase(idxs.begin());
        auto ret = self(self, idxs);
        return "(min (" + string(1, char('a' + idx)) + " <= " + string(1, char('a' + idx)) + ") (" + ret + " <= " + ret + "))";
    };

    if(res.size() == 0){
        // for(auto i : allAlpha)
    cout << "YES" << endl;// << "(" + string(1, char('a' + examp)) + " <= " << string(1, char('a' + examp)) << ")" << endl;
        cout << GenerateDisWhenEmpty(GenerateDisWhenEmpty, allAlpha) << endl;
    return 0;
    }

    auto GenerateDisByStr = [](auto&& self, queue < string > &strs)->string{
        // printf("> Current Str is %s\n", strs.front().c_str());
        if(strs.size() == 1)return strs.front();
        auto str = strs.front(); strs.pop();
        if(strs.size() == 1)return "(min " + strs.front() + " " + str + ")";
        return "(min " + str + " " + self(self, strs) + ")";
    };

    cout << "YES" << endl << GenerateDisByStr(GenerateDisByStr, res) << endl;

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