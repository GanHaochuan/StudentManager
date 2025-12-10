# 额外项目： CS106B Assignments 1–7 Summary

---

#  Overview

本仓库包含我在 **CS106B** 课程中完成的 **七个编程作业**。
这些作业覆盖了递归、数据结构、图算法、堆、哈希表等核心主题。
本 README 文档总结了每个作业的主要内容、我完成的工作，以及从中学习到的关键概念和 C++ 技巧。
本项目需要使用 Qt Creator 18.0.0 (Community) 运行 Qt Project file
---

#  Assignment 1 — Recursion Warm-Up

### ✔ **Tasks**

* 修复无限递归导致的 Stack Overflow
* 实现 OnlyConnect（字符串过滤）
* PlayingFair（生成递归组合）
* Sandpile（网格递归处理）
* Plotter（递归绘图）

### ✔ **Completed**

* 正确实现所有递归函数
* 通过调试修复递归爆栈问题
* 添加注释、测试并理解递归基本结构

### ✔ **Learned**

* 递归三要素（base case / recursive case / progress）
* 自然语言处理（字符串递归）
* 图形递归（Sierpinski-like 概念）

---

#  Assignment 2 — Big-O Analysis

### ✔ **Tasks**

* 分析给定程序的时间复杂度
* 理解嵌套循环、递归复杂度

### ✔ **Completed**

* 写出多段算法的 Big-O 推导
* 给 C++ 程序添加“时间复杂度注释”
* 整理成实验报告文档

### ✔ **Learned**

* 如何从代码推导时间复杂度
* O(1)/O(n)/O(n log n)/O(n³) 的判断方法
* 使用图算法分析复杂度

---

#  Assignment 3 — Recursion!

### ✔ **Tasks**

* **Sierpinski Triangle**：实现分治递归绘图
* **Human Pyramids**：递归背部重量 + Memoization
* **What Are YOU Doing?**：生成大小写组合（2ⁿ recursion tree）
* **Shift Scheduling**：递归搜索不重叠班表的最大价值

### ✔ **Completed**

* 理解四大递归结构
* 写出了部分实现与伪代码
* 调试 memoization、回溯、递归性能优化

### ✔ **Learned**

* 分治算法设计
* 递归 + 缓存技术（memoization）
* 字符串 token + 递归组合法
* 回溯算法（Shift Scheduling）

---

#  Assignment 4 — Stack / Queue / Linked List

### ✔ **Tasks**

* 实现自定义 Stack、Queue、LinkedList
* 手动管理内存（new/delete）
* 通过完整测试集

### ✔ **Completed**

* 你实现了链表节点、入栈、出栈、出队、删除等操作
* 修复了指针错误与段错误（segmentation fault）

### ✔ **Learned**

* 指针与引用
* 节点链结构（单链表）
* O(1) 的 push/pop queue 结构

---

#  Assignment 5 — Graph Matching

### ✔ **Tasks**

* 使用 DFS+回溯检查 perfect matching
* 处理 Map<string, Set<string>> 图结构
* 管理 matched pairs 与 used sets

### ✔ **Completed**

* 完整实现 hasPerfectMatching 函数
* 修复 remove() 回溯顺序 bug

### ✔ **Learned**

* 图遍历（DFS）
* 回溯算法设计
* 图匹配问题的状态管理
* Map / Set 模板类型使用
* Pair 数据结构应用

---

#  Assignment 6 — Binary Heap Priority Queue

### ✔ **Tasks**

* 完全实现一个二叉堆优先队列
* push/pop/peek
* 上浮（bubbleUp）/下沉（bubbleDown）

### ✔ **Completed**

* 修复 PQEntry 错误
* 实现动态数组存储堆元素
* 正确处理插入与删除

### ✔ **Learned**

* 二叉堆结构
* 完整的优先队列数据结构设计
* O(log n) 插入与删除

---

#  Assignment 7 — Linear Probing & Robin Hood Hashing（未完成）

### ✔ **Tasks**

* 实现：
  ✔ Linear Probing Hash Table
  ✔ Robin Hood Hash Table
* 支持 contains / insert / remove
* 处理 tombstone

### ✔ **Completed**

* 正确实现 Robin Hood 插入与探测距离更新
* 实现线性探测记号（EMPTY/TOMBSTONE/FILLED）
* 修复 constructor/destructor 逻辑

### ✔ **Learned**

* 开放地址哈希（Open Addressing）
* 线性探测（Linear Probing）
* Robin Hood Hashing （平衡探测距离）
* Tombstone 删除策略
* 析构函数设计与数组内存管理

---

#  Summary — What I Learned Across All Assignments

###  **C++ 技能**

* 指针、引用、动态内存
* 类设计、.h/.cpp 文件组织
* 自定义数据结构（List / Heap / Hash table）
* 模板与 STL（Map / Set / Vector）
* 调试技巧（断点、打印、中间状态）
* 代码规范与大型工程的文件管理

###  **算法能力**

* 递归（从基础到高阶）
* 回溯（matching / scheduling）
* 动态规划与 memoization
* 分治（Sierpinski）
* 图搜索（DFS）
* 二叉堆（优先队列）
* 哈希表（Linear Probing / Robin Hood）
