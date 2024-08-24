#include <bits/stdc++.h>

using namespace std;

int main(){
    string name;
    cin >> name;
    int stringLength = name.size();
    set<string> palindromic;

    for(long long i = 0; i < (1LL << stringLength); i++){
        string substring = "";
        for(int j = 0; j < stringLength; j++){
            if(i & (1LL << j)){
                substring += name[j];
            }
        }

        if(substring.length() > 1){
            string reversed = substring;
            reverse(reversed.begin(), reversed.end());
            if(reversed == substring){
                palindromic.insert(substring);
            }
        }
    }

    cout << palindromic.size();
}