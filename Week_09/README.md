学习笔记

1. #### [不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)状态转移方程

   
   $$
   dp[i][j]=
   \begin{cases}
   0, &if\ obstacleGrid[i][j]\ \ ==\ 0\ \ (障碍物)\\
   dp[i+1][j] + dp[i][j+1], &if\ obstacleGrid[i][j]\ \ !=\ 0
   \end{cases}
   $$

   但对最后一行和最后一列有个特殊处理，如果最后一行的第j列为障碍物，则`dp[n-1][0..j] = 0`，

   如果最后一列的第i行为障碍物，则`dp[0..i][m-1] = 0`

