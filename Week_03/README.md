学习笔记

树的面试题解法一般都是递归。
1、节点的定义
2、重复性（自相似性）

递归就是循环，通过函数体来进行的循环。

递归代码模板:
```
def recursion（level，param1,param2,...):
  # recursion terminator   递归终结条件
  if level > MAX_LEVEL:
    process_result
    return
  
  # process logic in current level  处理当前层逻辑
  process(level, data ...)

  # drill down    下探到下一层
  self.recursion(level + 1, p1, ...)

  # reserse the current level status if needed 清理当前层
```$$

思维要点
  1、不要人肉进行递归 (最大误区)
  2、找到最近最简方法，将其拆解成可重复解决的问题（重复子问题）
  3、数学归纳法思维

分治
  就是一个递归
  找重复性及分解问题，和组合每个子问题的结果

回溯
  不断试错
  平行+嵌套  分别对应循环+递归

  回溯模板:
```
  void backtracking(参数) {
    if (终止条件) {
      存放结果
      return;
    }

    for (选择: 本层集合中元素(树中节点孩子的数量就是集合的大小)) {
      处理节点;
      backtracking(路径，选择列表); // 递归
      回溯，撤销处理结果
    }
  }
```