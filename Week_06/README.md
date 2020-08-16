学习笔记
动态规划小结：
1. 打破自己的思维惯性，形成机器思维(循环、if-else)
2. 理解复杂逻辑的关键
3. 职业进阶的关键(不要人肉，分治、放权)

以三角形最小和为例，自顶向下分析
1. 找问题重复性(分治)：Problem(i,j) = min(SubProblem(i+1, j), SubProblem(i+1, j+1)) + Data(i,j);
2. 状态定义：f(i,j), 表示从[i,j]位置到最后一行的最小和
3. 转移方程：f[i,j] = min(f[i+1, j], f[i+1, j+1]) + Data[i,j]

关于动态规划：
   自顶向下分析：基本上等价于dfs + 记忆化
   自底向上分析：要有逆向分析的思维&意识

5 "easy" steps to DP:
  a. define subproblems
  b. guess(oart of solution)
  c. relate subproblem solutions
  d. recurse & memoize
     or build DP Table bottom-up
  f. solve original problem
