#include <bits/stdc++.h>
using namespace std;
/*
 * This code is designed to print the average score for students grades
 * As if the input is
 * 1
 * 5
 * 89
 * 93
 * 75
 * 66
 * 79
 * The output should be 80.4
 * Fix this code bugs to make it work properly.
 * */
int main() {
    int students;
    while (--students) {
        int courses, total, grade;
        cin >> courses;
        for (int i = 0; i <= courses; ++i) {
            cin >> grade;
            total += grade;
        }
        cout << "The Average is" << total / courses << '\n';
    }
    return 0;
}


