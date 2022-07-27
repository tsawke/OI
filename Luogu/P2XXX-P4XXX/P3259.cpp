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

int N, M, k, limit, cost;
map<string, int>posN;
map<string, int>edgeN;
class Pos{
    public:
        int lightRED, lightGreen;
        int mode; // 0-gas 1-start 2-end
}pos[110000];
int sN, eN;
int cnt(0);
vector< pair<int, int>/*toVertex, len*/ >vertex[110000];
int main(){
    N = read(), M = read(), k = read(), limit = read(), cost = read();
    for(int i = 1; i <= N; ++i){
        string Name;
        cin>>Name;
        int lR = read(), lG = read();
        posN.insert(make_pair(Name, ++cnt));
        if(Name.find("start") != string::npos)sN = cnt, pos[cnt].mode = 1;
        else if(Name.find("end") != string::npos)eN = cnt, pos[cnt].mode = 2;
        else if(Name.find("gas") != string::npos)pos[cnt].mode = 0;
        else pos[cnt].mode = -1;
        pos[cnt].lightRED = lR, pos[cnt].lightGreen = lG;
    }
    for(int i = 1; i <= M; ++i){
        string st, en, name;
        cin>>st>>en>>name;
        int len = read();
        int s = posN.find(st)->second;
        int e = posN.find(en)->second;
        vertex[s].push_back(make_pair(e, len));
        vertex[e].push_back(make_pair(s, len));
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