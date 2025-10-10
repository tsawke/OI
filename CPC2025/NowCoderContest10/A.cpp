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

template<typename T = int>
inline T read(void);

char *s = new char[110];
ll TAB(0);

vector < string > code;

int main(){
    cin.getline(s, 100);
    for(int i = 0; i < strlen(s); ++i)
        if(isdigit(s[i]))TAB = TAB * 10 + int(s[i] - '0');
        else break;
    
    auto IsW = [](char c)->bool{return c == 32 || c == 9 || c == 10;};
    //S, L, E is (W + void)

    auto IsD = [](char c)->bool{return isdigit(c);};

    auto IsSingleSign = [](char c)->bool{
        return  c == '&' ||
                c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' ||
                c == '!' || c == ',' || c == '*' || c == '?';
    };

    bool Commented(false);

    int c = getchar();
    while(c != EOF){
        // printf("-----Main Loop c = %c\n", c); fflush(stdout);
        if(IsSingleSign(c)){code.push_back(string{(char)c}); c = getchar(); continue;}
        if(c == '='){
            c = getchar();
            if(c == '=')code.push_back("=="), c = getchar();
            else code.push_back("=");
            continue;
        }
        if(c == '+'){
            c = getchar();
            if(c == '+')code.push_back("++"), c = getchar();
            else code.push_back("+");
            continue;
        }
        if(c == '*'){
            code.push_back("*"); c = getchar(); continue;
        }
        // if(Commented && c == '/'){
        //     code.push_back("/");
        //     c = getchar();
        //     continue;
        // }
        if(c == '/'){
            char c2 = getchar();
            if(c2 == '*' && code.empty()){
                Commented = true;
                code.push_back("/*");
                string str;
                int ct = getchar();
                // printf("************Ready to enter while c = %c\n", c); fflush(stdout);
                while(true){
                    // printf("In while ct = %c\n", ct); fflush(stdout);
                    if(ct == '*'){
                        ct = getchar();
                        if(ct == '/'){
                            Commented = false;
                            c = getchar();
                            // printf("Find Break\n"); fflush(stdout);
                            break;
                        }else{
                            str += '*';
                            continue;
                        }
                    }
                    str += (char)ct;
                    // cout << "curr str = " << str << endl; fflush(stdout);
                    ct = getchar();
                }
                code.push_back(str);
                code.push_back("*/");
                continue;
                // c = ct;
            }else{
                code.push_back("/");
                c = c2;
                // c = c == EOF ? EOF : getchar();
                continue;
            }
        }
        if(isdigit(c)){
            string num; 
            while(isdigit(c))num += c, c = getchar();
            code.push_back(num);
            continue;
        }
        if(isalpha(c) || c == '_'){
            string word; 
            while(isalpha(c) || c == '_' || isdigit(c))word += c, c = getchar();
            code.push_back(word);
            continue;
        }
        c = getchar();
    }

    auto IsSTMT = [](string S)->bool{
        return S == "if" || S == "otherwise" || S == "repeat" || S == "while" || S == "return";
    };

    auto PrintTab = [](int cur)->string{
        string ret;
        for(int i = 1; i <= TAB * cur; ++i)ret += ' ';
        return ret;
    };

    int curBlock(0);
    bool NeedsTab(false);
    bool isBegin(false);

    vector < bool > fromRep;

    for(int i = 0; i < code.size(); ++i){
        string cur = code[i];

        if(NeedsTab){
            if(cur == "}")--curBlock;
            cout << PrintTab(curBlock);
            NeedsTab = false;
            isBegin = true;
        }

        if((isalpha(code[i][0]) || code[i][0] == '_') && (i != 0 && (isalpha(code[i - 1][0]) || code[i - 1][0] == '_') && !IsSTMT(code[i - 1])))cout << " ";
        
        // if( && i != 0 && ))cout << " ";

        if(
            cur == "+" || cur == "&" || cur == "/" || cur == "==" ||
            cur == "="
        )cout << " " << cur << " ";
        else if(cur == ",")cout << ", ";
        else if(cur == "if")cout << "if ";
        else if(cur == "otherwise")cout << "otherwise ";
        else if(cur == "repeat")cout << "repeat ";
        else if(cur == "while")cout << "while ";
        else if(cur == "return")cout << "return ";
        else if(cur == "{"){
            fromRep.push_back((i > 0 && code[i - 1] == "repeat") ? true : false);
            if(i != 0 && (code[i - 1] == "otherwise" || code[i - 1] == "repeat"))cout << "{\n";
            else cout << " " << "{\n";
            ++curBlock;
            NeedsTab = true;
        }
        else if(cur == "(")cout << "(";
        else if(cur == "}"){
            // if(i + 1 < (int)code.size() && (code[i + 1] == "otherwise" || code[i + 1] == "while"))cout << "} ";
            // else cout << ((i == (int)(code.size() - 1)) ? "}" : "}\n"), NeedsTab = true;
            // // cout << ((i == (int)(code.size() - 1)) ? "}" : "}\n"), NeedsTab = true;
            bool joinOtherwise = (i + 1 < (int)code.size() && code[i + 1] == "otherwise");
            bool joinWhile(false);
            if(i + 1 < (int)code.size() && code[i + 1] == "while")
                if(!fromRep.empty() && fromRep.back()) joinWhile = true;
            cout << "}";
            if(joinOtherwise || joinWhile)cout << " ";
            else if(i != (int)code.size() - 1){cout << "\n"; NeedsTab = true;}
            if(!fromRep.empty()) fromRep.pop_back();
        }
        else if(cur == "?")cout << cur << "\n", NeedsTab = true;
        else if(cur == "!"){
            if(i != 0 && (
                // isdigit(code[i - 1][0]) || isalpha(code[i - 1][0]) ||
                // code[i - 1] == ")" || code[i - 1] == "]"
                // || code[i - 1] == "++"// || code[i - 1] == "!"
                code[i - 1] == "?" || code[i - 1] == "}"
            ))cout << cur << "\n", NeedsTab = true, code[i] = "?";
            else cout << cur;
        }
        else if(cur == "*/")cout << "*/\n";
        else if(cur == "main" &&
            (
                (i + 1 < code.size() && code[i + 1] == "(") &&
                (i + 2 < code.size() && code[i + 2] == ")")
            )
        )cout << "main()", i += 2;
        else if(isalpha(cur[0]) && 
            (
                (i + 1 < code.size() && code[i + 1] == "(") &&
                (i + 2 < code.size() && code[i + 2] == ")")
        ))cout << cur << "()", i += 2;
        else cout << cur;
        fflush(stdout);
    }
    
    

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