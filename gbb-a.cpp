// https://www.acmicpc.net/contest/problem/1675/1
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 2 <= n <= 100
    int n; cin >> n;

    int rows = 2 * n;
    int cols = 4 * n + 2;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // left diag
            if (j == 2 * n - 1 - i) {
                cout << "*";
            }
            // right BOJ park
            else {
                int l_Pos, r_Pos;

                if (i < n) {
                    l_Pos = 3 * n - i;
                    r_Pos = 3 * n + 2 + i;
                } else {
                    l_Pos = 2 * n + 1 + (i - n);
                    r_Pos = 4 * n + 1 - (i - n);
                }

                if (j == l_Pos || j == r_Pos) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }

    return 0;
}