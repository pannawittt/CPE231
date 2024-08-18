#include <iostream>
#include <vector>

using namespace std;

int Factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * Factorial(n - 1);
}

int main() {
    int n, nn, sp, p, v;
    int result1 = 1, result2 = 1;

    cin >> n;
    cin >> v;
    
    vector<int> S;
    for (int i = 0; i < n; i++) {
        cin >> nn;
        S.push_back(nn);
    }

    // for (int x : S) {
    //     cout << x << " ";
    // }
    
    cin >> p;

    vector<int> Sp;
    for (int i = 0; i < p; i++) {
        cin >> sp;
        Sp.push_back(sp);
    }

    while (p != 0) {
        int ways1 = n - 1;
        n--;
        p--;
        if (0 <= p) {
            result1 = result1 * ways1;
        }
    }

    if (n != 0) {
        result2 = Factorial(n);
    }

    int finalResult = result1 * result2;

    cout << finalResult;


    return 0;
}