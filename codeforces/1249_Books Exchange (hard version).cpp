//Books Exchange (hard version)
//https://codeforces.com/problemset/problem/1249/B2

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  /*
  string sample_input = R"(6
5
1 2 3 4 5
3
2 3 1
6
4 6 2 1 5 3
1
1
4
3 4 1 2
5
5 1 2 4 3
 
)";
  istringstream iss(sample_input);
  auto* old_cin_buf = cin.rdbuf(iss.rdbuf());
  */
 
  int q;
  cin >> q;
 
  while (q--) {
    int n;
    cin >> n; 
 
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i]--;
    }
 
    vector<int> ans(n, 0);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        vector<int> cycle;
        int current = i;
 
        while (!visited[current]) {
          visited[current] = true;
          cycle.push_back(current);
          current = p[current];
        }
 
        int length = cycle.size();
 
        for (int v : cycle) {
          ans[v] = length;
        }
      }
    }
 
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
} 
