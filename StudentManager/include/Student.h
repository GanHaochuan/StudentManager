#pragma once
#include <iostream>
#include <string>   
#include <valarray>

/**
 * @class Student
 * @brief 学生类，用于管理学生信息和成绩
 * 
 * 该类封装了学生的基本信息（姓名）和多门课程的成绩。
 * 提供了成绩计算、输入输出、数据访问等完整功能。
 * 使用 std::valarray 存储成绩。
 */
class Student
{
private:
    // 使用 valarray<double> 类型别名表示成绩数组
    typedef std::valarray<double> ArrayDb;
    std::string name; // 学生姓名
    ArrayDb scores; // 成绩数组
    // 辅助函数，用于以格式化方式输出学生成绩
    std::ostream& arr_out(std::ostream& os) const;
public:
    // 默认构造函数，初始化姓名为 "Null Student"，成绩为空
    Student() : name("Null Student"), scores() {}

    // 使用给定的姓名初始化，成绩为空
    explicit Student(const std::string& s)
        : name(s), scores() {
    }

    // 使用指定数量的成绩（初始为0）初始化，姓名为 "Nully"
    explicit Student(int n) : name("Nully"), scores(n) {}

    // 使用姓名和指定数量的成绩初始化
    Student(const std::string& s, int n)
        : name(s), scores(n) {
    }

    // 使用姓名和已有的成绩数组初始化
    Student(const std::string& s, const ArrayDb& a)
        : name(s), scores(a) {
    }

    // 使用姓名和成绩数组（指针和数量）初始化
    Student(const char* str, const double* pd, int n)
        : name(str), scores(pd, n) {
    }

    ~Student() {}

    // 计算学生成绩的平均值
    double Average() const;

    // 获取学生姓名
    const std::string& Name() const;

    // 重载非const下标运算符，用于修改学生的成绩
    double& operator[](int i);

    // 重载const下标运算符，用于访问学生的成绩
    double operator[](int i) const;

    // 输入运算符重载：从输入流中读取学生信息
    friend std::istream& operator>>(std::istream& is,
        Student& stu); 

    // 自定义的输入运算符重载：根据需要读取学生信息
    friend std::istream& readline(std::istream& is,
        Student& stu);   

    // 输出运算符重载：将学生信息输出到输出流
    friend std::ostream& operator<<(std::ostream& os,
        const Student& stu);
};