#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N], dp1[N], dp2[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    for(int i = n; i >= 1; i--) {
        for(int j = n + 1; j > i; j--) {
            if(a[i] > a[j]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }

    cout << (n - ans) << endl;

    return 0;
}


