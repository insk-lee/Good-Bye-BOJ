// https://www.acmicpc.net/contest/problem/1675/2
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    long long max_a = 0;
    long long max_b = 0;
    long long max_c = 0;
    bool is_possible = true;

    for (int i = 1; i <= n; i++) {
        long long a, b, c, p;
        cin >> a >> b >> c >> p;

        max_a = max(max_a, a);
        max_b = max(max_b, b);
        max_c = max(max_c, c);

        if (max_a + max_b + max_c + i > p) {
            is_possible = false;
        }
    }

    if (is_possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        solve();
    }

    return 0;
}