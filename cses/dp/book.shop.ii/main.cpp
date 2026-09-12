/*
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    if (!(cin >> n) || !(cin >> x)) return;

    vector<int> prices(n), pages(n), copies(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];
    for (int i = 0; i < n; i++) cin >> copies[i];


    vector<int> precio_paquete, paginas_paquete;

    for (int i = 0; i < n; i++) {
        int k = copies[i];
        int count = 1;

        while (k > 0) {
            int paquete = min(k, count);

            precio_paquete.push_back(paquete * prices[i]);
            paginas_paquete.push_back(paquete * pages[i]);

            k -= paquete;
            count *= 2;
        }
    }

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < precio_paquete.size(); i++) {
        int coste = precio_paquete[i];
        int paginas = paginas_paquete[i];

        // Si hago recorrido inverso cada paquete se agarra solo una vez
        for (int j = x; j >= coste; j--) {
            dp[j] = max(dp[j], dp[j - coste] + paginas);
        }
    }

    cout << dp[x] << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

struct Book {
  int price, pages;
};

int solve(int i, int j, vector<vector<int>> &dp, vector<Book> &books) {
  int n = books.size();

  if (i == n) return 0;

  if (dp[i][j] != -1) return dp[i][j];
  dp[i][j] = 0;

  // no lo cojo
  dp[i][j] = max(dp[i][j], solve(i + 1, j, dp, books));
  
  // lo cojo
  if (j >= books[i].price) {
    dp[i][j] = max(dp[i][j], books[i].pages + solve(i + 1, j - books[i].price, dp, books));
  }

  return dp[i][j];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;

  vector<int> h(n), s(n), k(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }

  vector<Book> books;
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    int left = k[i];

    while (left > 0) {
      int curr = min(cnt, left);
      books.push_back({curr * h[i], curr * s[i]});

      left -= curr;
      cnt *= 2;
    }
  }

  n = books.size();
  vector<vector<int>> dp(2, vector<int>(x + 1));

  for (int i = 0; i < n; i++) {

    for (int j = x; j >= 0; j--) {
      // no lo cojo
      dp[1][j] = max(dp[1][j], dp[0][j]);

      if (j >= books[i].price) {
        // lo cojo
        dp[1][j] = max(dp[1][j], books[i].pages + dp[0][j - books[i].price]);
      }
    }

    for (int j = 0; j <= x; j++) {
      dp[0][j] = dp[1][j];
      dp[1][j] = 0;
    }
  }

  cout << dp[0][x] << endl;

  return 0;
}