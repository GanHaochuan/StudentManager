#include "Student.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

// 计算学生成绩的平均值
// 如果学生有成绩记录（scores.size() > 0），则返回成绩的平均值；
// 否则返回0，避免除零错误。
double Student::Average() const
{
    if (scores.size() > 0)
        return scores.sum() / scores.size();
    else
        return 0;
}

// 获取学生的姓名
const string& Student::Name() const
{
    return name;
}

// 非const版本的下标运算符重载，用于修改学生的成绩
// 通过此运算符，用户可以直接修改学生指定索引位置的成绩
double& Student::operator[](int i)
{
    return scores[i];
}

// const版本的下标运算符重载，用于访问学生的成绩
// 该版本用于读取成绩，不能通过此方法修改成绩
double Student::operator[](int i) const
{
    return scores[i];
}

// 辅助函数，用于格式化输出学生的成绩
// 将学生的成绩输出到输出流中，每行最多输出5个成绩，超过5个换行
ostream& Student::arr_out(ostream& os) const
{
    int i;
    int lim = scores.size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << scores[i] << " ";
            if (i % 5 == 4) // 每输出5个成绩，换行
                os << endl;
        }
        if (i % 5 != 0) // 如果最后一行没有满5个成绩，换行
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}

// 输入运算符重载，用于从输入流中读取学生姓名
// 此方法用于标准输入或文件输入学生的姓名
istream& operator>>(istream& is, Student& stu)
{
    is >> stu.name;
    return is;
}

// 自定义的输入函数，用于读取学生的姓名（可以处理多行输入）
// 使用getline从输入流中读取整行内容作为学生姓名
istream& readline(istream& is, Student& stu)
{
    getline(is, stu.name);
    return is;
}

// 输出运算符重载，用于将学生信息输出到输出流
// 输出学生的姓名和成绩（通过arr_out()格式化输出成绩）
ostream& operator<<(ostream& os, const Student& stu)
{
    os << "Scores for " << stu.name << ":\n";
    stu.arr_out(os); 
    return os;
}
