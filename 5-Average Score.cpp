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
 * Fix this code bugs to make it work properly. // DONE
 * */

int main() {
    int students;
    cin >> students;
    while (students--) {
        int courses, total = 0, grade;
        cin >> courses;
        for (int i = 0; i < courses; i++) {
            cin >> grade;
            total += grade;
        }
        cout << "The Average is " << float(total) / float(courses) << '\n';
    }
    return 0;
}


