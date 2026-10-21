#include <bits/stdc++.h>
using namespace std;

// 将字符串全部转为小写的辅助函数
string to_lower_str(string s) {
    for (char& c : s) {
        c = tolower(c);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    int op, n;
    cin >> S >> op >> n;

    // 如果大小写不敏感，先将模式串 S 转为小写
    if (op == 0) {
        S = to_lower_str(S);
    }

    while (n--) {
        string os;
        cin >> os;
        // 根据 op 决定是用原串还是转小写后的串进行查找
        string ts = (op == 0) ? to_lower_str(os) : os;

        // string::find 若找到子串会返回其起始下标，找不到则返回 string::npos
        if (ts.find(S) != string::npos) {
            cout << os << '\n';
        }
    }

    return 0;
}