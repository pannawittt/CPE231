#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string beads;
  char A, B;
  int p;
  cin >> beads;
  cin >> A >> B;
  cin >> p;

  vector<char> beads_vec;
  for (int i = 0; i < beads.size(); i++) {
    beads_vec.push_back(beads[i]);
  }

  int n = beads.size();
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (beads[i] == A) {
      for (int j = i; j < n; j++) {
        if (beads[j] == B) {
          if (j - i + 1 >= p) {
            count++;
          }
        }
      }
    }
  }

  cout << count << endl;

  return 0;
}