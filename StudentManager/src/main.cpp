#include <iostream>
#include "Student.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n);

const int pupils = 3; // 学生人数
const int quizzes = 5; // 每个学生的测验次数

int main()
{
    // 创建一个Student对象数组，包含3个学生，每个学生有5个测验成绩
    Student ada[pupils] =
    { Student(quizzes), Student(quizzes), Student(quizzes) };

    // 循环为每个学生设置姓名和成绩
    int i;
    for (i = 0; i < pupils; ++i)
        set(ada[i], quizzes);

    // 输出学生列表
    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;

    // 输出学生成绩和平均成绩
    cout << "\nResults:";
    for (i = 0; i < pupils; ++i)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";

    return 0;
}