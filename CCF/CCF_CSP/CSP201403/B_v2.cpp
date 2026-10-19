#include <bits/stdc++.h>
using namespace std;

struct Window {
    int x1, y1, x2, y2, id;
    // 判断点 (x, y) 是否在窗口范围内（含边界）
    bool contains(int x, int y) const {
        return x1 <= x && x <= x2 && y1 <= y && y <= y2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    list<Window> wins;
    for (int i = 1; i <= N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 题目按从最下层到最顶层的顺序输入
        // 每次使用 push_front 插到链表头部，读完后链表就天然是“从顶层到底层”的顺序
        wins.push_front({x1, y1, x2, y2, i});
    }

    while (M--) {
        int x, y;
        cin >> x >> y;

        bool hit = false;
        // 使用迭代器从链表头部（最顶层）向尾部（最底层）遍历
        for (auto it = wins.begin(); it != wins.end(); ++it) {
            if (it->contains(x, y)) {
                cout << it->id << '\n';
                
                // 核心操作：将迭代器 it 指向的节点直接剪切并拼接到 wins.begin() 之前（即链表最前面）
                wins.splice(wins.begin(), wins, it);
                
                hit = true;
                break;
            }
        }

        if (!hit) {
            cout << "IGNORED\n";
        }
    }

    return 0;
}