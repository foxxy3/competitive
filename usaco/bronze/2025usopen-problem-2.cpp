//More Cow Photos
//https://usaco.org/index.php?page=viewproblem2&cpid=1516

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> freq(n+1, 0);
    ll max_n = 0;
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      max_n = max(max_n, x);
      freq[x]++;
    }

    ll count = 0;
    for (ll i = 1; i < max_n; i++) {
      if (freq[i] >= 2) {
        count++;
      }
    }
    cout << count*2 + 1 << "\n";
  }
  
  return 0;
 }
