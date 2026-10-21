#include <bits/stdc++.h>
using namespace std;

int main() {
    // 优化输入输出流，提升运行效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<int> seen; // 用于存储已经读入过的数字
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        // 检查 x - 1 是否在哈希表中
        if (seen.find(x - 1) != seen.end()) {
            ans++;
        }
        // 检查 x + 1 是否在哈希表中
        if (seen.find(x + 1) != seen.end()) {
            ans++;
        }

        // 将当前数字加入哈希表
        seen.insert(x);
    }

    cout << ans << '\n';

    return 0;
}