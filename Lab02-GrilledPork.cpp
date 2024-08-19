#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int findX(int n,int p){
    int x;
    x = floor(n/p);
    return x;
}

int findGreatestMissingNumber(const vector<int>& vec) {
    int max_num = vec.empty() ? -1 : vec.front(); 
    int missing_num = -1;

    for (int i = max_num; i >= 0; --i) {
        if (find(vec.begin(), vec.end(), i) == vec.end()) {
            missing_num = i;
            break;
        }
    }
    return missing_num;
}

int main() {

    int pn, n, a, b, c, d, sum;

    vector<int> p;
    for (int i = 0; i < 4; i++) {
        cin >> pn;
        p.push_back(pn);
    }

    cin >> n;

    // for (int x : p) {
    //     cout << x << " ";
    // }

    vector<int> possibles;

    a = findX(n, p[0]);
    b = findX(n, p[1]);
    c = findX(n, p[2]);
    d = findX(n, p[3]);

    for (int i = 0; i<= a; i++) {
        for (int j = 0; j<= b; j++) {
            for (int k = 0; k<= c; k++) {
                for (int l = 0; l<= d; l++) {
                    sum = (i*p[0])+(j*p[1])+(k*p[2])+(l*p[3]);
                    if (sum <= n) {
                        possibles.push_back(sum);
                    }
                }
            }
        }
    }

    sort(possibles.begin(), possibles.end(), greater<int>());

    int x = findGreatestMissingNumber(possibles);
    cout << x;

    // for (int x : possibles) {
    //     cout << x << " ";
    // }

    return 0;
}