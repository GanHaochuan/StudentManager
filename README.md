# StudentManager

## 项目简介

本项目是一个基于C++面向对象编程的学生成绩管理系统，能够管理多名学生的成绩信息，计算平均分，并展示详细的成绩报告。采用模块化结构，使用CMake进行构建，符合现代C++项目标准。

## 主要功能

1. **学生信息管理**
   - 记录学生姓名和成绩
   - 支持多种构造函数初始化方式

2. **成绩操作**
   - 计算学生平均成绩
   - 支持批量成绩输入

3. **数据展示**
   - 格式化输出学生成绩信息
   - 自动分页显示成绩列表（每5个成绩一行）

## 项目目录结构

```text
StudentManager/
│  CMakeLists.txt
│  StudentManager.vcxproj
│  StudentManager.vcxproj.filters
│  StudentManager.vcxproj.user
│
├─build/
├─include/
│      Student.h
│
└─src/
    │  main.cpp
    │  Student.cpp
    │  use.cpp
    │
    └─build/
        └─Debug/
```

## 构建与运行方式

### 环境要求
- C++17 或更高版本编译器
- CMake 3.10 或更高版本

### 构建步骤

```bash
# 1. 克隆项目（如果从GitHub下载）
git clone https://github.com/GanHaochuan/StudentManager.git
cd StudentManager

# 2. 创建构建目录
mkdir build
cd build

# 3. 使用CMake生成构建文件
cmake ..

# 4. 编译项目 (Linux/Mac 使用 make, Windows 使用 MSBuild 或打开解决方案)
make

# 5. 运行程序
Debug./app
```

### 运行示例

```text
Please enter the student's name: Mike
Please enter 5 quiz scores:
100
89
991
95
96
Please enter the student's name: Amy
Please enter 5 quiz scores:
80
81
86
78
69
Please enter the student's name: Jake
Please enter 5 quiz scores:
66
59
61
60
70

Student List:
Mike
Amy
Jake

Results:
Scores for Mike:
100 89 991 95 96
average: 274.2

Scores for Amy:
80 81 86 78 69
average: 78.8

Scores for Jake:
66 59 61 60 70
average: 63.2
Done.
```

## 模块设计说明

### 1. Student类（核心模块）
- **位置**: `include/Student.h`, `src/Student.cpp`
- **职责**: 封装学生基本信息和成绩操作
- **设计特点**:
  - 使用 `std::valarray<double>` 存储成绩，提供高效的数值计算
  - 实现运算符重载（`operator[]`）方便成绩访问
  - 提供多种构造函数以适应不同的初始化场景
  - 使用友元函数处理输入输出，保持封装性

### 2. 主程序模块
- **位置**: `src/main.cpp`
- **职责**: 程序入口和流程控制
- **设计特点**:
  - 清晰的主程序逻辑
  - 使用常量配置学生和科目数量
  - 调用辅助函数完成用户交互

### 3. 辅助功能模块
- **位置**: `src/use.cpp`
- **职责**: 提供用户输入支持
- **设计特点**:
  - 独立的输入处理函数

## 面向对象设计特点

### 封装性
- 私有成员变量保护数据完整性
- 公有接口提供安全的操作方式

### 运算符重载
- 下标运算符重载实现直观的成绩访问
- 流运算符重载支持标准输入输出

### 友元函数
- 使用友元函数处理特定输入输出需求
- 在保持封装性的同时提供灵活接口

## 开发记录

本项目遵循良好的Git实践，具有清晰的提交历史：

- `add`: 添加了一些注释
- `upload`: 尝试上传项目到Github
- `add`: 安装CMake Tools，重新运行程序
- `fix`: 在终端运行程序并修改CMakeLists.txt
- `move`: 添加文件夹scr与include，移动build文件夹
- `add`: CMakeLists.txt
- `add`: main.cpp
- `add`: use.cpp
- `add`: Student.cpp
- `add`: 添加项目文件
- `add`: .gitattributes、.gitignore 和 README.md

## 注意事项

1. 输入成绩时使用空格分隔或回车分隔均可。
2. 程序会自动处理换行符，确保输入流正确。
3. 成绩数量在编译时通过常量配置，可根据需要修改源码。

## 未来扩展方向

1. 添加文件持久化功能（从文件读写学生数据）
2. 实现成绩排序和统计功能
3. 添加异常处理机制
4. 支持动态调整学生和科目数量
5. 添加图形用户界面


# 附：std::valarray 类简介

`std::valarray` 是 C++ 标准库中的一个模板类，专门用于**数值计算**。它的设计目标是提供高效的数值数组操作，类似于数学中的向量运算。

## 主要特点

### 1. **数值优化**
- 专门为数值计算优化
- 支持向量化操作
- 适合科学计算和数学运算

### 2. **运算符重载**
支持对整个数组进行数学运算：

```cpp
std::valarray<double> a = {1.0, 2.0, 3.0};
std::valarray<double> b = {4.0, 5.0, 6.0};

// 逐元素运算
auto c = a + b;     // {5.0, 7.0, 9.0}
auto d = a * 2.0;   // {2.0, 4.0, 6.0}
auto e = sin(a);    // 对每个元素求正弦
```

### 3. **成员函数**

#### 常用构造函数：
```cpp
std::valarray<int> v1;           // 空数组
std::valarray<int> v2(10);       // 10个元素，值初始化为0
std::valarray<int> v3(5, 10);    // 10个元素，每个都是5
std::valarray<int> v4 = {1,2,3}; // 初始化列表
std::valarray<int> v5(v4);       // 拷贝构造
```

#### 常用成员函数：
```cpp
v.size()      // 返回元素个数
v.sum()       // 求和（在你的项目中用于计算总分）
v.min()       // 返回最小值
v.max()       // 返回最大值
v.resize(n)   // 调整大小
v.shift(n)    // 移位
v.cshift(n)   // 循环移位
v.apply(func) // 对每个元素应用函数
```

## 在项目中的应用

### 1. **存储成绩数组**
```cpp
// Student.h 中的定义
typedef std::valarray<double> ArrayDb;
ArrayDb scores;  // 用于存储学生成绩
```

### 2. **计算总分**
```cpp
// Student.cpp 中的 Average() 函数
double Student::Average() const {
    if (scores.size() > 0)
        return scores.sum() / scores.size();  // 使用 sum() 计算总分
    else
        return 0;
}
```

### 3. **支持下标访问**
```cpp
// 通过重载 operator[] 提供访问
double& Student::operator[](int i) {
    return scores[i];  // 直接使用 valarray 的下标操作
}
```

## 与 std::vector 的比较

| 特性 | std::valarray | std::vector |
|------|---------------|-------------|
| **设计目的** | 数值计算 | 通用动态数组 |
| **运算符重载** | 丰富（+,-,*,/,等） | 只有比较运算符 |
| **数学函数** | 内置（sin, cos, sqrt等） | 无，需要算法库 |
| **内存管理** | 连续存储，可重新分配 | 连续存储，动态增长 |
| **性能** | 数值计算优化 | 通用目的 |
| **适用场景** | 科学计算、数学运算 | 通用数据存储 |

