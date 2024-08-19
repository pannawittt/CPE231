#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, p, t;
    cin >> n;

    vector<int> Pn;
    for (int i=0; i<n; i++) {
        cin >> p;
        Pn.push_back(p);
    }

    // for (int x:Pn) {
    //     cout << x << " ";
    // }

    vector<int> Tn;
    for (int j=0; j<n; j++) {
        cin >> t;
        Tn.push_back(t);
    }

    sort(Pn.begin(), Pn.end());
    sort(Tn.begin(), Tn.end(), greater<int>());

    // cout << "Pn" << endl;
    // for (int x:Pn) {
    //         cout << x << " ";
    //     }

    // cout << endl << "Tn" << endl;
    // for (int x:Tn) {
    //         cout << x << " ";
    //     }

    vector<int> pt(n);
    for (int k=0; k<n; k++) {
        pt[k] = Pn[k] + Tn[k];
    }

    // cout << endl << "pt" << endl;
    // for (int x:pt) {
    //         cout << x << " ";
    //     }

    sort(pt.begin(), pt.end());

    int result = 0;
    for (int l=0; l<n-1; l++) {
        result += pt[l+1] - pt[l];
    }

    cout << result;
}