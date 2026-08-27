//Farmer John Actually Farms
//https://usaco.org/index.php?page=viewproblem2&cpid=1349
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int t;

// number of days for tree1 to become taller than tree2
int calc_days(ll h1, ll a1, ll h2, ll a2) {
  if (h1 > h2) {
    return 0;
  }
  if (h1 == h2) {
    if (a1 > a2) { 
      return 1;
    }
    return -1;
  }
  //if height 1 is smaller than height 2: 
  if (a1 <= a2) {
    return -1;
  }
  return (h2 - h1) / (a1 - a2) + 1;
}

int main() { 
  cin >> t;
  for (ll i = 0; i < t; i++) {
    ll n;
    cin >> n;
    ll initial[n];
    ll growth[n];
    ll taller[n];
    for (ll j = 0; j < n; j++) {
      cin >> initial[j];
    }
    for (ll j = 0; j < n; j++) {
      cin >> growth[j];
    }
    for (ll j = 0; j < n; j++) {
      ll t;
      cin >> t;
      taller[t] = j;
    }

    if (n == 1) {
      cout << "0" << endl;
      continue;
    }

    bool possible = true;
    ll max_days = -1;
    for (ll j = 0; j < n-1; j++) {
      ll days = calc_days(initial[taller[j]], growth[taller[j]], initial[taller[j+1]], growth[taller[j+1]]);
      if (days == -1) {
        possible = false;
        break;
      }
      max_days = max(days, max_days);
    }
    if (possible) {
      for (ll j = 0; j < n-1; j++) {
        ll height1 = initial[taller[j]] + growth[taller[j]] * max_days;
        ll height2 = initial[taller[j+1]] + growth[taller[j+1]] * max_days;
        if (height1 <= height2) {
          possible = false;
          break;
        }
      }
    }
    if (possible) {
      cout << max_days << endl;
    } else {
      cout << "-1" << endl;
    }
  }
}
