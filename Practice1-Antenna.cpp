#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

struct Tower {
    int height;
    int baseHeight;
};

float calculateP(const Tower& t1, const Tower& t2){
    return abs(t1.height - t2.height) / (double)(abs(t1.height) + abs(t2.height)) + abs(t1.baseHeight - t2.baseHeight) / (double)(abs(t1.baseHeight) + abs(t2.baseHeight));
}

int main(){
    int n;
    cin >> n;

    vector<Tower> towers(n);

    for (int i=0; i<n; i++){
        cin >> towers[i].height >> towers[i].baseHeight;
    }

    vector<double> avgEfficiency(n, 0.0);

    for (int x=0; x<n; ++x){
        double totalP = 0.0;
        for (int y=0; y<n; ++y){
            if (x != y) {
                totalP += calculateP(towers[x], towers[y]);
            }
        }
        avgEfficiency[x] = totalP/(n-1);
    }

    int bestTowerIndex = 0;
    double minAvgP = numeric_limits<double>::max();
    for (int i = 0; i < n; ++i) {
        if (avgEfficiency[i] < minAvgP) {
            minAvgP = avgEfficiency[i];
            bestTowerIndex = i;
        }
    }

    cout << towers[bestTowerIndex].height << " " << towers[bestTowerIndex].baseHeight;

    return 0;
}