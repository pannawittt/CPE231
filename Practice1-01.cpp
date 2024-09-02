#include <iostream>
#include <vector>

using namespace std;

void findCombinations(int start, int currentSum, int target, int MaxNum, vector<int>& current, vector<vector<int>>& result) {
    if (currentSum == target) {
        result.push_back(current);
        return;
    }
    if (start > MaxNum || currentSum > target) {
        return;
    }

    findCombinations(start+1, currentSum, target, MaxNum, current, result);

    current.push_back(start);
    findCombinations(start+1, currentSum + start, target, MaxNum, current, result);
    current.pop_back();

}

int main() {

    int x, y;
    cin >> x;
    cin >> y;


    vector<int> current;
    vector<vector<int>> combinations;
    findCombinations(1, 0, y, x, current, combinations);
    
    int count_odd = 0;
    int count_even = 0;
    for (const auto& combination : combinations) {
        for (int n : combination) {
            if (n%2 == 0) {
            count_even++;
            } 
            else {
                count_odd++;
            }
        }
    }
    
    cout << count_odd << endl;
    cout << count_even;

    return 0;
}