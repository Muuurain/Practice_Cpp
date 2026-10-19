#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    
    // 0: 非法选项, 1: 无参选项, 2: 带参选项
    int type[128] = {0};
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == ':') continue;
        if (i + 1 < s.size() && s[i + 1] == ':') {
            type[(int)s[i]] = 2;
        } else {
            type[(int)s[i]] = 1;
        }
    }

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string cmd, line;
        cin >> cmd;          // 读取并忽略工具名
        getline(cin, line);  // 读取该行剩余部分

        stringstream ss(line);
        map<char, string> ans;
        string opt;

        while (ss >> opt) {
            // 卫语句：凡是不符合 "-x" 格式的直接终止分析
            if (opt.size() != 2 || opt[0] != '-') break;
            
            char c = opt[1];
            if (type[(int)c] == 1) {
                ans[c] = ""; // 无参选项置为空串
            } else if (type[(int)c] == 2) {
                string arg;
                if (!(ss >> arg)) break; // 若后面没有参数则非法，直接终止
                ans[c] = arg;
            } else {
                break; // 未定义的选项，终止分析
            }
        }

        cout << "Case " << i << ":";
        for (auto &[key, val] : ans) {
            cout << " -" << key;
            if (!val.empty()) cout << " " << val;
        }
        cout << '\n';
    }

    return 0;
}