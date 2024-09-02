#include <iostream>
#include <vector>

using namespace std;

int main() {

    int landlength;
    cin >> landlength;

    vector<int> landheight;
    int landheight_n;
    for (int i=0; i<landlength; i++) {
        cin >> landheight_n;
        landheight.push_back(landheight_n);
    }

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
    
    int fill_size = fill_maker.size();
    vector<int> total_height(landlength, 0);
    for (int w=0; w<landlength; w++){
        for (int l=0; l<fill_size; l++) {
            total_height[w] += fill_maker[l] + landheight[l+w];
        }
    }


    for (int u : total_height) {
        cout << u << " ";
    }

    // int rough = 0;
    // for (int k=1; k<=landlength-1; k++) { // for rough calculating
    //     rough += total_height[k];
    // }

    // cout << rough;
    // for (int x:landheight) {
    //     cout << x << " " ;
    // }
    
    // cout << endl;

    // for (int w: fill_maker) {
    //     cout << w << " ";
    // }
    


    return 0;
}