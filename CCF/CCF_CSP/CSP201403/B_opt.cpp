#include <bits/stdc++.h>
using namespace std;

// 1. 使用结构体聚合窗口坐标与编号，语义清晰且内存连续
struct Window {
    int x1, y1, x2, y2, id;
    // 判断点击坐标 (x, y) 是否在当前窗口内
    bool contains(int x, int y) const {
        return x1 <= x && x <= x2 && y1 <= y && y <= y2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 题目按照从最下层到最顶层的顺序输入，我们直接倒着存，或者从后往前遍历
    // 这里直接将初始窗口存入 vector，下标 0 放最顶层，下标 N-1 放最底层
    vector<Window> wins(N);
    for (int i = 1; i <= N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        wins[N - i] = {x1, y1, x2, y2, i}; // 越晚输入的越靠前（顶层）
    }

    while (M--) {
        int x, y;
        cin >> x >> y;
        
        int hit_idx = -1;
        // 从最顶层 (0) 到最底层 (N - 1) 依次检查
        for (int i = 0; i < N; i++) {
            if (wins[i].contains(x, y)) {
                hit_idx = i;
                break;
            }
        }

        if (hit_idx == -1) {
            cout << "IGNORED\n";
        } else {
            cout << wins[hit_idx].id << '\n';
            // 2. 原地将命中的窗口 wins[hit_idx] 移到最顶层 wins[0]
            // 写法 A（手动倒序平移）：
            Window top_win = wins[hit_idx];
            for (int j = hit_idx; j >= 1; j--) {
                wins[j] = wins[j - 1];
            }
            wins[0] = top_win;
            
            // 写法 B（或者用 STL 一行代替上面 5 行）：
            // rotate(wins.begin(), wins.begin() + hit_idx, wins.begin() + hit_idx + 1);
        }
    }

    return 0;
}