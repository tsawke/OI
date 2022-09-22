# Tsawke's Exam Amusement

|   题目名称   |   雪球游戏    | 这是一道送分题 - IO交互 | 这是一道送分题 - grader交互 |              打倒llq               |
| :----------: | :-----------: | :---------------------: | :-------------------------: | :--------------------------------: |
|   题目类型   |   dark模拟    |    水的一批的交互题     |        更水的交互题         | 这场娱乐赛的核心，奇奇怪怪的对抗题 |
|   题目目录   |   snewbal1l   |         hackllq         |        hackllq_again        |               f1ght                |
| 源程序文件名 | snewbal1l.cpp |       hackllq.cpp       |      hackllq_again.cpp      |              name.cpp              |
|  输入文件名  | snewbal1l.in  |            \            |              \              |                 \                  |
|  输出文件名  | snewbal1l.out |            \            |              \              |                 \                  |
|   时间限制   |     50ms      |         1000ms          |           1000ms            |                 \                  |
|   内存限制   |    1024MiB    |         512MiB          |           1024MiB           |                 \                  |
| 提交文件限制 |    100KiB     |         100KiB          |           100KiB            |               100KiB               |
|   数据组数   |      10       |           10            |             10              |                 \                  |
|   满分分数   |      100      |           100           |             100             |                100                 |

## 注意事项

1. 所有文件名均保证为小写（友情提示：请格外注意文件名）。
2. C++ 中 `` main() `` 函数返回值必须为 `` int `` 且为 $ 0 $。
3. C++ 编译器开启 C++14 标准及 O2 优化。
4. 提交的程序源文件需独立文件夹。
5. 结果比较方式为全文比较（忽略行末空格及行尾回车）。
6. 程序可使用的栈空间限制与对应题目内存限制一致。
7. 评测采用机器配置为：11th Gen Intel(R) Core(TM) i5-11320H @ 3.20GHz。 
8. 编译选项为：`` g++ -o sample sample.cpp -lm -Wl,--stack=2147483647 -std=c++14 -O2 ``。
9. 对于本地 Linux 环境下调试时，可以添加编译选项：`` -fsanitize=undefined,signed-integer-overflow,address `` 以检测未定义行为、整数溢出，地址越界等问题。
10. 对于提答题请将 .out 为扩展名的文件统一放到子目录下。

# 雪球游戏（snewbal1l）

## 关于 T1 的心路历程

从 OI 的角度来看，这道题是很失败的、很无意义的、很浪费时间的，这道题可能更符合“为了出而出”，而并未考察任何算法，只是超过 12K 的码量的堆砌而形成的高难度长时间以及难以调试。

而我出这道题的本意更多也就只是“为了出而出”，因为是第一次出题，这道 T1 更多是希望能够通过这一道题面几千字的大模拟，来让我更去注意与考虑到题目的细枝末节，尽量让题目更严谨更合理。

因此，这道很奇怪的 T1 便诞生了，所以最终这道 T1 可以认为是一个 ex，也就是附加题，可以仅作观赏食用，当然如果真的能做出来也是可以得到 $ \texttt{pts} $ 的。（虽然我认为不可能有人做，不过如果有时间也可以考虑简单读一下这道题，尤其是题目背景，题目的切入点也是需要一点思考的，而并不是无脑的模拟）

当然，实话实说，这道题按照我原来的想法，是想要出的更巧妙点的，按照我的本意，这道题最终会形成一个与 Unity3D 的实现机制十分相似的模拟，全程的判定都与帧率这一核心息息相关，但是最终确实实力不济，如果按照这个思路强行模拟的话，码量实在是太大了，题目本身的叙述也将需要更加严谨很多，所以最终选择加了很多的限制让这道题变得没有那么巧妙，为了让实现变得简单，从而使题变得有些呆板与无趣，也请各位见谅。

于是——这道题便被放到了娱乐赛中。

## 题目背景

某一天早上，当 tsawke 打开机房大门的时候，突然发现天地之间一片苍茫——机房下雪了！tsawke 自然想去打雪仗，但是这样可能会感冒，于是 tsawke 决定趁着 llq 还没到机房，拉着 cc0000，sssmzy，zpair 一起去玩风靡全球的游戏 **Snewbal1l**，首字母最接近的 tsawke 和 sssmzy 被分配到了一组，首字母差距最大的 zpair 和 cc0000 被分配到了一组。

而对于常玩游戏的你们一定知道，很多游戏的帧率会影响到游戏过程中的判定。

如果你了解过 Unity3D，一定知道每一帧都会调用一次 `` Update() `` 函数，且其中我们经常使用这样一个常量：`` Time.deltaTime ``，举个例子，对于 C# 中的 `` transform.Translate(x, y, z) `` 函数，我们可以这么理解：

若写成 `` transform.Translate(0, 0, 1 / 60 * 10) `` 即 `` Update() `` 每执行一次物体移动 $ \dfrac{1}{6} $ 米，此时如果是 $ 60 $ fps 则每秒移动 $ 10 $ 米，若 $ 30 $ fps 则每秒仅能移动 $ 5 $ 米。 

若写成 `` transform.Translate(0, 0, Time.deltaTime * 10) ``，则若 `` Update() `` 每秒执行 $ 60 $ 次，即 $ 60 $ fps，最终效果每秒移动 $ 10 $ 米。

而对于上面的写法，若 `` Update() `` 每秒执行 $ N $ 次，即 $ N $ fps，最终效果仍然是每秒移动 $ 10 $ 米。

可以粗略地认为，`` Time.deltaTime `` 的值就是 $ \dfrac{1}{N} $。

我们一般通过这种方式来保证对于使用不同帧率的玩家，游戏总是公平的，而游戏 **Snewbal1l** 却默认不使用 `` Time.deltaTime ``。

## 题目描述

对于 2v2 非回合制游戏 **Snewbal1l**，存在一个有边界的二维矩形地图，横纵的单位距离均定义为 $ 1 $ 米，我们会给定一些游戏的基础信息（详见输入格式），对于每个角色都会有初始的一些信息，又有若干条不同玩家在不同时刻的操作信息，它们是以秒数来记录的，我们定义某一队胜利当且仅当另一队两个人血量均为 $ 0 $，而你需要计算出在游戏中哪一队胜利，四个人的电脑最终的帧率和四个人的剩余血量（已死亡记为 $ 0$），游戏结束的时间。

定义瞬时性操作为瞬时完成的，持续性操作为需要消耗帧数的，且保证对于未限定消耗帧数的均认为是瞬时性操作。

显然在游戏中一定会出现每一秒操作后不同玩家的游戏结果不同的情况，由于这是一个不公平的游戏，对于持续性操作，所以我们会按照玩家之间输入操作顺序的先后作为优先级并叠加影响，即若 tsawke 在 sssmzy 之前操作，在 tsawke 的帧率下处理一遍持续性操作，并记录最终的状态，若游戏未结束，则保留当前的状态并在 sssmzy 操作时再次以 sssmzy 的帧率重新处理一遍所有人的持续性操作。换句话说，每个人的持续性操作都可能被执行四遍。

对于任意一个角色有如下几个信息：

* 初始位置 $ \texttt{(x, y)} $
* 初始生命值 $ \texttt{HP(Health Point)} $
* 最大生命值 $ \texttt{maxHP} $
* 职业 $ \texttt{job} $
* 攻击力 $ \texttt{attack} $
* 防御力 $ \texttt{defence} $
* 朝向 $ \texttt{direction(1-up 2-right 3-down 4-left)} $
* 雪球速度 $ \texttt{velocity} $
* 持久力 $ \texttt{durability} $

对于所有玩家都有如下的操作：

* `` "*" ``：向着当前朝向丢一个雪球，每一帧向前闪现 $ \texttt{velocity} $ 米，击中每次移动的起点和中点中的所有玩家，伤害为攻击力。
* `` "+" ``：在接下来的 $ \texttt{durability} $ 帧中使防御力增加 $ 20\% $。
* `` "w" ``：在一帧的时间里向上移动 $ 1 $ 米。
* `` "a" ``：在一帧的时间里向左移动 $ 1 $ 米。
* `` "s" ``：在一帧的时间里向下移动 $ 1 $ 米。
* `` "d" ``：在一帧的时间里向右移动 $ 1 $ 米。
* `` "t" ``：向右旋转方向，即将朝向进行如下变换：$ 1 \rightarrow 2, 2 \rightarrow 3, 3 \rightarrow 4, 4 \rightarrow 1  $。

---

对于不同的职业，有如下信息和特定操作组合：

1. **soldier**

基础信息：

* 初始生命值 $ \texttt{HP(Health Point)} $ ： $ 100 $
* 最大生命值 $ \texttt{maxHP} $ ： $ 100 $
* 攻击力 $ \texttt{attack} $ ： $ 20 $
* 防御力 $ \texttt{defence} $ ： $ 10 $
* 雪球速度 $ \texttt{velocity} $ ： $ 2 $
* 持久力 $ \texttt{durability} $ ： $ 30 $

特定操作：

* `` "f" ``：对自己周围八个方向的距离小于等于 $ 1 $ 的角色（不包含与自己重合的）造成 $ 3 $ 倍 $ \texttt{attack} $ 的伤害。
* `` "g" ``：若 $ \texttt{HP} $ 小于 $ maxHP \times $ $ 10\% $，则将自己的帧率降低为原来的 $ 80\% $，并使全队队友 $ \texttt{attack} $ 变为原来的 $ 120\% $，否则 $ \texttt{HP} $ 变为原来的 $ 70\% $。

2. **assassin**

基础信息：

* 初始生命值 $ \texttt{HP(Health Point)} $ ： $ 20 $
* 最大生命值 $ \texttt{maxHP} $ ： $ 40 $
* 攻击力 $ \texttt{attack} $ ： $ 50 $
* 防御力 $ \texttt{defence} $ ： $ 1 $
* 雪球速度 $ \texttt{velocity} $ ： $ 5 $
* 持久力 $ \texttt{durability} $ ： $ 5 $

特定操作：

* `` "f" ``：对自己面前距离小于等于 $ 2 $ 的角色（不包含与自己重合的）造成 $ attack \times \dfrac{maxHP - HP}{maxHP} $ 的伤害，注意这里的 $ HP $ 和 $ maxHP $ 均指受到攻击者的属性。
* `` "g" ``：将自己的血量变为原来的 $ 90\% $ 并向自己的面前移动 $ 3 $ 米。

3. **tank**

基础信息：

* 初始生命值 $ \texttt{HP(Health Point)} $ ： $ 500 $
* 最大生命值 $ \texttt{maxHP} $ ： $ 800 $
* 攻击力 $ \texttt{attack} $ ： $ 3 $
* 防御力 $ \texttt{defence} $ ： $ 50 $
* 雪球速度 $ \texttt{velocity} $ ： $ 1 $
* 持久力 $ \texttt{durability} $ ： $ 2 $

4. **magician**

基础信息：

* 初始生命值 $ \texttt{HP(Health Point)} $ ： $ 100 $
* 最大生命值 $ \texttt{maxHP} $ ： $ 100 $
* 攻击力 $ \texttt{attack} $ ： $ 20 $
* 防御力 $ \texttt{defence} $ ： $ 5 $
* 雪球速度 $ \texttt{velocity} $ ： $ 2 $
* 持久力 $ \texttt{durability} $ ： $ 10 $

特定操作：

* `` "f" ``：使所有敌人的 $ \texttt{defence} $ 变为原来的 $ 80\% $。
* `` "g" ``：使所有队友的 $ \texttt{attack} $ 变为原来的 $ 120\% $。
* `` "x" ``：敌对方所有人任意一人若满足 $ \texttt{HP} < \texttt{maxHP} \times 10\% $，则其直接死亡（若两人均满足的均死亡），否则自己 $ \texttt{HP} $ 变为原来的 $ 60\% $。
* `` "p" ``：使敌对方所有人的帧率变为原来的 $ 120\% $，己方所有人的帧率变为原来的 $ 80\% $。

5. **priest**

基础信息：

* 初始生命值 $ \texttt{HP(Health Point)} $ ： $ 100 $
* 最大生命值 $ \texttt{maxHP} $ ： $ 100 $
* 攻击力 $ \texttt{attack} $ ： $ 5 $
* 防御力 $ \texttt{defence} $ ： $ 5 $
* 雪球速度 $ \texttt{velocity} $ ： $ 2 $
* 持久力 $ \texttt{durability} $ ： $ 10 $

特定操作：

* `` "f" ``：使所有队友的 $ \texttt{HP} $ 变为原来的 $ 150\% $。
* `` "g" ``：使所有队友的 $ \texttt{defence} $ 变为原来的 $ 120\% $。

---

一些细节：

1. 若玩家的位置超出地图则判定为死亡。
1. 如果有不合法的输入则忽略，若攻击等超出边界亦忽略（地图边界为从 $ 1 $ 到最大值）。
1. 只有当某一秒的所有玩家瞬时性操作全部完成和持续操作全部完成的两个时候才判定游戏是否结束。（即如果在同一秒内按照操作顺序一名玩家已经死亡，但仍会执行其剩下的操作，只对“需要判定敌方是否已经死亡”的技能来说其为死亡状态，只有判定游戏是否结束时其才会真正死亡）。
1. 对于 3 的更详细解释：如 zpair 在某秒中优先操作，在 zpair 操作的过程中 tsawke 已经死亡，但是在这之后仍会执行此秒内 tsawke 的操作，但假设 cc0000 的职业是 priest，使用技能时则认为 tsawke 已经死亡，不在判定范围内，此时若 sssmzy 亦不符合要求，则 cc0000 受到惩罚。
1. 对于 3 的额外规定：对于在持续性操作中，因移动而走出边界的情况，我们特殊规定其若可以在本秒的之后操作中回到合法区域中则不视为死亡，也就是说移动过程中可能存在过程中有负值的坐标但最终合法的情况。
1. 我们认为在某一秒内雪球是可以飞出边界并击中临时在边界外的玩家。
1. 发射雪球的过程认为其不消耗帧数。
1. 我们认为每当雪球与玩家重合时，玩家受到攻击一次。
1. 对于每一秒的开始的瞬间我们认为雪球不会对玩家造成伤害，从第一帧开始才可能会对玩家造成伤害。
1. 若操作超出当前秒帧数，则忽略超出的部分。
1. 存在队友伤害，存在自我伤害。
1. 不存在两方队员同时获胜的情况。
1. 保证时刻升序输入。
1. 保证防御时间小于整个游戏过程中任意时刻任意玩家的帧率。
1. 对于百分比形式的增加，最终的值均下取整保留整数。
1. 对于未标注在一定帧率中实现的，均认为是瞬间完成。
1. 对于 $ \texttt{durability} $，若其大于当前的帧率，则认为其就是当前玩家的帧率，即每次的包含 $ \texttt{durability} $ 的操作最多持续 $ 1 $ 秒。
1. 对于移动类的按照输入顺序先后进行移动，即若输入 `` "waa" ``，则第一帧向上走 $ 1 $ 米，第二、三帧分别向左走 $ 1 $ 米。
1. 伤害的计算，为攻击者攻击时计算出的伤害与受击者防御力做差，若最终伤害低于 $ 1 $，则仍然会造成 $ 1 $ 点伤害的钝伤。
1. 若 $ \texttt{HP} $ 超过  $ \texttt{maxHP} $ 则自动变为 $ \texttt{maxHP} $。
1. 所有“全队队友”均包含自己。

## 输入格式

首四行每行两个字符串，第一个字符串为玩家名称，第二个字符串保证格式为数字+fps后缀，如 `` "60fps" ``，表示某个玩家电脑的初始帧率。

接下来一行为两个整数，分别表示地图的纵和横的大小。

接下来四行每行两个字符串，第一个字符串为玩家名称，第二个字符串为职业名称。

接下来四行每行一个字符串和三个整数，分别表示玩家名称、初始坐标的横坐标和纵坐标、朝向。

接下来有若干组数据，每组数据满足如下格式：

* 首行一个整数，表示当前的信息的发生时刻。
* 若输入的整数为 $ -1 $，则代表所有玩家的操作均结束。
* 接下来四行，四行之间有序，每行两个字符串，第一个字符串表示玩家名称，第二个字符串记录了这个玩家在此时刻的所有操作，保证第二个字符串长度为 $ \texttt{len} $，具体限制详见后文。
* 输入顺序即为玩家之间的操作顺序。
* 保证在每秒每个玩家的操作中，`` "+" `` 最多仅出现一次，并一定在 `` "wasd" `` 之前。
* 保证在每秒每个玩家的操作中，`` "*" `` 最多仅出现连续的一段，并一定在 `` "wasd" `` 之前。
* 不保证四个玩家的输入顺序。

保证输入文件以 $ -1 $ 结尾。

## 输出格式

首行一行字符串，表示获胜方：

> 具体地，若 tsawke 和 sssmzy 获胜，则输出 `` "tsawke & sssmzy are the winners!" ``。
>
> 若 zpair 和 cc0000 获胜，则输出 `` "zpair & cc0000 are the winners!" ``。
>
> 若两方平局，则输出 `` "No one is the winner!" ``。

第二行，输出一个整数，表示游戏的具体结束时刻，若游戏未结束则输出 $ -1 $。

第三行，输出四个整数，按顺序表示 tsawke, sssmzy, zpair, cc0000 四个人的剩余血量，已死亡输出 $ 0 $。

（注意此时输出的是在某一秒，任意一个玩家的操作完成后的血量，具体定义可参考细节中的对判定游戏是否胜利的限制）

第四行，输出四个整数，按顺序表示四个人电脑的最终帧率。

## Examples

### Input_1

> ```
> tsawke 60fps
> sssmzy 60fps
> zpair 60fps
> cc0000 60fps
> 5 5
> tsawke tank
> sssmzy soldier
> zpair assassin
> cc0000 magician
> tsawke 1 2 3
> sssmzy 2 2 3
> zpair 3 3 3
> cc0000 4 4 3
> 1
> tsawke s
> sssmzy a
> zpair a
> cc0000 w
> -1
> ```

### Output_1

> ```
> tsawke & sssmzy are the winners!
> 1
> 500 0 0 0
> 60 60 60 60
> ```

### Input_2

> ```
> tsawke 30fps
> sssmzy 60fps
> zpair 144fps
> cc0000 60fps
> 20 20
> tsawke priest
> sssmzy tank
> zpair magician
> cc0000 soldier
> tsawke 7 7 3
> sssmzy 5 5 2
> zpair 10 15 1
> cc0000 6 6 4
> 1
> tsawke fgfg
> sssmzy +******sdwaasdasdasd
> zpair pfffxfffffffffffxx
> cc0000 fffffffffffffffgg
> 128
> tsawke *gggfgfgf
> sssmzy ****
> zpair pfffffffffffff
> cc0000 fffff**tttffffffffffffgg
> -1
> ```

### Output_2

> ```
> zpair & cc0000 are the winners!
> 1
> 0 0 21 49
> 36 72 115 48
> ```

### Input_3

> ~~~~
> tsawke 253
> cc0000 91
> sssmzy 33
> zpair 209
> 28268 9400
> tsawke priest
> cc0000 tank
> sssmzy priest
> zpair magician
> sssmzy 27753 5628 2
> zpair 9531 3692 4
> cc0000 8676 4963 3
> tsawke 1440 8070 4
> 73
> sssmzy ***********************************wsaadtswgwtwtfswtdasatfaaswatdwsawstwwwaaaasga
> zpair +aawwttw
> cc0000 +*****************************************dswaasawaasadsaawtwtssawdwstadwtsdwsawsdtswaw
> tsawke ********************wfagswagdssgsgfwdasgwwwdadtfadtfwsdswswwfwswdsada
> 127
> zpair ***********************************gdwadtpwaawffdxxpsxwsgxpxdpfwwaptttadxatwawaaag
> cc0000 *******************twwdsdsdsawstda
> sssmzy ***awwagsdsdwtgwwstw
> tsawke +******************************************fwasawtfs
> 223
> sssmzy +***************************wsfwastgdafawdtgtwgwwggatdwatwswfwgdatsdsagas
> zpair aa
> tsawke ****************************************agadggdawttasgwdtsffgfawfaawgfwgsfswswtadw
> cc0000 ********daatsdwssatatwsstwdsaswsswswtsdawda
> 244
> zpair *************axsftpxwtwadfxwxasxpwxxsaapagxxaafxwtxf
> tsawke wtwtsttafsfwfawggawawdgffsdgfaswawdfswdfwwasasttawdwdaawgswsttawwwgttwfgwfww
> sssmzy +*****************************wttgw
> cc0000 twtwwsaassawadasattdwtawwtwwwdwaadssaaawdaawwaswdwstawaswwswsdwswastsaatadsstaawsstatssdtattssdtddtt
> 282
> sssmzy +******************************************fwfdwgwwtadfgtsfwsttfaddaaddgwddwwa
> cc0000 ***********dswstatwwawwasdddaaadwssssddstawdwtwwwswasadswwwsdtawwsaawsaaadtsadattttwtaatwdwwsadwwasd
> tsawke ****************************wsawtgfdswwdw
> zpair ************************fwfftdwpxaxgaxppdpwdaxxxgspsxtwwdwwaawtpswawtsxtpdgdtsfpxtxxxxsassstpwgpddgs
> 379
> cc0000 ************wawdswwswdwwadsddwsaaswsdddwwsttdwwwataassdwwsstddwwadwtsawttwtawwssadsdsdsadaaaawwwasta
> sssmzy *******ddwfwwawaaw
> zpair *************************************************xtpawafxwwggatdfxpxpwtsgxdgwttpttxwpfsspaswxawstasw
> tsawke +**********************wwsswfwsawfwgfwatwwd
> 476
> cc0000 tasswwsdttsddtaadasasasawwdsadwawaswataadwwaawatsdsdsadaaaswwastwwddswdwddad
> zpair +ftwsttt
> sssmzy *********************************tfwwswgtgwsttaga
> tsawke +ftwdtfgwdtftdffwwsddgttwasawassaffdfswgwgdaadwtdaddwsfswtwwftawwsass
> -1
> ~~~~

### Output_3

> ```
> No one is the winner!
> -1
> 100 100 0 413
> 59598 7312 0 0
> ```

## 数据范围

部分数据范围及约定已在题面中标注，剩余数据范围限制如下：

我们定义输入操作数据的组数为 $ n $，地图纵横大小分别为 $ \texttt{height, width} $。

对于 $ 20\% $ 的数据，保证输入的操作仅为 `` "wasd" `` 。

对于 $ 70\% $ 的数据，保证 $ 1 \le \texttt{len} \le 10^3 $。

对于 $ 100\% $ 的数据，保证 $ 1 \le \texttt{len} \le 10^5, 1 \le n \le 100, 1 \le \texttt{height, width} \le 10^5 $。

数据很友好。

## 提示

请仔细阅读题目背景，并注意题面中的细节提示，思考应如何处理。

注意当游戏结束时请使游戏直接结束，可以直接忽略后面的输入，否则可能会导致超时。

Tips：可以考虑将瞬时性操作与持续性操作分开考虑，并且对于每一位玩家每秒的状态分开考虑。

# 关于交互题

## 关于这两道交互题

以下信息均为个人理解，不保证正确性，如果发现不对的地方随时跟我说~

一般来讲交互题大致分为两种，grader 交互和 IO 交互。

grader 交互题大多是给你一个可以调用的函数，并让你实现一个函数。你只需要将提供给你的函数声明出来，并写好需要实现的函数，最终提交这一部分代码即可，而不需要实现 `  main()` 函数。

而对于 IO 交互题，大多会“重载”你的输入与输出，通过 stdout 来向提供的交互库传参，通过 stdin 来获取交互库的返回值，同时需要注意这类题均需要在每次询问后清空缓冲区。

回到本题，因为 T1 不可做，为了保证标准的 $ 400\texttt{pts} $，而我又不想改题号，所以 T3 被分割为了 T3-1 和 T3-2，各自 $ 100\texttt{pts} $，这两道题将会分别使用两种交互方式实现，可以当作对于交互题的练习。

同时对于这几道交互题和 SPJ，tsawke 会尽力去使其严谨，但不保证不会漏下在交互库里对所有数据的大小范围的限定，所以烦请各位不要特意去卡超出范围的数据，否则可能有直接 RE 的可能。

## 关于交互具体如何实现

对于刷新缓冲区，一般有以下几种写法：

```cpp
fflush(stdout);
std::cout << std::flush;
```

同时 ` endl ` 也可以在输出换行的同时刷新缓冲区，即：

```cpp
std::cout << std::endl;
```

如对于 IO 交互题，比较尽人皆知的便是“猜数游戏”，这里提供一个 Luogu 上的样例程序来便于理解交互的方式：

```cpp
#include <cstdio>
#include <iostream>

int main() {
  for (int l = 1, r = 1000000000, mid = (l + r) >> 1, res; l <= r; mid = (l + r) >> 1) {
    std::cout << mid << std::endl;
    std::cin >> res;
    if (res == 0) {
      return 0;
    } else if (res == -1) {
      l = mid + 1;
    } else if (res == 1) {
      r = mid - 1;
    } else {
      puts("OvO, I AK IOI"); // this statement will never be executed.
    }
  }
  return 0;
}
```

对于以上的程序我们通过 ` cout ` 来向交互库传递参数，并刷新缓冲区，此时交互库便会返回一个值，我们通过  `  cin` 来实现获取交互库的返回值。需要注意这里并不必须是 ` cin ` 或  ` cout `，只要使用的是标准输入输出的均适用。当程序结束时 ` return 0; `。

而对于 grader 交互题，有如下 Luogu 上的样例：

```cpp
#include <cstdio>                         // 在本题中并不是必须的

extern "C" int Seniorious(int);           // 在这里需要声明一次交互库给出的函数。

extern "C" int Chtholly(int n, int OvO) { // 在这里实现交互库要求你实现的函数。
  int ans = 1;
  for (int l = 1, r = n, mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) if (Seniorious(mid) >= 0) {
    r = (ans = mid) - 1;
  } else {
    l = mid + 1;
  }
  return ans;
}
```

首先我们需要在全局作用域声明交互库中的函数，与你需要实现的函数，见样例程序。

然后你需要实现这个函数，如样例程序，可以直接通过调用声明过的交互库中的函数，即 ` Seniorious(int) `，计算结束后返回要求的返回值即可，提交时也只需要提交这些代码片段。

## 关于交互如何本地调试

Tips：因为咱们大多为 Windows 环境，所以这里以 Windows 为例，Linux 可以类比一下，差别不大。

Tips：以下均对于 grader 交互题而言，若为 IO 交互题，则仅需按一般形式测试即可。

对于交互题一般会给交互库的源代码，假设交互库为 ` interactive_lib.cpp `，提交的程序为 ` submit.cpp `，假设两个文件在同一目录，且命令行中所在位置为文件所在位置，那么可以使用如下命令：

```bash
g++ interactive_lib.cpp submit.cpp -o 1.exe -std=c++14 -lm -Wl,--stack=2147483647
```

即可生成名为 ` 1.exe ` 的可执行文件。

关于 g++ 的配置，命令行和 powershell 的用法等，这里不再赘述。

生成可执行文件后在命令行输入：

```bash
1.exe
(examples)
```

也就是说，回车后输入将**样例输入**输入，即可得到程序的输出。

## 关于这两种交互题

似乎 NOI 系列的比赛均采用 grader 交互？不太确定。

如果 IO 类的交互 NOI 系列赛不考的话，可以把这个当成一个小拓展~

# 这是一道送分题 - IO交互

## 题目背景

是的这是一道送分题。

tsawke 成功 hack 进了 neooj.com:8082/oldoj，但是他只获得了数据库中大量用户密码的 md5 形式，tsawke 需要获取这些用户的明文密码来勒索 llq，但是他不知道如何做，只能帮你进行 md5 的正向过程，靠你来实现 md5 的破解。

为了机房的未来，这道题一定要切呀！

## 题目描述

注意：由于 LemonLime 似乎不支持 IO 交互题，所以 tsawke 在 Luogu 上配置了这道题，最终会在 Luogu 上评测，然后记录分数。

我们得到了 llq 网站数据库中 $ n $ 个用户密码的 md5，你需要**一次性**读入这些数据，在这之后你可以进行至多 $ 10^4 $ 次询问，每次询问一个字符串，然后获得这个字符串的 md5，当你询问完成后需要输出一个 ` "Completely Hacked!" `，并在这之后输出着 $ n $ 个用户的明文密码。

Tips：此题时间复杂度可以通过一些优化而去掉一个 $ \log $，但因交互题一般不要求时间复杂度，而是要求函数调用次数或询问次数，所以本题也不会去卡时间复杂度。

Tips：同时这道题也并不是一个优秀的交互题，因为此题并没有去可变地限制函数调用次数，当成练手题即可。

## 实现过程

这里我们规定，“**输入**”即为从**标准输入**中获取，“**输出**”即为向**标准输出**中输出，**并刷新缓冲区**。

Tips：这里的**输入**实际上指的是交互库输出的返回值，你进行读入，**输出**即为向交互库传参。

第一行**输入**一个整数 $ n $，代表用户密码个数。

接下来 $ n $ 行每行**输入**一个字符串，表示第 $ i $ 个密码的 md5。

接下来至多 $ 10^4 \times 2 $ 行，对于每两行：

1. 第一行**输出**一个字符串，表示某个密码的明文。
2. 第二行**输入**一个字符串，表示该密码明文对应的 md5。

接下来一行**输出** ` Completely Hacked! `，表示询问结束。

接下来 $ n $ 行每行**输出**一个字符串，表示用户密码的明文。

## 数据规模

令明文字符串长度为 $ len $。

对于 $ 50\% $ 的数据，保证 $ 1 \le n \le 100, 1\le len \le 2 $。

对于 $ 100\% $ 的数据，保证 $ 1 \le n \le 10^4, 1 \le len \le 4 $，保证字符串中仅含有数字且不含前导 $ 0 $。

## 评分标准

若你的询问次数超过 $ 10^4 $，则获得 $ 0\texttt{pts} $。

若你的输出不合法，则获得 $ 0\texttt{pts} $。

若你输出的密码明文有任何错误，则 tsawke 将无法成功勒索 llq，获得 $ 0\texttt{pts} $。

若你的输出全部正确，获得 $ 100\texttt{pts} $。

## 关于本地调试

对于 IO 交互题，似乎一般难以进行本地调试，可能也就是因此，NOI 系列比赛都采用的是 grader 交互，这里为了方便各位调试提供了一个头文件。

头文件可在 ` Tsawke's Exam - Issue/hackllq/md5.h ` 找到。 

你可以调用一个叫做 ` md5_hash_hex ` 的函数，其原型是：

```cpp
inline std::string websocketpp::md5::md5_hash_hex(std::string const &)
```

使用方法：在需要生成 md5 的 cpp 文件引入如下头文件：

```cpp
#include "md5.h"
```

调用该函数，并在将明文字符串作文参数传入，将会返回 md5 形式的字符串。

注意在提交的程序中不能使用 md5.h。

## Examples

### Input_1

> ```
> 3
> 45c48cce2e2d7fbdea1afc51c7c6ad26
> eccbc87e4b5ce2fe28308fd9f2a7baf3
> 1679091c5a880faf6fb5e6087eb1b2dc
> ```

### Output_1

> ```
> 9
> 3
> 6
> ```

# 这是一道送分题 - grader交互

## 题目背景

是的这是一道送分题。

tsawke 成功 hack 进了 neooj.com:8082/oldoj，但是他只获得了数据库中大量用户密码的 md5 形式，tsawke 需要获取这些用户的明文密码来勒索 llq，但是他不知道如何做，只能帮你进行 md5 的正向过程，靠你来实现 md5 的破解。

为了机房的未来，这道题一定要切呀！

## 题目描述

我们得到了 llq 网站数据库中 $ n $ 个用户密码的 md5，你需要将其变成明文，以帮助 tsawke 成功地 hack 掉 llq 的数据库，并对 llq 进行勒索。

Tips：此题时间复杂度可以通过一些优化而去掉一个 $ \log $，但因交互题一般不要求时间复杂度，而是要求函数调用次数或询问次数，所以本题也不会去卡时间复杂度。

Tips：同时这道题也并不是一个优秀的交互题，因为此题并没有去可变地限制函数调用次数，当成练手题即可。

注意：你的程序禁止从标准输入读数据、向标准输出写数据或与任何文件交互。

## 具体描述

你需要实现一个函数：

```cpp
std::string HackLLQ(string md5);
```

这个函数的作用是，对于参数中的 md5，将其变为明文并返回。

你可以调用交互库中的以下函数：

```cpp
std::string EncryptMD5(std::string plaintext);
```

 这个函数将会返回字符串 ` plaintext ` 的 md5，你最多可以调用 $ 10^5 $ 次这个函数。

## 数据规模

令明文字符串长度为 $ len $。

对于 $ 50\% $ 的数据，保证 $ 1\le len \le 2 $。

对于 $ 100\% $ 的数据，保证 $ 1 \le len \le 4 $，保证字符串中仅含有数字且不含前导 $ 0 $。

## 评分标准

若你的函数调用次数超限，则获得 $ 0\texttt{pts} $。

若你的函数返回值错误，则 tsawke 将无法成功勒索 llq，获得 $ 0\texttt{pts} $。

若你的函数全部正确，获得 $ 100\texttt{pts} $。

## Tips

对于前文提到的函数的声明，在这道题里即为：

```cpp
extern std::string EncryptMD5(std::string);
extern std::string HackLLQ(std::string);
std::string HackLLQ(std::string md5){
	//TODO
}
```

关于交互库的源代码已下发到 ` Tsawke's Exam - Issue/hackllq_again/interactive_lib.cpp `。 

**注意，此交互库仅供测试样例使用，实际评测时的交互库此交互库不同**。

## 输入格式

Tips：这里的输入格式仅为本地调试时使用，与交互过程本身无关。

第一行输入一个整数 $ n $。

接下来 $ n $ 行，每行一个字符串，表示密码的 md5。

## 输出格式

一共 $ n $ 行，表示密码的明文。

Tips：对于本地调试时，即为你的程序计算出来的明文，可以和样例输出比对。

## Examples

Tips：样例仅供本地调试使用，样例输入你都**不必读取**，样例输出你都**不必输出**。

### Input_1

> ```
> 3
> 45c48cce2e2d7fbdea1afc51c7c6ad26
> eccbc87e4b5ce2fe28308fd9f2a7baf3
> 1679091c5a880faf6fb5e6087eb1b2dc
> ```

### Output_1

> ```
> 9
> 3
> 6
> ```

# 打倒llq

## 题目背景

在 JDFZ 的一楼半最深处的房间，明亮的灯光下却驱不散机房中 tsawke, sssmzy, zpair, cc0000 心中的黑暗...机房已经数年在 llq 的统治之下，OIer 们苦不堪言。

终于，在一个雷雨交加的夜晚，随着夜空被一道闪光划破，OIer 们决定奋起反抗 llq，誓要推翻 llq 的统治。

表面上，他们团结一心，众志成城，但每个人的心里却仍然暗流涌动...人人都有着野心，因为即使推翻了 llq 的统治，机房最终也只能由一人统治，显然 OIer 们都想当这个人，在共同对抗 llq 的同时，他们心中也在思考如何同时打败其他人...

在众人的努力下，llq 终于被打败了，但是 OIer 们之间的竞争才刚刚开始。

众所周知，人与人之间的天赋不能一概而论，OIer 们的各项属性将会由当天娱乐模拟赛的 T1-T3 的成绩决定。

## 题目描述

llq 已经被打败了，现在为了获得更多的 pts，最终目标即为打败其他的 OIer。

我们定义当天的模拟赛中：

tsawke, sssmzy, zpair, cc0000 的分数百分比分别为 $ T1, T2, T3 $。

每一位 OIer 都会根据分数百分比获得一定的属性。（大模拟分数更高哦~）

共有如下几种属性：

* 初始生命值 $ \texttt{HP(Health Point)} $
* 最大生命值 $ \texttt{maxHP} $
* 攻击力 $ \texttt{attack} $
* 防御力 $ \texttt{defence} $

我们会根据前三道题的得分，来决定每一帧 OIer 的操作顺序。

对于每位 OIer，每一帧里有如下几种操作：

* `` "f" ``：攻击面朝方向的所有敌人（默认面朝方向为上）。
* `` "w" ``：向上移动 $ 1 $ 米，同时改变朝向。
* `` "a" ``：向左移动 $ 1 $ 米，同时改变朝向。
* `` "s" ``：向下移动 $ 1 $ 米，同时改变朝向。
* `` "d" ``：向右移动 $ 1 $ 米，同时改变朝向。

Tips：每秒会根据分数排名有一定概率固定扣除 $ 1 $ 的 $ \texttt{HP} $。

## 说明

**注意：以下代码块函数名称中如果有 name 字段，您均需要将其改成您自己的名字！**

我们目前支持的名字有：tsawke, sssmzy, zpair, cc0000。

请在其中选择您自己的名字并将 name 替换。

如对于：

```cpp
pair < int, int > name_SetInitialPosition(void);
```

应该写成如下的形式：

```cpp
pair < int, int > tsawke_SetInitialPosition(void){
	return make_pair(1, 1);
}
```

同时我们定义四个玩家 tsawke, sssmzy, zpair, cc0000 的序号分别为 1, 2, 3, 4。

---

我们为您提供了如下的 API，您需要在程序全局声明这些函数，也就是加上以下代码段：

```cpp
#include "default.h"
#include "f1ght.h"

extern GameStatus GetGameStatus(void);
```

以下是对这些函数作用的说明：

我们存在如下结构体：

```cpp
struct GameStatus
{
	int height, width;
	int mapStatus[::height + 1][::width + 1] = {};
	Player player[5];
};
```

`height` 和 `width` 记录了地图的高和宽，默认均为 $ 10 $。

`mapStatus` 记录了当前地图的状态，0为空地，1~4对应着对应玩家的位置，-1 对应着抵达该位置将会回复 $ 10\% $ 的血量。

`player[i]` 记录了玩家 $ i $ 的所有信息，具体如下：

```cpp
class Player {
public:
	int HP;
	int maxHP;
	int attack;
	int defence;
	int posX, posY;
	int towards;//1-up, 2-left, 3-down, 4-right
	int rank;
};
```

~~含义估计你们能看出来~~

Tips：$ HP $ 可能为负数，如果要判定是否死亡时请注意这一点。

您可以通过调用如下函数以获取最新的游戏状态：

```cpp
GameStatus GetGameStatus(void);
```

但是注意每帧您只能调用一次此函数，也就是仅每次执行您的 `name_NextFrame` 函数时可以调用一次该函数，我们并未对其进行限制，但请自觉遵守。

---

您需要实现如下的函数，以下是对这些函数的要求与说明：

```cpp
pair < int, int > name_SetInitialPosition(void);
```

设置你最初在地图上的位置，返回一个 `pair < int, int >`，表示位置在第 first 行 second 列。

注意：如果您返回的位置超出限制将会直接失败。

```cpp
char name_NextFrame(void);
```

根据您获得的信息来决定这一帧里您将进行什么操作。

合法的返回值有 `'w', 'a', 's', 'd', 'f', ' '`。

返回空格或其他值即意味着这一帧您将原地不动。

注意请不要在此函数中运算过长的时间！

注意：由于该题测评环境为 Visual Studio，不支持万能头文件，提交时请将万能头文件删去。

