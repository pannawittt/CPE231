#include <iostream>
#include <vector>

using namespace std;

void selection_sort_stable(vector<pair<int, int>>& students) {
    int n = students.size();

    for (int i = 0; i < n - 1; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (students[j].second > students[max_idx].second ||
                (students[j].second == students[max_idx].second && students[j].first < students[max_idx].first)) {
                max_idx = j;
            }
        }

        if (max_idx != i) {
            // Swap elements while maintaining stability
            auto temp = students[i];
            students[i] = students[max_idx];
            students[max_idx] = temp;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].first >> students[i].second;
    }

    selection_sort_stable(students);

    for (const auto& student : students) {
        cout << student.first << endl;
    }

    return 0;
}