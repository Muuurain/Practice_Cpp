#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string cal(int n, string s, int m) {
    int cnt = 0;
    int ret = 0;
    for(int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];
        if(c >= 'A' && c <= 'Z') {
            ret += (c - 'A' + 10) * pow(n, cnt);
        }
        else {
            ret += (c - '0') * pow(n, cnt);
        }
        cnt++;
    }
    int temp = ret % m;
    string ans = "";
    do {
        if(temp > 9) {
            ans = (char)(temp - 10 + 'A') + ans;
        }
        else {
            ans = (char)(temp + '0') + ans;
        }
        ret /= m;
        temp = ret % m;
    }while(ret);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    string s;
    cin >> n >> s >> m;
    string ans = cal(n, s, m);
    cout << ans << '\n';

    return 0;
}