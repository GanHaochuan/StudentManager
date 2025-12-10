#include <iostream>
#include "Student.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n)
{
    cout << "Please enter the student's name: ";
    readline(cin, sa);
    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];
    while (cin.get() != '\n')
        continue;
}