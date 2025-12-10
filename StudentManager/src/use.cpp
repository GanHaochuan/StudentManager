#include <iostream>
#include "Student.h"
using std::cin;
using std::cout;
using std::endl;

// 设置学生信息，包括姓名和成绩
// 该函数会提示用户输入学生的姓名以及指定数量的成绩
void set(Student& sa, int n)
{
    cout << "Please enter the student's name: ";
    readline(cin, sa);
    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];
    // 清除输入缓冲区中的剩余字符，直到遇到换行符
    while (cin.get() != '\n')
        continue;
}