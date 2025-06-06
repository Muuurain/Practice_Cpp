#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int num1[1000] = {0};
    int num2[1000] = {0};
    int ret[1000] = {0};
    for(int i = 0; i < a.length(); i++) {
        num1[i] = a[a.length() - 1 - i] - '0';
    }
    for(int i = 0; i < b.length(); i++) {
        num2[i] = b[b.length() - 1 - i] - '0';
    }
    int jn = 0;
    for(int i = 0; i < max(a.length(), b.length()) + 1; i++) {
        ret[i] = (num1[i] + num2[i] + jn) % 10;
        jn = (num1[i] + num2[i] + jn) / 10;
    }
    if(ret[max(a.length(), b.length())] != 0) {
        cout << ret[max(a.length(), b.length())];
    }
    for(int i = max(a.length(), b.length()) - 1; i >= 0; i--) {
        cout << ret[i];
    } 
    cout << endl;


    return 0;
}