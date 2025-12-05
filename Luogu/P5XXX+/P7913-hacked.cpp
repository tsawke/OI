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

typedef pair<int, int> Plane;

int N, m1, m2;
int ans(-1);
vector< int >m1Port(110000, 0);
vector< int >m2Port(110000, 0);
int m1S[110000], m2S[110000];
vector< int > CalAirPort(vector<Plane>);
int main(){
	N = read(), m1 = read(), m2 = read();
    vector<Plane>plane;
    for(int i = 1; i <= m1; ++i){
        int iT = read(), oT = read();
        plane.push_back(make_pair(iT, oT));
    }
    m1Port = CalAirPort(plane);
    plane.clear();
    for(int i = 1; i <= m2; ++i){
        int iT = read(), oT = read();
        plane.push_back(make_pair(iT, oT));
    }
    m2Port = CalAirPort(plane);
    for(int i = 1; i <= N; ++i){
        m1S[i] = m1S[i - 1] + m1Port.at(i);
        m2S[i] = m2S[i - 1] + m2Port.at(i);
    }
    for(int i = 0; i <= N; ++i){
        ans = max(ans, m1S[i] + m2S[N - i]);
    }
    printf("%d\n", ans);
    return 0;
}
vector< int > CalAirPort(vector<Plane> _plane){
    vector< int >Port(110000, 0);
    priority_queue< Plane, vector<Plane>, greater<Plane> >plane;
    vector< Plane >Ports;//(N, outTime)
    for(auto i : _plane)plane.push(i);
    while(!plane.empty()){
        Plane temp(plane.top());
        plane.pop();
        if(Ports.empty()){
            Ports.push_back(make_pair(1, temp.second));
            ++Port.at(1);
            continue;
        }
        bool fail(true);
        for(auto &i : Ports){
            if(i.second < temp.first){
                i = make_pair(i.first, temp.second);
                ++Port.at(i.first);
                fail = false;
                break;
            }
        }
        if(fail){
            int num = ( *(Ports.end() - 1) ).first + 1;
            Ports.push_back( make_pair(num, temp.second) );
            ++Port.at(num);
        }
    }
    return Port;
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