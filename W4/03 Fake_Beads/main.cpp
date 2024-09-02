#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int totalBeads;
    int total_diff = numeric_limits<int>::max();
    int diff = 0;
    int len;
    cin >> totalBeads;
    vector<int> beads(totalBeads);
    vector<int> result(totalBeads);
    for (int i = 0; i < totalBeads; i++) {
        cin >> beads[i];
    }
    for (int i = 0; i < totalBeads - 1; i++) {
        diff = beads[i + 1] - beads[i];
        if(diff < total_diff) {
            total_diff = diff;
        }
    }
    result[0] = beads[0];
    for (int i = 1; i <= totalBeads; i++) {
        result[i] = result[i - 1] + total_diff;
        len =  beads[i - 1] - result[i - 1];
        cout << len << " ";
    }
    cout << endl;
    return 0;
}