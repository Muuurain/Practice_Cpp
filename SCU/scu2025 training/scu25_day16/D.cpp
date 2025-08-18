#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, l;
    cin >> n >> l;
    int ans = 0;
    while(n--) {
        int len;
        cin >> len;
        len = min(len, l - len);
        ans = max(ans, len);
    }

    cout << ans << endl;
    
    return 0;
}