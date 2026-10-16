#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    int result = 0;
    int weight = 1;
    
    // 遍历前 11 个字符计算校验和，自动跳过 '-'
    for (int i = 0; i < 11; ++i) {
        if (s[i] != '-') {
            result += (s[i] - '0') * weight;
            weight++;
        }
    }
    result %= 11;

    // 将计算结果转换为期望的字符
    char expected = (result == 10) ? 'X' : (result + '0');

    // 比较并输出
    if (s[12] == expected) {
        cout << "Right\n";
    } else {
        s[12] = expected; // 直接覆盖最后一位错误字符
        cout << s << '\n'; // 整体输出，省去 for 循环打印
    }

    return 0;
}