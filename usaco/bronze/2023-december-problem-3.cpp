//Cowntact Tracing 2
//https://usaco.org/index.php?page=viewproblem2&cpid=1348
#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
  cin >> n;
  string cows;
  cin >> cows;

  // count the number of regions containing continuous ones
  // 1110011011111 gives 325
  vector<int> regions;
  bool s_edge = false; // whether there's a region at the starting edge
  bool e_edge = false; // whether there's a region at the ending edge
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (cows[i] == '1') {
      count++;
      if (i == 0) {
        s_edge = true;
      } else if (i == n - 1) {
        e_edge = true;
      }
    } else {
      if (count > 0) {
        regions.push_back(count);
        count = 0;
      }
    }
  }
  if (count > 0) {
    regions.push_back(count);
    count = 0;
  }
  //for (int i = 0; i < regions.size(); i++) { cout << regions[i]; }

  // compute the max window size a cow can cover for each region
  // then use the smallest window size
  int min_window_size = 300000;
  for (int i = 0; i < regions.size(); i++) {
    int window_size;
    if ((i == 0 && s_edge) || (i == regions.size() - 1 && e_edge)) {
      window_size = 2 * regions[i] - 1;
    } else if (regions[i]%2 == 0) {
      window_size = regions[i] - 1;
    } else {
      window_size = regions[i];
    }
    min_window_size = min(min_window_size, window_size);
  }

  //
  int number_of_cows = 0;
  for (int i = 0; i < regions.size(); i++) {
    number_of_cows += (regions[i] + min_window_size - 1) / min_window_size;
  }
  cout << number_of_cows << endl;
}
