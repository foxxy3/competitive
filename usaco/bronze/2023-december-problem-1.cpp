//Candy Cane Feast 
#include <iostream>
#include <queue>
#include <map>
using namespace std;

long long n, m;
long long cow_h[200000];
long long candycane_h[200000];

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> cow_h[i];
  }
  for  (int i = 0; i < m; i++) {
    cin >> candycane_h[i];
  }

  for (int i = 0; i < m; i++) {
    long long candycane = candycane_h[i];
    long long amount = candycane_h[i];
    
    for (int j = 0; j < n; j++) {
      if (amount == 0) {
        continue;
      }
      if (candycane - amount < cow_h[j]) {
        long long taken;
        if (candycane > cow_h[j]) {
          taken = amount - (candycane - cow_h[j]);

        } else {
          taken = amount;
        }
        cow_h[j] += taken;
          amount -= taken;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << cow_h[i] << endl;
  }
}
