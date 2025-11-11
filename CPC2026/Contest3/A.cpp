#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){ return rnd() % (r - l + 1) + l; }

using ll = long long;
using unll = unsigned long long;
using uint = unsigned int;
using ld = long double;

template < typename T = int >
inline T read(void);

const ld EPS = 1e-12L;

class Vec{
private:
public:
    ld x, y, z;
    Vec operator + (const Vec &b) const {return Vec{ x + b.x, y + b.y, z + b.z };}
    Vec operator - (const Vec &b) const {return Vec{ x - b.x, y - b.y, z - b.z };}
    Vec operator * (ld k) const {return Vec{ x * k, y * k, z * k };}

    friend ld operator * (const Vec &a, const Vec &b){
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }
    friend Vec operator ^ (const Vec &a, const Vec &b){
        return Vec{a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
    }

    Vec Unit(void){
        ld len = sqrtl(*this * *this);
        if(len < EPS)return *this;
        return *this * (1.0L / len);
    }
};

struct Plane{Vec n; ld h;};
struct Flight{Vec a, b; Vec n;};

auto OnArc = [](const Vec &a, const Vec &b, const Vec &n, const Vec &v){
    ld s1 = (a ^ v) * n;
    ld s2 = (v ^ b) * n;
    return s1 >= -EPS && s2 >= -EPS;//
};

vector < Vec > FindPts(const Plane& p1, const Plane& p2){
    vector < Vec > res;
    Vec d = p1.n ^ p2.n;
    ld dn2 = d * d;
    if(dn2 < 1e-24L) return res;

    // Find u0 on the line intersection of planes: u0 = alpha * n1 + beta * n2
    ld A11 = p1.n * p1.n, A22 = p2.n * p2.n, A12 = p1.n * p2.n;
    ld det = A11 * A22 - A12 * A12;
    if (fabsl(det) < 1e-24L) return res;

    ld alpha = ( p1.h * A22 - p2.h * A12 ) / det;
    ld beta  = ( A11 * p2.h - A12 * p1.h ) / det;
    Vec u0 = p1.n * alpha + p2.n * beta;

    // Intersect the line u = u0 + t * d̂ with unit sphere |u| = 1
    ld u02 = u0 * u0;
    if(u02 > 1.0L + 1e-18L) return res; // no intersection with sphere
    Vec dhat = d * (1.0L / sqrtl(dn2));
    ld t2 = 1.0L - u02;
    if(t2 < 0) t2 = 0;
    ld t = sqrtl(t2);

    Vec pA = (u0 + dhat * t).Unit();
    res.push_back(pA);
    if(t > 1e-18L){
        Vec pB = (u0 - dhat * t).Unit();
        res.push_back(pB);
    }
    return res;
}

auto Count = [](const Vec &u, const vector < Flight > &F, ld cosA, ld sinA){
    int cnt = 0;
    for(const auto &f : F){
        if((u * f.a) > cosA + EPS || (u * f.b) > cosA + EPS ){++cnt; continue;}
        ld un = u * f.n;
        Vec v = u - f.n * un;
        if(v * v < EPS * EPS)continue;
        if(OnArc(fl.a, fl.b, fl.n, v)){
            if(fabsl(un) < sinA - EPS) ++cnt; // distance to great circle < alpha
        }
    }
    return cnt;
}

int main(){
    int T = read();
    while(T--){
        int N = read(), K = read();
        ld R = (ld)read();
        cout << "R = " << R << endl;

        vector < Vec > pts((N << 1) + 10);
        for(int i = 1; i <= (N << 1); ++i){
            int x = read(), y = read(), z = read();
            pts[i] = Vec{(ld)x, (ld)y, (ld)z}.Unit();
        }

        vector < Flight > F;
        for(int i = 1; i <= N; ++i){
            auto a = pts[(i << 1) - 1], b = pts[i << 1];
            auto n = a ^ b;
            F.push_back(Flight{a, b, n * (1.0L / sqrtl(n * n))});
        }

        
        auto Check = [&](ld d)->bool{
            ld alpha = d / R;
            alpha = alpha < 0 ? 0 : (alpha > (ld)PI ? (ld)PI : alpha); 
            ld cosA = cosl(alpha), sinA = sinl(alpha);

            vector < Plane > circ;
            for(auto f : F){
                circ.push_back({f.a, cosA});
                circ.push_back({f.b, cosA});
                circ.push_back({f.n, sinA});
                circ.push_back({f.n, -sinA});
            }

            vector < Vec > pts;
            for(auto it1 = circ.begin(); it1 != prev(circ.end()); advance(it1, 1))
                for(auto it2 = next(it1); it2 != circ.end(); advance(it2, 1)){
                    auto res = FindPts(*it1, *it2);
                    for(auto &i : res)pts.emplace_back(i);
                }

            for(auto f : F){
                pts.push_back(f.a);
                pts.push_back(f.b);
                pts.push_back((f.a + f.b).Unit());
                pts.push_back(f.n);
                pts.push_back(f.n * (-1.0L));
            }
            for(auto &p : pts){
                int cnt = Count(p, F, cosA, sinA);
                if(cnt <= K)return true;
            }
            return false;
        };

        ld l = 0.0L, r = (ld)PI * R, ans;
        while(r - l > (ld)1e-7){
            printf("l = %.10Lf, r = %.10Lf\n", l, r);
            ld mid = (l + r) * 0.5L;
            if(Check(mid))l = mid + EPS, ans = mid;
            else r = mid - EPS;
        }

        printf("%.10f\n", (double)ans);
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c)) c = getchar();
    if(c == '-') flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}
