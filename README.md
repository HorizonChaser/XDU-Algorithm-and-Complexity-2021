# 这是啥

西电 2021 年双创周课程 "算法及其复杂度分析" 的答案仓库

# 里面都有啥

三次作业的答案, 或者说提示

出于版权考虑, 不能提供作业要求的原文件及代码

虽然本人交上去的作业是对的, 但是并不对 仓库中内容的正确性 和 因为作业要求的修改造成的不一致导致的任何错误 进行任何保证 ~例行甩锅声明😂~

# 三次作业

## Task1: Benchmarks for the case study task

**这是 Windows 平台下的操作, 如果你用 Linux/MacOS 的话, 我相信出了问题你也能自己搞定** ~(要不还是用Windows吧...)~

1. 编译源代码, 这包含贪心 `n3a-gd.c`, 穷举 `n3a-es.c`, 动态规划 `n3a-dm.c` 三种算法的源代码和数据生成器 `n3a-gen.c`
    - 为了减少程序中输出造成的时间误差, 可以把代码中的输出部分删除
    - Windows 平台的编译命令如下 (如果你已经装好了 GCC 的话, 没装好请自行搜索教程...)
      - 在命令行中, 切换到你源代码所在的路径, 然后
      - `gcc n3a-gd.c -O2 -o n3a-gd.exe`
      - `gcc n3a-es.c -O2 -o n3a-es.exe`
      - `gcc n3a-dm.c -O2 -o n3a-dm.exe`
      - `gcc n3a-gen.c -O2 -o n3a-gen.exe`
2. 生成测试数据
    - 使用 `.\n3a-gen [size] > t[size]`, 请自行把 `[size]` 替换为数据大小
    - 对一般的电脑来说, **贪心和动规的数据大小最大可到几千, 穷举一般不超过 40**, 可以尽可能多测几组
3. 测试执行时间
    - 由于我没有搞定计时用的 powershell 脚本咋写 (其实写出来了, 但是误差贼大), 所以我用的 `MSYS2`, 这样就可以用 `time` 命令简单**而靠谱**地计时了
    - 如前所述, 切换命令行的当前路径
    - 例如对于贪心算法 (对应之前我们编译得到的 `n3a-gd.exe`), 在数据大小为 5 时 (对应的输入文件为 `t5`), 计时命令如下, 别的情况看着改改
      - `time ./n3a-gd < t5`
    - 如果一切顺利的话, 你可以看到三个时间 `real` `user` 和 `sys`, 在这里我们统一采用 `real`
    - 把**每个算法在每个数据大小下所用的时间**记录到表格中
4. 画图, 写报告, 可以参考仓库中 `/Task 1` 中的文件

## Task2: Turing Machine (TM)

**和助教与教授确认好写哪个/哪些题, 希望不要再出现把几乎所有题都写了的无用功了🤦‍** ~2021年夏天的悲剧~

- 使用图灵机编程, 解决特定的问题
- 老师建议的图灵机在 [这里](http://morphett.info/turing/turing.html)
- 但实际上和老师沟通之后, 你也可以用其他的图灵机, 比如 [这个](https://turingmachinesimulator.com/)
- **本仓库中的 Task2 采用第二个图灵机**
- 每道题的代码中要附上算法解析, 测试用例和状态图 (都用英文)
- 仓库中的示例是 `Replace “abc” by “cc” within a word in alphabet {a,b,c}` 这道题
  - 因为这题才是我应该写的, 所以只有这道题有状态图
- 状态图可以使用 [这个在线工具](https://app.diagrams.net/) 绘制, 还算好使

## Task3: Matrices, dynamic memory allocation

- 给定大小, 生成一个矩阵, 用随机数填充
- 按照**给定的路径**, 先输出路径上的元素
- 再把这些元素从小到大排序, 再填回到路径上
- 最后输出修改后的矩阵
- 由于大小不固定, 矩阵的生成与路径上元素的保存需要动态内存分配
- 路径的生成可以直接使用若干个 `for` 循环 (最简单), 或者如果你想的话, 也可以用 `DFS` 之类的算法
- 同样的, 在你的代码中写上算法说明, 你写的是哪个路径和注释, 并附上流程图
- **你要完成的路径种类同样可能和你的编号有关, 请务必提前和助教与教授确认好 - 如果你不想做无用功的话**

# 最后

各位加油, 只要作业和最后的考试用心写分是不会低的 (真的, 你甚至可能能拿到最高分 (滑稽.jpg))
