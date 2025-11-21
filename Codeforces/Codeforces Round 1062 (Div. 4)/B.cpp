#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    const int N = 1e3;
    const int m = 1e3 / 2;
    vector<int> lt(N);
    vector<char> oc;
    for(char c : s) {
        oc.push_back(c);
        lt[c - '0' + m]++;
    }
    bool isvalue = true;
    for(char c : t) {
        lt[c - '0' + m]--;
        if(lt[c - '0' + m] < 0) isvalue = false;
    }
    if(isvalue) {
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
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