#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cnt = 0;
    int num = 0;
    vector<int> maB(n + 1);
    for(char c : s) {
        if(c == 'A') num++;
        else {
            maB[cnt++] = num;
            num = 0;
        }
    }
    bool spc = false;
    if (cnt == 0) {
        spc = true;
    }
    maB[cnt] += num;
    while(q--) {
        int a;
        cin >> a;
        int step = 0;
        int ord = 0;
        if(spc) {
            cout << a << '\n';
            continue;
        }
        while(a) {
            if(a <= maB[ord]) {
                step += a;
                break;
            }
            if(ord == cnt) {
                step += maB[ord];
                a -= maB[ord];
                ord = 0;
            }
            else {
                step += maB[ord] + 1;
                a -= maB[ord];
                a /= 2;
                ord++;
            }
        }
        cout << step << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}