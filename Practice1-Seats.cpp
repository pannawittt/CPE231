#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(pair<int, int> *a, pair<int, int> *b) {
    pair<int, int> temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(vector<pair<int, int>>& students, int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if ((students[i].second > students[min_idx].second) || 
            (students[i].second == students[min_idx].second && students[i].first < students[min_idx].first)) {
                min_idx = i;
            }
        }
        swap(&students[min_idx], &students[step]);
    }
}

void printStudentID(const vector<pair<int, int>>& students) {
    for (const auto& student : students) {
        cout << student.first << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> students;

    int student_id, student_score;
    for (int i = 0; i < n; i++) {
        cin >> student_id >> student_score;
        students.push_back(make_pair(student_id, student_score));
    }

    SelectionSort(students, n);
    printStudentID(students);

    return 0;
}
