#include <bits/stdc++.h>

using namespace std;


int main() {
    int num1[5000] = {0};
    int num2[5000] = {0};
    int ret[5000] = {0};
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.length(); i++) {
        num1[i] = a[a.length() - 1 - i] - '0';
    }
    for(int i = 0; i < b.length(); i++) {
        num2[i] = b[b.length() - 1 - i] - '0';
    }
    for(int i = 0; i < a.length(); i++) {
        for(int j = 0; j < b.length(); j++) {
            ret[i + j] += num1[i] * num2[j];
        }
    }
    int upd = 0;
    for(int i = 0; i < (a.length() + b.length()) + 10; i++) {
        int t = (ret[i] + upd) % 10;
        upd = (ret[i] + upd) / 10;
        ret[i] = t;
    }
    int index;
    for(index = 4999; index > 0; index--) {
        if(ret[index]) break;
    }
    for(int i = index; i >= 0; i--) {
        cout << ret[i];
    }
    cout << endl;

    return 0;
}