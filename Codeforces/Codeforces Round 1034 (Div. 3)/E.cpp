#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 10);
    vector<int> diff(n + 10);
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    
    for(int i = 0; i <= n; i++) {
        diff[n - i + 1]--;
        if(!freq[i]) break;
        diff[freq[i]]++;
    }
    
    int ans = 1;
    for(int i = 0; i <= n; i++) {
        ans += diff[i];
        cout << ans << " ";   
    }
    cout << endl;
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