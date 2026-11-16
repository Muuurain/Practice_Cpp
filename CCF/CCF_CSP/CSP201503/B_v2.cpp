#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cnt(1001, 0);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cnt[t]++;
    }

    // 仅收集出现过的数字，存入 {-频次, 数值}
    vector<pair<int, int>> ans;
    for (int i = 0; i <= 1000; i++) {
        if (cnt[i] > 0) {
            ans.emplace_back(-cnt[i], i);
        }
    }

    // pair 默认按 first 升序（即频次降序）、second 升序（即数值升序）排列
    sort(ans.begin(), ans.end());

    for (const auto& [neg_time, num] : ans) {
        cout << num << ' ' << -neg_time << '\n';
    }

    return 0;
}