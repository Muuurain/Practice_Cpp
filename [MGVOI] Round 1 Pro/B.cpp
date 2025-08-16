#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, Q;
    cin >> n >> Q;
    vector<int> num(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    while(Q--) {
        int x, y;
        cin >> x >> y;
        vector<int> prefix(n + 1);
        int aim = num[x];
        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (aim > num[i]);
        }
        
        vector<int> um(n * 2 + 10);
        for(int L = 1; L <= x; L++) {
            int key = L - prefix[L - 1] - y + n;
            um[key]++;
        }
        long long ans = 0;
        for(int R = y; R <= n; R++) {
            ans += um[-prefix[R] + n];
        }

        cout << ans << '\n';
    }

    return 0;
}