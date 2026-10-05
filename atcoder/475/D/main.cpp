#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// This appears to be a backtracking problem

bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

string S;
vector<int> unique_chars;
vector<int> char_to_digit(26, -1);
vector<bool> used_digit(10, false);
string result = "-1";

bool backtrack(int idx) {

    // Base case of recursion
    if (idx == (int)unique_chars.size()) {
        ll num = 0;
        for (char c : S) {
            num = num * 10 + char_to_digit[c - 'a'];
        }

        if (is_prime(num)) {
            result = to_string(num);
            return true;
        }

        return false;
    }

    char current_char = unique_chars[idx];

    for (int d = 0; d <= 9; d++) {
        // First char cannot be 0
        if (d == 0 && current_char == S[0]) continue;

        // Check if this digit has been used by another char
        if (!(used_digit[d])) {
            // Now we choose
            used_digit[d] = true;
            char_to_digit[current_char - 'a'] = d;

            if (backtrack(idx + 1)) {
                return true;
            }

            // Step back
            used_digit[d] = false;
            char_to_digit[current_char - 'a'] = -1;
        }
    }

    return false;
}

void solve() {
    cin >> S;

    vector<bool> seen(26, false);
    for (char c : S) {
        if (!(seen[c - 'a'])) {
            seen[c - 'a'] = true;
            unique_chars.push_back(c);
        }
    }

    backtrack(0);

    cout << result << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}