#include<bits/stdc++.h>
using namespace std;

int kaprekar(string n, int pasos) {
    if (n == "6174") {
        return pasos;
    }
    if (n.size() < 4) {
        n.insert(0, 4 - n.length(), '0');
    }
    if (n == "0000") {
        return 8;
    }
    string menor = n, mayor = n;

    sort(menor.begin(), menor.end());
    sort(mayor.begin(), mayor.end(), greater<char>());

    int num_mayor, num_menor;
    num_mayor = stoi(mayor);
    num_menor = stoi(menor);
    int nuevo_num;
    nuevo_num = num_mayor - num_menor;
    string num = to_string(nuevo_num);
    return kaprekar(num, pasos + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;

        int res;
        res = kaprekar(n, 0);

        cout << res << "\n";

    }


    return 0;
}