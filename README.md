# OJ-TODO
## JDFZ
    1050
    1300
    1635
    2982
    dfs 1945 1946 1271 1532 1947 1948 1973 1621 1239 1807 1785 3117
    1788 [NOIP2012]文化之旅 T4

## Luogu
    1216
    3956 - Dijkstra
    1032


# AC
## JDFZ
    1929 求最长不下降序列长度
    1387 VIJOS-P1255 月饼盒
    1742 生成全排列
    1858 n皇后问题
    1859 n皇后问题again
    3117 勇敢的热气球驾驶者
    1270 [NOIP2004]合并果子 T2
    1418 [NOIP2000]单词接龙 T3
    1523 VIJOS-P1446 最短路上的统计

## Luogu
    1219 [USACO1.5]八皇后 Checker Challenge
    1019 [NOIP2000 提高组] 单词接龙
    5194 [USACO05DEC]Scales S
    5440 [XR-2]奇迹
    1378 油滴扩展
    1443 马的遍历
    1162 填涂颜色
    3956 [NOIP2017 普及组] 棋盘 - BFS
    5318 [深基18.例3] 查找文献
    3916 图的遍历
    3371 [模板]单源最短路径(弱化版)
    4779 [模板]单源最短路径(标准版)
    
## YBT
    1374 铲雪车(snow)
## BAILIAN
    1050 To the Max


# Problems
    diff. scanf(%s) && gets(s) && fgets(s) && cin.getline(s, n) (为什么cin.getline WA 而 scanf AC)
    只有fget相关的会读入'\n'之类的并存到s里吗?其他的是读入'\n'等停止但不保存到s里
        若使用fgets等,应该如何判断读入后的s数组是否为结尾等呢?输入结尾的话是否会存在s[n]=EOF(同时这里还有个char类型是否可以存EOF即-1)
        判断结尾时不同系统换行等应该都不一样,那么是应该写成如s[i]!=EOF && s[i]!='\n' && s[i]!='\r'这些是否可行?
        gets因无法判断长度被"禁用"了,那么cin.getline是不是没有什么问题了?
        对于strlen,显然其是从头到\0为止判断长度,那么如果是fgets获取的,结尾应该是\n,\r之类的还是\n和\0,返回的长度是否会包含\n等
    correct? scanf()!=EOF && (c = getchar()) != EOF && gets(s) != EOF...
        头文件中有宏定义EOF=-1, scanf输入失败返回-1. 对于getchar()如果读入失败返回-1赋值给char类型的c再跟EOF比较不会出错吗
        所有用于输入的函数读入失败返回值都是-1吗?cin可以不用!=EOF是因为cin读入失败返回0吗?
    diff. char c[size] && char *c && string
    undefined? e.g.https://blog.csdn.net/dpfordor/article/details/1958077
    环的定义就是至少有三个点吗,如果有自环等不能算作一个环吗
    对于一般的语句中的函数执行顺序，是否除了scanf，cin之类的其他的均是正向的?
        即如果输入1 2,那么如a[read()] = read()等均为a[1] = 2;如scanf("%d%d", &a[read()], &a[read()])

# TEXT-TODO
    https://zhuanlan.zhihu.com/p/89721008                       &数的因数个数与质因数分解的关系
    https://blog.csdn.net/liu16659/article/details/79093513     &最长不下降子序列详解
    https://blog.csdn.net/bell041030/article/details/88911180   &杨辉三角与组合数
    http://c.biancheng.net/view/597.html                        &C++ next_permutation
    https://www.cnblogs.com/Morning-Glory/p/11747744.html       &卡特兰数
    https://www.cnblogs.com/c1299401227/p/5370685.html          &C++ String
    https://zhuanlan.zhihu.com/p/377183341                      &命名规范
    https://developer.aliyun.com/article/619121                 &命名规范-aliyun
    https://xknote.com/blog/114975.html                         &memset初始化max&min
    https://www.cnblogs.com/chenleideblog/p/12745271.html       &对于堆(优先队列)的说明
    https://www.luogu.com.cn/blog/Tweetuzki/solution-p3366      &Borůvka (Sollin)最小生成树


# Website
    Luogu OJ        https://www.luogu.com.cn/
    JDFZ OJ         https://neooj.com:8082/oldoj/
    POJ             http://poj.org/
    POJ-Submit      http://bailian.openjudge.cn/
    OI WIKI         https://oi-wiki.org/
    Coding DevOps   https://monkey-hyx.coding.net/

    一本通           http://ybt.ssoier.cn:8088/index.php
    