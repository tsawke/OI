#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
char c[1100];
int main(){
    gets(c + 1);
    int len = strlen(c + 1);
    stack<char>s;
    for(int i = 1; i <= len; ++i){
        if(c[i] == '(' || c[i] == '[')s.push(c[i]);
        else if(c[i] == ')' || c[i] == ']'){
            if(s.empty()){
                printf("Wrong\n");
                return 0;
            }
            if((c[i] == ')' && s.top() == '(') || (c[i] == ']' && s.top() == '['))s.pop();
            else{
                printf("Wrong\n");
                return 0;
            }
        }
    }
    if(s.empty())printf("OK\n");
    else printf("Wrong\n");

    char c = getchar();
    return 0;
}