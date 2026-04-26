// https://www.acmicpc.net/contest/problem/1675/3
#include <bits/stdc++.h>
using namespace std;

struct Tomato {
    int t, a, b;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long d;
    cin >> n >> d;

    vector<Tomato> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].t >> v[i].a >> v[i].b;
    }

    sort(v.begin(), v.end(), [](const Tomato& i, const Tomato& j) {
        return i.t < j.t;
    });

    vector<int> a_prefix_max(n);
    a_prefix_max[0] = v[0].a;
    for (int i = 1; i < n; i++) {
        a_prefix_max[i] = max(a_prefix_max[i - 1], v[i].a);
    }

    long long ans = 0;
    for (int j = 0; j < n; j++) {
        long long remaining_time = d - v[j].t;
        if (remaining_time < 0) continue;

        int left = 0, right = n - 1, idx = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (v[mid].t <= remaining_time) {
                idx = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (idx != -1) {
            ans = max(ans, (long long)a_prefix_max[idx] + v[j].b);
        }
    }

    cout << ans << "\n";

    return 0;
}