//Hoof Paper Scissors Minus One 
//https://usaco.org/index.php?page=viewproblem2&cpid=1515

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, m;
  cin >> n >> m;
  bitset<3000> bs[n]; 
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j <= i; j++) {
      char s;
      cin >> s;
      if (s == 'W') {
        bs[j].set(i);
      } else if (s == 'L') {
        bs[i].set(j);
      }
    }
  }
  while (m--) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    bitset<3000> r = bs[x] & bs[y];
    ll count = r.count();
    cout << (2*n*count-count*count) << "\n";
  }
  /*
  vector<vector<bool>> symbols(n, vector<bool> (n, false));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j <= i; j++) {
      char s;
      cin >> s;
      //cout << "s >> " << s << "\n";
      if (s == 'L') {
        symbols[i][j] = true;
      } else {
        symbols[i][j] = false;
      }
      if (i != j) {
        symbols[j][i] = !symbols[i][j];
      }
    }
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      cout << symbols[i][j] << " ";
    }
    cout << "\n";
  }
  while (m--) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    ll count = 0;
    for (ll i = 0; i < n; i++) {
      if (symbols[x][i] && symbols[y][i]) {
        count++;
      } 
    }
    if (count != 0) {
      cout << (2*n*count - count*count) << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
  */
  return 0;
 }
