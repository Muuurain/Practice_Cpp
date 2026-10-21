#include <bits/stdc++.h>
using namespace std;

// 将字符串转为小写的辅助函数
string to_lower_str(string s) {
    for (char& c : s) {
        c = tolower(c);
    }
    return s;
}

// 1. 预处理模式串 S，构建 nxt 数组，时间复杂度 O(M)
vector<int> build_nxt(const string& S) {
    int m = S.size();
    vector<int> nxt(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        // 若失配，利用之前算好的 nxt 数组不断回退 j
        while (j > 0 && S[i] != S[j]) {
            j = nxt[j - 1];
        }
        // 若字符相等，最长公共前后缀长度 +1
        if (S[i] == S[j]) {
            j++;
        }
        nxt[i] = j;
    }
    return nxt;
}

// 2. KMP 匹配函数：判断主串 ts 中是否包含模式串 S，时间复杂度 O(L)
bool kmp_search(const string& ts, const string& S, const vector<int>& nxt) {
    int n = ts.size(), m = S.size();
    for (int i = 0, j = 0; i < n; i++) {
        // 失配时，主串指针 i 不动，模式串指针 j 按 nxt 数组回退
        while (j > 0 && ts[i] != S[j]) {
            j = nxt[j - 1];
        }
        // 当前字符匹配成功，模式串指针后移
        if (ts[i] == S[j]) {
            j++;
        }
        // 完全匹配了模式串 S 的所有字符
        if (j == m) {
            return true; 
        }
    }
    return false;
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

    // 只需在循环外对模式串 S 预处理一次 nxt 数组
    vector<int> nxt = build_nxt(S);

    while (n--) {
        string os;
        cin >> os;
        string ts = (op == 0) ? to_lower_str(os) : os;

        // 使用 KMP 进行单行匹配
        if (kmp_search(ts, S, nxt)) {
            cout << os << '\n';
        }
    }

    return 0;
}