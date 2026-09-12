#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  cin.ignore();

  int total = 0;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 'o') total++;
    }
  }

  vector<int> freqRow(n);
  for (int i = 0; i < n; i++) {
    int freq = 0;

    for (int j = 0; j < n; j++) {
      if (a[i][j] == 'o') freq++;
    }

    freqRow[i] += freq;
  }

  vector<int> freqCol(n);
  for (int j = 0; j < n; j++) {
    int freq = 0;

    for (int i = 0; i < n; i++) {
      if (a[i][j] == 'o') freq++;
    }

    freqCol[j] += freq;
  }

  vector<pair<int, int>> sol;
  while (total > 0) {
    int maxCoins = -1;
    int type = -1; // 1 for row 2 for column
    int x = -1;
    for (int i = 0; i < n; i++) {
      if (freqRow[i] > maxCoins) {
        maxCoins = freqRow[i];
        type = 1;
        x = i;
      }
    }
    for (int j = 0; j < n; j++) {
      if (freqCol[j] > maxCoins) {
        maxCoins = freqCol[j];
        type = 2;
        x = j;
      }
    }

    if (type == 1) {
      total -= freqRow[x];

      for (int j = 0; j < n; j++) {
        if (a[x][j] == 'o') freqCol[j]--;
      }
      freqRow[x] = 0;
    } else if (type == 2) {
      total -= freqCol[x];

      for (int i = 0; i < n; i++) {
        if (a[i][x] == 'o') freqRow[i]--;
      }
      freqCol[x] = 0;
    }

    sol.push_back({type, x + 1});
  }

  cout << sol.size() << "\n";
  for (const pair<int, int> &x : sol) {
    cout << x.first << " " << x.second << "\n";
  }


  return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync(0);
    cin.tie(0);

    int r, c;
    if

    
    return 0;
}

*/