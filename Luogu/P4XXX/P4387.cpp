//C++11 - Template
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <unistd.h>

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);

int Q;

int main(){
	Q = read();
    for(int q = 1; q <= Q; ++q){
        int N = read();
        queue<int>in;
        queue<int>out;
        for(int i = 1; i <= N; ++i)in.push(read());
        for(int i = 1; i <= N; ++i)out.push(read());
        stack<int>s;
        s.push(in.front());
        // if(in.empty()){printf("ERROR!!!\n\n\n");return 0;}
        in.pop();
        int breakflag(false);
        while(!out.empty()){
            int breakflag2(false);
            if(s.empty()){
                if(in.empty()){
                    breakflag = true;
                    break;
                }
                else{
                    s.push(in.front());
                    in.pop();
                }
            }
            // if(.empty()){printf("ERROR!!!\n\n\n");return 0;}
            while(s.top() != out.front()){
                if(in.empty()){
                    breakflag = breakflag2 = true;
                    break;
                }
                s.push(in.front());
                in.pop();
            }
            if(breakflag2)break;
            s.pop();
            out.pop();
        }
        if(breakflag)printf("No\n");
        else printf("Yes\n");
    }


    return 0;
}

template <typename T = int>
inline T read(void)
{
	T ret(0);
	short flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
    }
    ret *= flag;
	return ret;
}