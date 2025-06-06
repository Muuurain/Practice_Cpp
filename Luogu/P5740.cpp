#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> score;

int main() {
    int N;
    cin >> N;
    int maxn = -1;
    string ans = "";
    int ra, rb, rc;
    for(int i = 0; i < N; i++) {
        int a, b, c;
        string name;
        cin >> name >> a >> b >> c;
        score[name] = a + b + c;
        if(score[name] > maxn) {
            maxn = score[name];
            ans = name;
            ra = a;
            rb = b;
            rc = c;
        }
    }
    cout << ans << " " << ra << " " << rb << " " << rc << endl;

    return 0;
}