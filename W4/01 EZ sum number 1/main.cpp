#include <iostream>
#include <vector>

using namespace std;

vector<int> arth(int number){
    vector<int> set;
    for (int i=1;i<=number;i++){
        set.push_back(i);
    }
    return set;
}

void EzSum_BackTracking(int n,int want_n,int current,int sum,vector<int>& current_comb,pair<int,int>& O_E){ //Back Tracking
    if (sum == want_n){

        for (auto i : current_comb){

            if (i%2 !=0){

                O_E.first += 1;
            }else{

                O_E.second += 1;
            }
        }
        return;
    }

    if (sum > want_n)
        return;

    for (int i = current; i <= n; i++){

        current_comb.push_back(i);

        EzSum_BackTracking(n, want_n, i + 1, sum + i, current_comb, O_E);

        current_comb.pop_back();
    }
}


int main(){
    int n,want_n;
    cin >> n >> want_n;
    vector<int> CurrentComb;
    pair<int,int> O_E = {0,0};
    EzSum_BackTracking(n, want_n, 1, 0, CurrentComb, O_E);
    cout << O_E.first << endl << O_E.second << endl;
    
    return 0;
}
