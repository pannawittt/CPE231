#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    string text;
    char first, last;
    int p;

    cin >> text;
    cin >> first >> last;
    cin >> p; // the minimun length


    int len = text.size();
    vector<char> text_vec;
    for (int i=0; i<len; i++) {
        text_vec.push_back(text[i]);
    }

    int count=0;
    for (int j=0; j<=len; j++) {
        if (text_vec[j] == first) {
            for (int m=j; m<=len; m++) {
                if (text_vec[m] == last) {
                    if (m-j+1 >= p){
                    count++;
                    }
                }
            }
        }
    }

    cout << count;

    return 0;
}