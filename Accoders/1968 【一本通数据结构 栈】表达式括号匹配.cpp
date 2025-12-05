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
        if(c[i] == '(')s.push(c[i]);
        else if(c[i] == ')'){
            if(!s.empty())s.pop();
            else{
                printf("NO\n");
                return 0;
            }
        }
    }
    if(s.empty())printf("YES\n");
    else printf("NO\n");

    char c = getchar();
    return 0;
}