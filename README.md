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

```
StudentManager/
│  CMakeLists.txt
│  StudentManager.vcxproj
│  StudentManager.vcxproj.filters
│  StudentManager.vcxproj.user
│
├─build
├─include
│      Student.h
│
└─src
    │  main.cpp
    │  Student.cpp
    │  use.cpp
    │
    └─build
        └─Debug
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

# 4. 编译项目
make

# 5. 运行程序
Debug./app

### 运行示例

```
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
  - 使用`std::valarray<double>`存储成绩，提供高效的数值计算
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

    add：添加了一些注释
    upload：尝试上传项目到Github
    add：安装CMake Tools，重新运行程序
    fix：在终端运行程序并修改CMakeLists.txt
    move: 添加文件夹scr与include，移动build文件夹
    add: CMakeLists.txt
    add: main.cpp
    add: use.cpp
    add: Student.cpp
    add: 添加项目文件
    add: .gitattributes、.gitignore 和 README.md



## 注意事项

1. 输入成绩时使用空格分隔
2. 程序会自动处理换行符，确保输入流正确
3. 成绩数量在编译时通过常量配置，可根据需要修改

## 未来扩展方向

1. 添加文件持久化功能（从文件读写学生数据）
2. 实现成绩排序和统计功能
3. 添加异常处理机制
4. 支持动态调整学生和科目数量
5. 添加图形用户界面

