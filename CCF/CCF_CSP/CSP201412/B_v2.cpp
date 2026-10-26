#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> num(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num[i][j];
        }
    }

    // 枚举副对角线坐标和 s = i + j，范围从 2 到 2*n
    for (int s = 2; s <= 2 * n; s++) {
        int low = max(1, s - n);
        int high = min(n, s - 1);

        if (s % 2 == 0) {
            // s 为偶数：向右上扫描，行号 i 从 high 递减到 low
            for (int i = high; i >= low; i--) {
                cout << num[i][s - i] << (s == 2 * n && i == low ? '\n' : ' ');
            }
        } else {
            // s 为奇数：向左下扫描，行号 i 从 low 递增到 high
            for (int i = low; i <= high; i++) {
                cout << num[i][s - i] << ' ';
            }
        }
    }

    return 0;
}