#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    string name;
    cin >> name;
    int length = name.size();
    set<string> palindromes;

    for (int i = 1; i < (1 << length); i++) {
        string substring = "";
        for (int j = 0; j < length; j++) {
            if (i & (1 << j)) {
                substring += name[j];
            }
        }

        string reversed = substring;
        reverse(reversed.begin(), reversed.end());
        if (reversed == substring && substring.length() > 1) { // check palindrome
            palindromes.insert(substring);
        }
    }

    cout << palindromes.size();
}