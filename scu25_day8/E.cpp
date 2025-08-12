#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int ans;
    cin >> ans;
    n--;
    while(n--) {
        int t;
        cin >> t;
        ans ^= t;
    }
    cout << ans << endl;

    return 0;
}