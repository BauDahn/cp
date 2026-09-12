#include <bits/stdc++.h>
using namespace std;

const int MAX = 20000;
vector<bool> alcanzable(MAX + 1, false);

void precalculo() {
    queue<int> q;

    q.push(1);
    alcanzable[1] = true;

    while (!q.empty()) {
        int actual = q.front();
        q.pop();

        int op1 = actual * 3;
        if (op1 <= MAX && !alcanzable[op1]) {
            alcanzable[op1] = true;
            q.push(op1);
        }

        int op2 = actual + 5;
        if (op2 <= MAX && !alcanzable[op2]) {
            alcanzable[op2] = true;
            q.push(op2);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precalculo();

    int n;
    while (cin >> n && n) {
        if (alcanzable[n]) {
            cout << "SI" << '\n';
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}