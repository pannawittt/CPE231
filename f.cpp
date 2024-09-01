#include <iostream>
#include <vector>

using namespace std;

// int fill_maker_maker(l, m, r) {
    
// }    

int main() {

    int l, m, r;
    cin >> l >> m >> r;

    vector<int> fill_maker;
    int left = l;
    fill_maker.push_back(left);
    if (m-l>1){
        for (int i=1; i<=(m-l); i++) {
            left = l+i;
            fill_maker.push_back(left);
        }
    }

    if (m-l == 1 && m-r == 1) {
        fill_maker.push_back(m);
    }

    int right = r;
    if (m-r>1) {
        for (int j=m-1; j>r; j--) {
            right = j;
            fill_maker.push_back(right);
        }
    }
    fill_maker.push_back(r);
    
    for (int x: fill_maker) {
        cout << x << " ";
    }

    cout << endl << fill_maker.size();

    return 0;
}