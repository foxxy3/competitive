//It's Mooin' Time III
//https://usaco.org/index.php?page=viewproblem2&cpid=1517

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  unordered_set<char> char_set;
  for (ll i = 0; i < n; i++) {
    char_set.insert(s[i]);
  }

  unordered_map<char, vector<ll>> cache_l;
  //for (char c : char_set) {
  for (char c = 'a'; c <= 'z'; c++) {
    cache_l[c] = vector<ll>(n, -1);
  }
  unordered_map<char, ll> last_pos;
  //for (char c : char_set) {
  for (char c = 'a'; c <= 'z'; c++) {
    last_pos[c] = 0;
  }
  for (ll i = 0; i < n; i++) {
    char c = s[i];
    cache_l[c][i] = i;
    for (ll j = last_pos[c]; j < i; j++) {
      cache_l[c][j] = i;
    }
    last_pos[c] = i + 1;
  }

  unordered_map<char, vector<ll>> cache_k;
  //for (char c : char_set) {
  for (char c = 'a'; c <= 'z'; c++) {
    cache_k[c] = vector<ll>(n, -1);
  }
  //for (char c : char_set) {
  for (char c = 'a'; c <= 'z'; c++) {
    last_pos[c] = n - 1;
  }
  for (ll i = n - 1; i >= 0; i--) {
    char c = s[i];
    cache_k[c][i] = i;
    for (ll j = last_pos[c]; j > i; j--) {
      cache_k[c][j] = i;
    }
    last_pos[c] = i - 1;
  }

  while (q--) {
    ll l, r;
    cin >> l >> r;
    l--;
    r--;
    ll max_area = -1;
    //for (char m : char_set) {
    for (char m = 'a'; m <= 'z'; m++) {
      ll i = cache_l[m][l];
      if (i == -1 || i > r - 2) {
        continue;
      }
      //for (char o : char_set) {
      for (char o = 'a'; o <= 'z'; o++) {
        if (o == m) {
          continue;
        }
        ll k = cache_k[o][r];
        if (k == -1 || k < i + 2) {
          continue;
        }
        ll j = cache_k[o][r - 1];
        if (j == -1 || j <= i) {
          continue;
        }
        j = cache_l[o][i + 1];
        if (j == -1 || j >= k) {
          continue;
        }
        ll j1 = (i + k) / 2, j2 = j1 + 1;
        ll j11 = cache_l[o][j1];
        ll j21 = cache_k[o][j2];
        max_area = max(max_area, (j11 - i) * (k - j11));
        max_area = max(max_area, (j21 - i) * (k - j21));
        /*
        while (j1 > i || j2 < k) {
          if (j1 > i && s[j1] == o) {
            max_area = max(max_area, (j1 - i) * (k - j1));
            break;
          }
          if (j2 < k && s[j2] == o) {
            max_area = max(max_area, (j2 - i) * (k - j2));
            break;
          }
          j1--;
          j2++;
        }*/
      }
    }
    cout << max_area << "\n";
  }

  return 0;
}
