//Zero Remainder Array
//https://codeforces.com/problemset/problem/1374/D

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  /*
  string sample_input = R"(5
4 3
1 2 1 3
10 6
8 7 1 8 3 7 5 10 8 9
5 10
20 100 50 20 100500
10 25
24 24 24 24 24 24 24 24 24 24
8 8
1 2 3 4 5 6 7 8
)";
  istringstream iss(sample_input);
  auto* old_cin_buf = cin.rdbuf(iss.rdbuf());
  //*/
 
  int t;
  cin >> t;

  while (t--) {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    map<ll, ll> moves;
    for (ll i = 0; i < n; i++) {
      cin >> a[i];

      if (a[i] % k == 0) {
        continue;
      }

      moves[k-(a[i]%k)]++;
    }

    ll max_moves = 0;

    for (auto &[rem, freq] : moves) {
      max_moves = max(max_moves, (freq - 1) * k + rem + 1);
    }

    cout << max_moves << "\n";
  }
} 




