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

#define EPS (1e-9)

const double GRID = 2000;

int N;

// auto HashPoint = [](tuple < int, int> pos)->unsigned{
//     auto [a, b] = pos;
//     int p1 = 73856093 * a;
//     int p2 = 19349663 * b;
//     return p1 ^ p2;
// };
auto HashPoint = [](ll gx, ll gy)->std::uint64_t {
    std::uint64_t p1 = 73856093ULL * (std::uint64_t)(gx & 0x7fffffffULL);
    std::uint64_t p2 = 19349663ULL * (std::uint64_t)(gy & 0x7fffffffULL);
    return p1 ^ (p2 << 1);
};

struct Circ{
    double x, y, r;
    ll gx, gy;
};

int main(){
    int T = read();
    while(T--){
        vector < Circ > circ;
        unordered_map < ll, vector < int > > buck;

        buck.reserve(N * 5);

        N = read();
        for(int i = 1; i <= N; ++i){
            int x = read(), y = read(), r = read();
            circ.push_back(Circ{(double)x, (double)y, (double)r, (long long)floor(x / GRID), (long long)floor(y / GRID)});
        }

        for(int idx = 0; idx < N; ++idx){
            auto c = circ.at(idx);
            ll xl = floor((c.x - c.r) / GRID), xr = floor((c.x + c.r) / GRID);
            ll yl = floor((c.y - c.r) / GRID), yr = floor((c.y + c.r) / GRID);
            for(int i = xl; i <= xr; ++i)
                for(int j = yl; j <= yr; ++j)
                    buck[HashPoint(i, j)].push_back(idx);
        }

        vector < int > idxs;
        for(int i = 0; i < N; ++i)idxs.emplace_back(i);
        sort(idxs.begin(), idxs.end(), [&](const int &a, const int &b)->bool{
            return circ[a].r > circ[b].r;
        });

        vector < bool > covered;
        // covered.reset();
        covered.assign(N, 0);
        for(auto idx : idxs){
            if(covered[idx])continue;
            auto gx = circ[idx].gx, gy = circ[idx].gy;
            // ll gx = floor(circ[idx].x / GRID), gy = floor(circ[idx].y / GRID);
            bool flag(false);
            for(int dx = -1; dx <= 1 && !flag; ++dx)
                for(int dy = -1; dy <= 1 && !flag; ++dy){
                    auto it = buck.find(HashPoint(gx + dx, gy + dy));
                    if(it != buck.end()){
                        for(auto i : it->second){
                            if(i == idx || covered[i] || circ[i].r < circ[idx].r)continue;
                            double d = hypot(circ[i].x - circ[idx].x, circ[i].y - circ[idx].y);
                            if(d + circ[idx].r <= circ[i].r + EPS){flag = true; break;}
                        }
                    }
                }
            if(flag)covered[idx] = true;
        }

        double area(0.0);
        for(int i = 0; i < N; ++i){
            vector < double > cuts;
            if(covered[i])continue;
            auto gx = circ[i].gx, gy = circ[i].gy;
            // ll gx = floor(circ[i].x / GRID), gy = floor(circ[i].y / GRID);
            for(int dx = -1; dx <= 1; ++dx)
                for(int dy = -1; dy <= 1; ++dy){
                    auto it = buck.find(HashPoint(gx + dx, gy + dy));
                    if(it != buck.end()){
                        for(auto j : it->second){
                            double d = hypot(circ[j].x - circ[i].x, circ[j].y - circ[i].y);
                            if(d < EPS || d >= circ[i].r + circ[j].r - EPS || d <= fabs(circ[i].r - circ[j].r) + EPS)continue;
                            double theta = atan2(circ[j].y - circ[i].y, circ[j].x - circ[i].x);
                            double arg = (circ[i].r * circ[i].r - circ[j].r * circ[j].r + d * d) / (2.0 * circ[i].r * d);
                            arg = max(min(arg, (double)1), (double)-1);
                            double delta = acos(arg);
                            cuts.push_back(theta - delta), cuts.push_back(theta + delta);
                        }
                    }
                }
            
            if(cuts.empty()){
                area += PI * circ[i].r * circ[i].r;
                continue;
            }
            
            for(auto &c : cuts)c = fmod(c + 2.0 * PI, 2.0 * PI);
            sort(cuts.begin(), cuts.end());
            cuts.push_back(*cuts.begin() + 2.0 * PI);

            for(auto it = cuts.begin(); next(it) < cuts.end(); advance(it, 1)){
                double arc1(*it), arc2(*next(it));
                double mid = (arc1 + arc2) * 0.5;
                double px = circ[i].x + circ[i].r * cos(mid);
                double py = circ[i].y + circ[i].r * sin(mid);

                ll gx = floor(px / GRID), gy = floor(py / GRID);

                // printf("p = %.2lf, %.2lf.  g = %d, %d\n", px, py, gx, gy);

                bool flag(false);
                for(int dx = -1; dx <= 1 && !flag; ++dx)
                    for(int dy = -1; dy <= 1 && !flag; ++dy){
                        auto it = buck.find(HashPoint(gx + dx, gy + dy));
                        if(it != buck.end()){
                            for(auto j : it->second){
                                if(j == i || covered[j])continue;
                                double d = hypot(px - circ[j].x, py - circ[j].y);
                                if(d < circ[j].r){flag = true; break;}
                            }
                        }
                    }
                if(flag)continue;
                double x1 = circ[i].x + circ[i].r * cos(arc1);
                double y1 = circ[i].y + circ[i].r * sin(arc1);
                double x2 = circ[i].x + circ[i].r * cos(arc2);
                double y2 = circ[i].y + circ[i].r * sin(arc2);

                area += 0.5 * (x1 * y2 - x2 * y1) + 0.5* circ[i].r * circ[i].r * (arc2 - arc1 - sin(arc2 - arc1));

            }
        }
        // printf("%.9lf\n", area);
        cout << fixed << setprecision(18) << area << endl;
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