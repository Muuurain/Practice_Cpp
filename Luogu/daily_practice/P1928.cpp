#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string cal() {
    string temp= "";
    int k = 0;
    string s = "";
    char c;
    while(cin >> c) {
        if(c == '[') {
            cin >> k;
            temp = cal();
            while(k--) {
                s += temp;
            }
        } else if(c == ']') {
            return s;
        } else {
            s += c;
        }
    }
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string ans = cal();
    cout << ans << endl;

    return 0;
}