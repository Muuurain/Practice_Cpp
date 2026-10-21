#include <bits/stdc++.h>
using namespace std;

int diff[105][105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // O(1) 二维差分标记（下标整体 +1，方便后面直接求前缀和而不越界）
        diff[x1 + 1][y1 + 1]++;
        diff[x2 + 1][y1 + 1]--;
        diff[x1 + 1][y2 + 1]--;
        diff[x2 + 1][y2 + 1]++;
    }

    int ans = 0;
    // 二维前缀和还原每个方格的覆盖次数
    for (int x = 1; x <= 100; x++) {
        for (int y = 1; y <= 100; y++) {
            diff[x][y] += diff[x - 1][y] + diff[x][y - 1] - diff[x - 1][y - 1];
            if (diff[x][y] > 0) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}