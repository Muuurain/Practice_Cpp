#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> sst(n - 1);
    for(auto &it : sst) cin >> it;
    int k;
    cin >> k;
    vector<int> b(k), c(k);
    for(auto &it : b) cin >> it;
    for(auto &it : c) cin >> it;
    int s, t;
    cin >> s >> t;
    long long ret = 0;
    for(int i = s - 1; i < t - 1; i++) {
        ret += sst[i];
    }
    for(int i = 0; i < k; i++) {
        if(b[i] > s && b[i] < t) ret += c[i];
    }
    cout << ret << endl;
    

    return 0;
}