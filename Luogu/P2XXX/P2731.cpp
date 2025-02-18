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
#include <unistd.h>
#include <functional>

using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int edgeAmt; //Edge Amount
int vertAmt(0); //Vertex Amount 
pair< vector< pair<int, bool> /*toVertex, visited*/ > , int /*vertex, degree*/>vertex[1100];
bool cmp_vec(pair<int, bool>, pair<int, bool>);
void dfs(int, int);
vector<int>route;
int root;
int main(){
	edgeAmt = read();
    for(int i = 1; i <= 500; ++i)vertex[i].second = false;
    for(int i = 1; i <= edgeAmt; ++i){
        int from = read(), to = read();
        vertex[from].first.push_back(pair<int, bool>(to, false));
        vertex[to].first.push_back(pair<int, bool>(from, false));
        ++vertex[from].second;
        ++vertex[to].second;
        vertAmt = max(vertAmt, max(from, to));
    }
    for(int i = 1; i <= vertAmt; ++i)sort(vertex[i].first.begin(), vertex[i].first.end(), cmp_vec);
    
    root = 1;
    for(int i = 1; i <= vertAmt; ++i)
        if(vertex[i].second & 1){root = i; break;}
    route.push_back(root);
                // printf("Check Values: root = %d  vertAmt = %d\n", root, vertAmt);
                // for(int i = 1; i <= vertAmt; ++i){
                //     for(auto j : vertex[i].first){
                //         printf("%d ", j.first);
                //     }printf("\n");
                // }
    // printf("Complete Before DFS\n");
    dfs(root, 1);
    return 0;
}
void dfs(int vertex, int steps){
    // printf("DFS: vert:%d  setps:%d\n", vertex, steps);
                        if(steps >= 497){
                            printf("IN DFS vertex = %d    steps = %d\n", vertex, steps);
                            for(int c = 1; c <= ::vertAmt; ++c){
                                printf("No.%d  ", c);
                                for(auto j : ::vertex[c].first){
                                    printf("%d-%d  ", j.first, j.second);
                                }printf("\n");
                            }
                            sleep(5);
                        }
    if(steps >= edgeAmt + 1){
        for(auto i : route)printf("%d\n", i);
        exit(0);
    }
    for(auto &i : ::vertex[vertex].first){
        int to;
        bool vis;
        tie(to, vis) = i;
        if(!vis){
            route.push_back(to);
            i.second = true;
            auto itea = find(::vertex[to].first.begin(), ::vertex[to].first.end(), pair<int, bool>(vertex, false));
            if(itea == ::vertex[to].first.end())continue;//printf("\n\n\nFIND WRONG!\n\n\n");
            (*itea).second = true;
            dfs(to, steps + 1);
            (*itea).second = false;
            i.second = false;
            route.pop_back();
        }
    }
                            // printf("IN DFS vertex = %d    steps = %d\n", vertex, steps);
                            // for(int c = 1; c <= ::vertAmt; ++c){
                            //     for(auto j : ::vertex[c].first){
                            //         printf("%d-%d  ", j.first, j.second);
                            //     }printf("\n");
                            // }
}
bool cmp_vec(pair<int, bool>a, pair<int, bool>b){
    return a.first < b.first;;
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
/*TODO Debug Required
Q: https://www.luogu.com.cn/problem/P2731
https://www.luogu.com.cn/record/66671258

TEST#7 TLE

500
1 172
2 201
3 295
3 42
5 220
5 31
6 158
6 288
7 91
8 199
8 227
9 72
10 103
10 276
11 167
12 3
13 180
14 139
14 237
15 114
16 109
16 271
16 290
19 217
20 137
20 198
21 246
21 262
22 211
23 33
23 79
24 140
24 245
26 38
26 65
27 123
27 65
28 87
29 218
30 136
30 202
31 202
31 68
32 102
32 130
33 110
33 112
33 116
33 96
34 176
35 156
35 278
38 54
40 150
40 250
40 84
41 199
41 271
41 52
42 131
43 103
44 118
44 218
45 26
46 234
46 48
48 235
49 113
49 272
50 262
51 117
52 62
53 128
54 275
55 138
58 20
58 259
59 117
60 174
60 61
60 89
61 195
62 266
62 30
65 223
65 282
65 70
68 120
68 122
68 191
69 129
69 213
70 253
71 107
71 65
72 128
72 236
72 242
72 275
72 92
73 118
73 174
74 207
75 176
75 33
77 172
77 250
78 114
78 174
79 185
80 140
81 9
82 266
83 22
84 122
84 203
84 97
86 23
87 117
88 160
89 250
89 278
89 35
90 33
91 108
91 158
91 232
92 160
92 175
92 50
92 98
94 136
95 189
95 84
96 41
96 73
96 8
97 187
97 231
97 27
98 193
98 92
99 158
99 181
99 227
99 249
99 92
100 145
100 16
100 167
100 51
100 55
101 230
102 11
102 163
102 175
102 220
102 99
103 10
103 124
103 224
103 40
104 24
105 108
105 95
107 102
107 252
107 283
108 100
108 181
108 198
108 60
109 287
110 83
112 44
113 16
113 41
114 160
114 237
114 46
114 72
114 99
115 208
115 89
116 12
116 161
117 142
117 187
117 239
117 257
118 194
118 284
118 60
119 159
119 95
120 134
121 75
122 166
122 167
123 270
123 90
124 272
125 21
125 279
127 128
127 99
128 194
128 256
128 28
128 99
129 227
129 271
129 295
129 40
130 142
131 276
131 32
131 97
133 102
134 170
136 164
136 217
136 6
136 72
137 183
138 235
139 114
139 275
140 23
140 275
142 115
142 159
142 274
142 298
143 232
143 271
144 35
145 259
147 149
149 224
149 227
150 266
155 116
156 273
156 71
157 14
158 103
158 186
158 2
158 264
158 284
159 185
159 276
160 142
160 218
160 219
160 222
161 178
161 268
163 149
163 216
163 220
164 189
164 19
165 157
165 58
166 143
166 155
166 160
166 254
166 43
167 223
167 239
167 279
167 296
168 102
168 104
168 3
169 228
170 185
170 219
172 119
172 275
172 32
173 125
174 129
174 165
174 270
175 100
175 114
175 208
175 250
175 34
176 296
176 96
177 268
178 131
179 215
180 14
180 283
181 125
181 268
182 232
183 49
185 167
185 190
185 277
186 15
186 199
186 230
186 287
186 33
187 147
187 298
187 5
189 175
189 215
190 58
191 92
193 100
193 166
193 91
194 233
194 249
194 69
194 8
195 89
198 136
198 168
198 202
199 286
199 49
199 91
200 103
200 115
200 29
201 168
201 254
202 105
202 121
202 205
202 59
202 68
203 21
205 156
207 129
207 88
208 6
208 77
211 13
213 194
215 166
215 251
216 41
216 78
217 129
217 201
218 226
218 279
218 69
219 10
219 257
219 291
220 226
220 262
220 78
222 202
223 108
223 193
224 127
224 186
224 284
225 173
225 82
226 254
226 30
227 119
227 169
227 179
227 200
228 72
230 158
230 158
230 165
230 166
230 255
231 136
231 46
232 102
232 161
232 200
233 272
234 71
235 230
235 77
236 44
237 163
237 168
239 164
239 94
241 62
242 139
243 294
245 264
245 81
246 299
249 186
249 225
250 108
250 294
250 31
250 80
251 5
252 107
253 113
254 27
254 73
254 75
255 72
256 105
256 133
256 231
257 20
257 245
259 100
259 97
260 198
262 117
262 7
262 84
264 1
264 280
264 53
266 166
266 177
266 224
266 26
266 277
268 256
268 287
268 45
269 187
269 225
270 186
270 230
271 243
271 260
271 280
271 96
272 219
272 86
272 99
273 269
274 123
275 118
275 16
275 207
275 40
275 68
276 138
276 142
276 266
277 143
277 300
278 107
278 264
279 163
279 194
279 266
279 74
280 175
280 241
282 186
282 256
283 24
283 98
284 114
284 202
284 279
286 182
287 144
287 170
287 282
288 294
290 101
290 131
290 230
291 172
294 128
294 193
294 290
295 127
295 60
296 100
296 200
298 180
298 299
299 175
299 290
300 216




*/