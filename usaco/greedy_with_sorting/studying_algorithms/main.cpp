#include <bits/stdc++.h>
using namespace std;

void solve(){
    int total, n;
    cin >> n >> total;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int contador = 0;
    for (int i = 0 ; i < n ; i++) {
        if (total - a[i] >= 0) {
            total -= a[i];
            contador++;
        }
    }

    cout << contador << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}