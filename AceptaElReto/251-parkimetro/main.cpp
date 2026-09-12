#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> coins(n);
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }

        vector<bool> formable(3001, false); // Vector con los valores formables
        queue<int> precios;
        precios.push(0);

        
        for (int i = 0; i < k; i++) {
            int lenght = precios.size();

            for (int n = 0; n < lenght; n++) {
                int precio = precios.front();
                precios.pop();

                for (int coin : coins) {
                    int nuevo_precio = precio + coin;

                    if (!formable[nuevo_precio]) {
                        precios.push(nuevo_precio);
                        formable[nuevo_precio] = true;
                    }
                }
            }
        }

        int formables = 0;
        for (int i = 0; i < 2001; i++) {
            if (formable[i]) {
                formables += 1;
            }
        }

        cout << formables << '\n';
    }

    return 0;
}