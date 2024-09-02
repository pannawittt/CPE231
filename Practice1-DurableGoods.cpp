#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float maxSum = 0;
    
void findMaxSum(const vector<vector<float>>& matrix, int col, float currentSum, vector<bool>& usedRows) {
    int matrix_size = matrix.size();
    if (col == matrix_size) {
        maxSum = max(maxSum, currentSum);
        return;
    }

    for (int row=0; row<matrix_size; ++row) {
        if (!usedRows[row]) {
            usedRows[row] = true;
            findMaxSum(matrix, col+1, currentSum+matrix[row][col], usedRows);
            usedRows[row] = false;
            }
        }
    }

int main() {

    int n;
    cin >> n;

    vector<vector<float>> matrix;
    for (int i=0; i<n; i++) {
        vector<float> goods;
        for (int j=0; j<n; j++) {
            float goods_n;
            cin >> goods_n;
            goods.push_back(goods_n);
        }
        matrix.push_back(goods);
    }

    // for (const auto& row : matrix) {
    //     for (float y : row) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    vector<bool> usedRows(n, false);
    
    findMaxSum(matrix, 0, 0, usedRows);

    cout << maxSum;



    return 0;
}