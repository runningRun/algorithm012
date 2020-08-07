// 递归
void recursion(int level, int max, int param) { 
  // 终止条件
  if (level > max) { 
    // 处理当前结果 
    return ; 
  }

  // 当前层处理
  process(level, param);

  // 进入下一层 
  recursion(level + 1, max, param);

  // 清理当前层
}