#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    // 值域为 0 ~ 10000，开到 10005 防止检查 x + 1 时越界
    bitset<10005> vis; 
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0 && vis[x - 1]) ans++; // 检查 x - 1 是否已出现
        if (vis[x + 1]) ans++;          // 检查 x + 1 是否已出现
        vis[x] = true;                  // 标记当前数字已出现
    }

    cout << ans << '\n';
    return 0;
}